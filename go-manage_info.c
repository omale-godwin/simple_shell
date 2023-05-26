#include "shell.h"
/**
 * clear_infomationg - initializes info_s struct
 * @info: struct address
 */
void clear_infomationg(info_s *info)
{
	info->arg = NULL;
	info->argv = NULL;
	info->path = NULL;
	info->argc = 0;
}
/**
 * set_info - initializes info_s struct
 * @info: struct address
 * @av: argument vector
 */
void set_info(info_s *info, char **av)
{
	int i = 0;

	info->prog_name = av[0];
	if (info->arg)
	{
		info->argv = stringtow(info->arg, " \t");
		if (!info->argv)
		{
			info->argv = malloc(sizeof(char *) * 2);
			if (info->argv)
			{
				info->argv[0] = _stringdup(info->arg);
				info->argv[1] = NULL;
			}
		}
		for (i = 0; info->argv && info->argv[i]; i++)
			;
		info->argc = i;
		change_alias(info);
		changed_v(info);
	}
}
/**
 * free_infomation - frees info_s struct fields
 * @info: struct address
 * @all: true if freeing all fields
 */
void free_infomation(info_s *info, int all)
{
	freeing_vector(info->argv);
	info->argv = NULL;
	info->path = NULL;
	if (all)
	{
		if (!info->sep_buff)
			free(info->arg);
		if (info->env)
			free_listtings(&(info->env));
		if (info->history)
			free_listtings(&(info->history));
		if (info->alias)
			free_listtings(&(info->alias));
		freeing_vector(info->environ);
		info->environ = NULL;
		bfreetings((void **)info->sep_buff);
		if (info->fd_read > 2)
			close(info->fd_read);
		_puttingchar(NEG_ONE);
	}
}
