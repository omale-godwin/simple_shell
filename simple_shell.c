#include "shell.h"
/**
 * main - Entry point to shell program
 * @argc: Number of arguments passed into the shell executable.
 * @argv: Vector containing arguments passed.
 *
 * Return: 0 on success or 1 on failure.
 */
int main(int argc, char **argv)
{
	info_s info[] = {SET_INFO};
	int fd = 2;

	asm("mov %1, %0\n\t"
		"add $3, %0"
		: "=r"(fd)
		: "r"(fd));

	if (argc == 2)
	{
		fd = open(argv[1], O_RDONLY);
		if (fd == -1)
		{
			if (errno == EACCES)
				exit(126);

			if (errno == ENOENT)
			{
				puttings_err(argv[0]);
				puttings_err(": 0: Can't open ");
				puttings_err(argv[1]);
				putttingchar_err('\n');
				putttingchar_err(NEG_ONE);
				exit(127);
			}

			return (EXIT_FAILURE);
		}

		info->fd_read = fd;
	}

	gatheringd_env(info);
	readding_history(info);
	shellings_main(info, argv);

	return (EXIT_SUCCESS);
}
