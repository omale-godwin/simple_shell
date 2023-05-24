#include "simple_shell.h"


/**
 * if_file_in_exists - Checks file status.
 * @s: Pointer to file name.
 * Return: 0 if success, else non zero.
 */
int if_file_in_exists(char *s)
{
	struct stat st;

	return (stat(s, &st));
}


/**
 * builder_of_path - Constructs a path to binaries.
 * @tokenised: Double pointer to tokenised.
 * Return: Return - path, else - NULL.
 */
char *builder_of_path(char **tokenised)
{
	char path1[100] = "/bin/";
	char path2[100] = "/usr/bin/";

	char *finalPath1;
	char *finalPath2;

	finalPath1 = _strcattings(path1, tokenised[0]);

	if ((if_file_in_exists(finalPath1) == 0))
		return (finalPath1);

	finalPath2 = _strcattings(path2, tokenised[0]);
	if ((if_file_in_exists(finalPath2) == 0))
		return (finalPath2);

	return (NULL);
}

/**
 * second_execute - Executes a file.
 * @tokenised: Split string into tokenised from stdin.
 * @path: Path from builder_of_path function.
 * @args: Program arguments.
 * Return: 0 - on success, else - 1.
 */
int second_execute(char **tokenised, char *path, char *args)
{
	char *err1, *err2, *err3;
	pid_t child_pid;
	int status;

	child_pid = fork();
	if (child_pid == -1)
	{
		perror("Error: ");
		return (1);
	}

	if (child_pid == 0)
	{
		tokenised[0] = path;

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
	return (EXIT_SUCCESS);
}