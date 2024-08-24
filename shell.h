#ifndef SHELL_H
#define SHELL_H
#define MAX_ARGS 100 /* define a maximum number of arguments */
#include <sys/wait.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/*Function prototypes*/
void execute_command(char *command);

#endif /* SHELL_H */

