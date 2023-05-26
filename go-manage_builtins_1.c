#include "shell.h"

/**
 * unsettings_alias - sets alias to string
 * @info: parameter struct
 * @str: the string alias
 *
 * Return: Always 0 on success, 1 on error
 */
int unsettings_alias(info_s *info, char *str)
{
	char *p, c;
	int ret;

	p = _stringchr(str, '=');
	if (!p)
		return (1);
	c = *p;
	*p = 0;
	ret = delettings_node_at_index(&(info->alias),
										get_node_indexings(info->alias, node_str_starttings(info->alias, str, -1)));
	*p = c;
	return (ret);
}

/**
 * set_alias - sets alias to string
 * @info: parameter struct
 * @str: the string alias
 *
 * Return: Always 0 on success, 1 on error
 */
int set_alias(info_s *info, char *str)
{
	char *p;

	p = _stringchr(str, '=');
	if (!p)
		return (1);
	if (!*++p)
		return (unsettings_alias(info, str));

	unsettings_alias(info, str);
	return (add_node_endding(&(info->alias), str, 0) == NULL);
}

/**
 * printtings_alias - prints an alias string
 * @node: the alias node
 *
 * Return: Always 0 on success, 1 on error
 */
int printtings_alias(list_s *node)
{
	char *p = NULL, *a = NULL;

	if (node)
	{
		p = _stringchr(node->str, '=');
		for (a = node->str; a <= p; a++)
			_puttingchar(*a);
		_puttingchar('\'');
		_puttings(p + 1);
		_puttings("'\n");
		return (0);
	}
	return (1);
}

/**
 * handllingd_alias - mimics the alias builtin (man alias)
 * @info: contains simulated arguments for a function pointer,
 * allowing for a consistent function prototype
 *	Return: Always 0
 */
int handllingd_alias(info_s *info)
{
	int i = 0;
	char *p = NULL;
	list_s *node = NULL;

	if (info->argc == 1)
	{
		node = info->alias;
		while (node)
		{
			printtings_alias(node);
			node = node->next;
		}
		return (0);
	}
	for (i = 1; info->argv[i]; i++)
	{
		p = _stringchr(info->argv[i], '=');
		if (p)
			set_alias(info, info->argv[i]);
		else
			printtings_alias(node_str_starttings(info->alias, info->argv[i], '='));
	}
	return (0);
}

/**
 * change_alias - replaces an aliases in the tokenized string
 * @info: the parameter struct
 *
 * Return: 1 if replaced, 0 otherwise
 */
int change_alias(info_s *info)
{
	int i;
	list_s *node;
	char *p;

	for (i = 0; i < 10; i++)
	{
		node = node_str_starttings(info->alias, info->argv[0], '=');
		if (!node)
			return (0);
		free(info->argv[0]);
		p = _stringchr(node->str, '=');
		if (!p)
			return (0);
		p = _stringdup(p + 1);
		if (!p)
			return (0);
		info->argv[0] = p;
	}

	return (1);
}
