#include "shell.h"

/**
 * main - Entry point for the shell
 *
 * Return: Always 0 (Success)
 */
int main(void)
{
char *line = NULL;
size_t len = 0;
ssize_t nread;

while (1)
{
printf("($) ");
nread = getline(&line, &len, stdin);
if (nread == -1)
{
free(line);
exit(0);
}
if (strcmp(line, "exit\n") == 0)
{
free(line);
break;
}
/* Additional commands will be handled here in the future */
}

return (0);
}

