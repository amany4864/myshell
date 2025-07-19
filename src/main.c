#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "parser.h"
#include "executor.h"

#define MAX_LINE 1024

int main() {
    char input[MAX_LINE];

    while (1) {
        printf("mysh> ");
        fflush(stdout);

        if (!fgets(input, MAX_LINE, stdin)) {
            break; // Ctrl+D
        }

        if (strcmp(input, "\n") == 0) continue;

        // Parse and execute
        char **args = parse_input(input);
        if (args == NULL) continue;

        if (strcmp(args[0], "exit") == 0) {
            free_args(args);
            break;
        }

        execute_command(args);
        free_args(args);
    }

    return 0;
}
