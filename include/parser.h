#ifndef PARSER_H
#define PARSER_H

void parse_command(char *cmd, char **args, char **infile, char **outfile);
void free_args(char **args);

#endif
