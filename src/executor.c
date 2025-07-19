#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/wait.h>
#include "parser.h"

#define MAX_CMDS 10
#define MAX_ARGS 100

void execute_pipeline(char *cmd_line) {
    char *commands[MAX_CMDS];
    int num_cmds = 0;

    // Split by '|'
    char *token = strtok(cmd_line, "|");
    while (token != NULL && num_cmds < MAX_CMDS) {
        commands[num_cmds++] = strdup(token);
        token = strtok(NULL, "|");
    }

    int prev_fd = -1;
    int pipefd[2];

    for (int i = 0; i < num_cmds; i++) {
        char *args[MAX_ARGS];
        char *infile = NULL, *outfile = NULL;

        char *cmd = commands[i];
        parse_command(cmd, args, &infile, &outfile);

        // Setup pipe if needed
        if (i < num_cmds - 1 && pipe(pipefd) == -1) {
            perror("pipe");
            exit(EXIT_FAILURE);
        }
        // Handle built-in 'cd' before forking
if (strcmp(args[0], "cd") == 0) {
    if (args[1] == NULL) {
        fprintf(stderr, "cd: missing argument\n");
    } else {
        if (chdir(args[1]) != 0) {
            perror("cd");
        }
    }

    // Cleanup and skip fork
    free_args(args);
    if (infile) free(infile);
    if (outfile) free(outfile);
    continue; // go to next command in pipeline
}

        pid_t pid = fork();
        if (pid == 0) {
            // CHILD PROCESS

            if (prev_fd != -1) {
                dup2(prev_fd, STDIN_FILENO);
                close(prev_fd);
            }

            if (i < num_cmds - 1) {
                close(pipefd[0]);
                dup2(pipefd[1], STDOUT_FILENO);
                close(pipefd[1]);
            }

            if (infile) {
                int fd_in = open(infile, O_RDONLY);
                if (fd_in < 0) {
                    perror("open infile");
                    exit(EXIT_FAILURE);
                }
                dup2(fd_in, STDIN_FILENO);
                close(fd_in);
            }

            if (outfile) {
                int fd_out = open(outfile, O_WRONLY | O_CREAT | O_TRUNC, 0644);
                if (fd_out < 0) {
                    perror("open outfile");
                    exit(EXIT_FAILURE);
                }
                dup2(fd_out, STDOUT_FILENO);
                close(fd_out);
            }

            execvp(args[0], args);
            perror("execvp failed");
            exit(EXIT_FAILURE);

        } else if (pid > 0) {
            // PARENT PROCESS
            if (prev_fd != -1) close(prev_fd);
            if (i < num_cmds - 1) {
                close(pipefd[1]);
                prev_fd = pipefd[0];
            }
            waitpid(pid, NULL, 0);
        } else {
            perror("fork failed");
            exit(EXIT_FAILURE);
        }

        // Cleanup per-command
        free_args(args);
        if (infile) free(infile);
        if (outfile) free(outfile);
    }

    for (int i = 0; i < num_cmds; i++) {
        free(commands[i]);
    }
}