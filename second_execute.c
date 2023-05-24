#include "simple_shell.h"

/**
 * _executting - Executes a file.
 * @tokenised: Split string into tokenised from stdin.
 * @args: Program arguments.
 * Return: 0 if success. otherwise - 1.
 */
int _executting(char **tokenised, char *args)
{
	char *err1, *err2, *err3;
	pid_t child_pid;
	int status;
	char *path;
	/* check if first token is a built in */
	if (_isBuiltIncmd(*tokenised) == 0)
	{
		status = _executeBuiltIncmd(tokenised);
		return (status);
	}
	/* if path wasn't entered e.g ls, pwd, etc */
	path = builder_of_path(tokenised);
	if (path != NULL)
	{
		status = second_execute(tokenised, path, args);
		return (status);
	}
	/* if path was entered e.g /bin/ls */
	child_pid = fork();
	if (child_pid == -1)
	{
		perror("Error: ");
		return (1);
	}
	if (child_pid == 0)
	{

		if (execve(tokenised[0], tokenised, NULL) == -1)
		{
			err1 = _strcattings(*tokenised, ": No such file or directory\n");
			err2 = _strcattings(args, ":");
			err3 = _strcattings(err2, err1);
			write(STDERR_FILENO, err3, _stringlen(err3));
			free(tokenised);
			exit(EXIT_FAILURE);
		}
		return (EXIT_SUCCESS);
	}
	wait(&status);
	return (0);
}
