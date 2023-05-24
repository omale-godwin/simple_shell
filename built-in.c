#include "simple_shell.h"

/**
  *_printtingenv - Prints variables in current
  * working environment.
  * Return: void.
  */
void _printtingenv(void)
{
	int i = 0;

	while (environ[i])
	{
		_putttind(environ[i]);
		i++;
	}
}

/**
 * _isBuiltIncmd - Checks if token is a built in.
 * @str: Pointer to string to check.
 * Return: 0 if true else 1.
 */
int _isBuiltIncmd(char *str)
{
	/* check if strings are equal */
	if ((_stringcmp(str, "env")) == 0)
	{
		return (0);
	}
	if ((_stringcmp(str, "exit")) == 0)
		return (0);
	if ((_stringcmp(str, "setenv")) == 0)
		return (0);
	if ((_stringcmp(str, "unsetenv")) == 0)
		return (0);
	return (1);

}

/**
 * _executeBuiltIncmd - Executes a builtin Function.
 * @tokenised: Double pointer to tokenised.
 * Return: 0 if success.
 */
int _executeBuiltIncmd(char **tokenised)
{
	/* check if first token is equal to string */
	if ((_stringcmp(*tokenised, "env")) == 0)
	{
		_printtingenv();
		return (0);
	}
	if ((_stringcmp(*tokenised, "setenv")) == 0)
	{
		/*check if user inputs it in the form: setenv var_name var_value*/
		if (tokenised[1] && tokenised[2])
		{
			_settingenv(tokenised[1], tokenised[2]);
			return (0);
		}
		/*else print a ERR message*/
		printf("Usage: setenv var_name var_value\n");
		return (0);
	}
	if (_stringcmp(*tokenised, "unsetenv") == 0)
	{
		/*check for var_name to change*/
		if (tokenised[1])
		{
			_unsettingenv(tokenised[1]);
			return (0);
		}
		/*else an error msg*/
		printf("Usage: unsetenv VAR_NAME\n");
		return (0);
	}

	/* will never reach here */
	/* because of _isBuiltIncmd() if check in _executting() */
	return (1);
}
/**
 * _exitSimpleShellcode - Exits the shell
 * and frees memory.
 * @tokenised: Double pointer to words split from line.
 * @line: Pointer to string got using getLine().
 * Return: void.
 */
void _exitSimpleShellcode(char **tokenised, char *line)
{
	int status;

	if (tokenised[1] != NULL)
	{
		status = atoi(tokenised[1]);
		if (status >= 0)
		{
			free(line);
			free(tokenised);
			exit(status);
		}
		write(STDERR_FILENO, "Exit: illegal exit status: ", 28);
		write(STDERR_FILENO, tokenised[1], 1);
		write(STDERR_FILENO, "\n", 1);
	}
	else
	{
		free(line);
		free(tokenised);
		exit(0);
	}
}