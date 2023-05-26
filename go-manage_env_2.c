#include "shell.h"

/**
 * _gettingenv - gets the value of an environ variable
 * @info: contains simulated arguments for a function pointer,
 * @name: env var name
 *
 * Return: the value
 */

char *_gettingenv(info_s *info, const char *name)
{
	char *p;
	list_s *node = info->env;

	while (node)
	{
		p = starttings_with(node->str, name);
		if (p && *p)
			return (p);
		node = node->next;
	}
	return (NULL);
}

/**
 * checkings_setenv - Checks if an environment variable has been set.
 * @info: contains simulated arguments for a function pointer,
 * allowing for a consistent function prototype
 *
 * Return: 0 if set, else 1.
 */

int checkings_setenv(info_s *info)
{
	if (info->argc != 3)
	{
		puttings_err("Incorrect number of arguements\n");
		return (1);
	}

	if (_settingsenv(info, info->argv[1], info->argv[2]))
		return (0);
	return (1);
}

/**
 * checkking_unsettingsenv - Remove an environment variable
 * @info: contains simulated arguments for a function pointer,
 * allowing for a consistent function prototype
 * Return: Always 0
 */
int checkking_unsettingsenv(info_s *info)
{
	int i;

	if (info->argc == 1)
	{
		puttings_err("Too few arguements.\n");
		return (1);
	}
	for (i = 1; i <= info->argc; i++)
		_unsettingsenv(info, info->argv[i]);

	return (0);
}

/**
 * gatheringd_env - populates env linked list
 * @info: contains simulated arguments for a function pointer,
 * allowing for a consistent function prototype
 * Return: Always 0
 */
int gatheringd_env(info_s *info)
{
	list_s *node = NULL;
	size_t i;

	for (i = 0; environ[i]; i++)
		add_node_endding(&node, environ[i], 0);
	info->env = node;
	return (0);
}

/**
 * _printtingenv - prints the current environment
 * @info: contains simulated arguments for a function pointer,
 * allowing for a consistent function prototype
 * Return: Always 0
 */
int _printtingenv(info_s *info)
{
	printtings_list_str(info->env);
	return (0);
}
