#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "parser.h"

#define MAX_TOKENS 64

char **parse_input(char *line) {
    char **args = malloc(MAX_TOKENS * sizeof(char *));
    if (!args) return NULL;

    int i = 0;
    char *token = strtok(line, " \t\n");
    while (token != NULL && i < MAX_TOKENS - 1) {
        args[i++] = strdup(token);
        token = strtok(NULL, " \t\n");
    }
    args[i] = NULL;
    return args;
}

void free_args(char **args) {
    for (int i = 0; args[i] != NULL; ++i)
        free(args[i]);
    free(args);
}
