#include "shell.h"
/**
 * is_chainning - test if current char in buffer is a chain delimeter
 * @info: the parameter struct
 * @buffer: the char bufferfer
 * @d: address of current position in buffer
 *
 * Return: 1 if chain delimeter else 0
 */
bool is_chainning(info_s *info, char *buffer, size_t *d)
{
	size_t j = *d;

	if (buffer[j] == '|' && buffer[j + 1] == '|')
	{
		buffer[j] = 0;
		j++;
		info->sep_buff_kind = OR_FLAG;
	}
	else if (buffer[j] == '&' && buffer[j + 1] == '&')
	{
		buffer[j] = 0;
		j++;
		info->sep_buff_kind = AND_FLAG;
	}
	else if (buffer[j] == ';')
	{
		buffer[j] = 0;
		info->sep_buff_kind = CHAIN_FLAG;
	}
	else
		return (false);
	*d = j;
	return (true);
}

/**
 * check_chainnings - checks we should continue chaining based on last status
 * @info: the parameter struct
 * @buf: the char buffer
 * @p: address of current position in buf
 * @i: starting position in buf
 * @len: length of buf
 *
 * Return: Void
 */
void check_chainnings(info_s *info, char *buf, size_t *p, size_t i, size_t len)
{
	size_t j = *p;

	if (info->sep_buff_kind == AND_FLAG)
	{
		if (info->status)
		{
			buf[i] = 0;
			j = len;
		}
	}
	if (info->sep_buff_kind == OR_FLAG)
	{
		if (!info->status)
		{
			buf[i] = 0;
			j = len;
		}
	}
	*p = j;
}

/**
 * changed_v - replaces vars in the tokenized string
 * @info: the parameter struct
 *
 * Return: 1 if replaced, 0 otherwise
 */
int changed_v(info_s *info)
{
	int i = 0;
	list_s *node;

	for (i = 0; info->argv[i]; i++)
	{
		if (info->argv[i][0] != '$' || !info->argv[i][1])
			continue;
		if (!_stringcmp(info->argv[i], "$?"))
		{
			changed_string(&(info->argv[i]),

						   _stringdup(changgings_base(info->status, 10, 0)));

			continue;
		}
		if (!_stringcmp(info->argv[i], "$$"))
		{
			changed_string(&(info->argv[i]),

						   _stringdup(changgings_base(getpid(), 10, 0)));

			continue;
		}
		node = node_str_starttings(info->env, &info->argv[i][1], '=');
		if (node)
		{
			changed_string(&(info->argv[i]),

						   _stringdup(_stringchr(node->str, '=') + 1));

			continue;
		}
		changed_string(&info->argv[i], _stringdup(""));
	}
	return (0);
}
/**
 * changed_string - replaces string
 * @old: address of old string
 * @new: new string
 *
 * Return: 1 if replaced, 0 otherwise
 */
int changed_string(char **old, char *new)
{
	free(*old);
	*old = new;

	return (1);
}
