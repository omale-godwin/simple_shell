#include "simple_shell.h"

/**
 * prompttin - Print prompttin.
 * Return: Void.
 */
void prompttin(void)
{
	if (isatty(STDIN_FILENO))
	{
		write(STDOUT_FILENO, "#cisfun$ ", 9);
	}
}