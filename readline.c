#include "simple_shell.h"

/**
 * read_lines - Gets a typed line from the command line as a string.
 * Return: Pointer to the line(string).
 */

char *read_lines(void)
{
	char *lines =  NULL;
	size_t len = 0;
	/*int chars = 0;*/
	ssize_t chars = 0;

	/* inbuilt getlines */
	chars = getline(&lines, &len, stdin);

	/* custom get lines */
	/*chars = get_lines(&lines);*/
	if (chars == EOF)
	{
		free(lines);
		exit(0);
	}
	if (lines == NULL)
	{
		write(STDOUT_FILENO, "\n", 1);
		free(lines);
		exit(-1);
	}

	return (lines);
}