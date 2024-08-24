#include "shell.h"
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/wait.h>

#define BUFFER_SIZE 1024

void prompt(void);
char *read_input(void);
void execute_command(char *buffer);
void handle_exit(char *buffer);

/**
 * main - Entry point for the simple shell
 *
 * Return: 0 on success, or an error code on failure
 */
int main(void)
{
char *buffer;

while (1)
{
prompt();
buffer = read_input();

if (buffer == NULL)
{
printf("\n");
break;
}

/* Handle "exit" command */
if (strcmp(buffer, "exit") == 0)
{
handle_exit(buffer);
break;
}

execute_command(buffer);
free(buffer);
}

return (0);
}

/**
 * prompt - Displays the shell prompt
 */
void prompt(void)
{
printf("($) ");
}

/**
 * read_input - Reads input from the user
 *
 * Return: The input string from the user
 */
char *read_input(void)
{
char *buffer = NULL;
size_t bufsize = 0;

if (getline(&buffer, &bufsize, stdin) == -1)
{
free(buffer);
return (NULL);
}

/* Remove the newline character */
buffer[strcspn(buffer, "\n")] = 0;

return (buffer);
}

/**
 * execute_command - Executes the command entered by the user
 * @buffer: The command to execute
 */
void execute_command(char *buffer)
{
char *args[2];
pid_t pid;
int status;

args[0] = buffer;
args[1] = NULL;

pid = fork();
if (pid == 0)
{
if (execve(args[0], args, NULL) == -1)
{
perror("./hsh");
}
exit(EXIT_FAILURE);
}
else if (pid < 0)
{
perror("Error:");
}
else
{
wait(&status);
}
}

/**
 * handle_exit - Frees memory and exits the shell
 * @buffer: The command buffer to free
 */
void handle_exit(char *buffer)
{
free(buffer);
}

