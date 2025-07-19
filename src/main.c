#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "parser.h"
#include "executor.h"

#define MAX_LINE 1024

int main() {
    char line[MAX_LINE];

    while (1) {
        printf("mysh> ");
        fflush(stdout);

        if (!fgets(line, sizeof(line), stdin)) break;

        line[strcspn(line, "\n")] = '\0';

        if (strcmp(line, "exit") == 0) break;

        execute_pipeline(line);
    }

    return 0;
}
