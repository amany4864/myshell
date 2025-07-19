#ifndef EXECUTOR_H
#define EXECUTOR_H

// Executes an entire command line that may contain multiple piped commands.
// This function uses the parser to split commands, handle redirection, and execute them via fork/exec.
void execute_pipeline(char *cmd_line);

#endif // EXECUTOR_H
