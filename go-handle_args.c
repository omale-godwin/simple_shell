#include "shell.h"

/**
 * is_executting - determines if a file is an executable command
 * @info: the info struct
 * @pathed: pathed to the file
 *
 * Return: 1 if true, 0 otherwise
 */
bool is_executting(info_s *info, char *pathed)
{
	struct stat st;

	(void)info;
	if (!pathed || stat(pathed, &st))
		return (0);

	if (st.st_mode & S_IFREG)
	{
		return (true);
	}
	return (false);
}

/**
 * duppings_chars - duplicates characters
 * @pathstr: the PATH string
 * @start: starting index
 * @stop: stopping index
 *
 * Return: pointer to new buffer
 */
char *duppings_chars(char *pathstr, int start, int stop)
{
	static char buf[1024];
	int i = 0, k = 0;

	for (k = 0, i = start; i < stop; i++)
		if (pathstr[i] != ':')
			buf[k++] = pathstr[i];
	buf[k] = 0;
	return (buf);
}

/**
 * check_file_in_pathings - finds this cmd in the PATH string
 * @info: the info struct
 * @pathstr: the PATH string
 * @cmd: the cmd to find
 *
 * Return: full path of cmd if found or NULL
 */
char *check_file_in_pathings(info_s *info, char *pathstr, char *cmd)
{
	int i = 0, curr_pos = 0;
	char *path;

	if (!pathstr)
		return (NULL);
	if ((_stringlen(cmd) > 2) && starttings_with(cmd, "./"))
	{
		if (is_executting(info, cmd))
			return (cmd);
	}
	while (1)
	{
		if (!pathstr[i] || pathstr[i] == ':')
		{
			path = duppings_chars(pathstr, curr_pos, i);
			if (!*path)
				_stringcat(path, cmd);
			else
			{
				_stringcat(path, "/");
				_stringcat(path, cmd);
			}
			if (is_executting(info, path))
				return (path);
			if (!pathstr[i])
				break;
			curr_pos = i;
		}
		i++;
	}
	return (NULL);
}
