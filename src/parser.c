#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "parser.h"

#define MAX_ARGS 100

// Helper to trim leading and trailing whitespace
char *trim_whitespace(char *str) {
    while (isspace((unsigned char)*str)) str++;
    if (*str == 0) return str;

    char *end = str + strlen(str) - 1;
    while (end > str && isspace((unsigned char)*end)) end--;
    *(end + 1) = '\0';

    return str;
}

// Parses command into args + infile + outfile, supporting quotes
void parse_command(char *cmd, char **args, char **infile, char **outfile) {
    int argc = 0;
    *infile = NULL;
    *outfile = NULL;

    char *token = NULL;
    char *p = cmd;

    while (*p) {
        while (isspace((unsigned char)*p)) p++;
        if (*p == '\0') break;

        if (*p == '<' || *p == '>') {
            char redir = *p++;
            while (isspace((unsigned char)*p)) p++;

            if (*p == '"' || *p == '\'') {
                char quote = *p++;
                token = p;
                while (*p && *p != quote) p++;
            } else {
                token = p;
                while (*p && !isspace((unsigned char)*p)) p++;
            }

            char saved = *p;
            *p = '\0';

            if (redir == '<') *infile = strdup(trim_whitespace(token));
            else *outfile = strdup(trim_whitespace(token));

            *p = saved;
            if (*p) p++;
        } else {
            if (*p == '"' || *p == '\'') {
                char quote = *p++;
                token = p;
                while (*p && *p != quote) p++;
            } else {
                token = p;
                while (*p && !isspace((unsigned char)*p) && *p != '<' && *p != '>') p++;
            }

            char saved = *p;
            *p = '\0';

            args[argc++] = strdup(trim_whitespace(token));
            *p = saved;
            if (*p) p++;
        }
    }

    args[argc] = NULL;
}

// Frees args
void free_args(char **args) {
    for (int i = 0; args[i]; ++i) free(args[i]);
}
