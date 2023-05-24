#include "simple_shell.h"

/**
 * main - Main Entry to Simple Shell project code.
 * @argc: Total number Number of arguments.
 * @argv: Pointer to array of arguments.
 * Return: Always 0 if success else 1.
 */

int main(int argc, char *argv[])
{
	char *lines;
	int PresentStatus;
	char **tokenised;

	(void)argc;

	signal(SIGINT, controlc);
	PresentStatus = 0;
	while (PresentStatus == 0)
	{
		prompttin();

		lines = read_lines();
		if (_stringcmp(lines, "\n") == 0)
		{
			tokenised = NULL;
			free(lines);
			continue;
		}
		tokenised = _strtotokenised(lines);
		if (tokenised[0] == NULL)
		{
			free(tokenised);
			free(lines);
			continue;
		}

		if (_stringcmp(tokenised[0], "exit") == 0)
		{
			_exitSimpleShellcode(tokenised, lines);
		}
		else
		{
			PresentStatus =  _executting(tokenised, argv[0]);
		}
		free(lines);
		free(tokenised);
	}
	return (PresentStatus);
}
