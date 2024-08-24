#ifndef SHELL_H
#define SHELL_H

/**
 * prompt - Displays the shell prompt.
 *
 * Description: This function is responsible for displaying the shell prompt
 * to the user, allowing them to enter commands.
 */
void prompt(void);

/**
 * execute_command - Executes a command entered by the user.
 * @args: Array of arguments (command and its flags/parameters).
 *
 * Return: Status of the command execution.
 *
 * Description: This function takes an array of arguments, where the first
 * element is the command and the subsequent elements are the command's flags
 * or parameters. It then executes the command using the appropriate system
 * call.
 */
int execute_command(char **args);

#endif /* SHELL_H */

