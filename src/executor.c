#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <stdio.h>
#include <stdlib.h>
#include "executor.h"

void execute_command(char **args) {
    pid_t pid = fork();

    if (pid == 0) {
        // Child
        execvp(args[0], args);
        perror("exec");
        exit(1);
    } else if (pid > 0) {
        // Parent
        wait(NULL);
    } else {
        perror("fork");
    }
}
