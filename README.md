# Simple Shell

## Description
This project is a simple UNIX command interpreter (shell) that replicates the basic functionalities of the standard shell. It is implemented in C and provides a command-line interface for users to execute commands.

## Features
- Command execution
- Handling of built-in commands like `exit`
- Interactive and non-interactive modes
- Basic environment variable management

## Usage
### Compilation
To compile the shell, run the following command:
```bash
gcc -Wall -Werror -Wextra -pedantic -std=gnu89 *.c -o hsh
