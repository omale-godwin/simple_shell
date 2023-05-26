#include "shell.h"
/**
 * _listlennings - gets the length of linked list
 * @h: Pointer to first node.
 *
 * Return: Size of list.
 */
size_t _listlennings(const list_s *h)
{
	size_t i = 0;

	while (h)
	{
		h = h->next;
		i++;
	}
	return (i);
}

/**
 * listtings_to_vector - returns an array of strings of the list->str
 * @head: pointer to first node
 *
 * Return: Array of strings.
 */

char **listtings_to_vector(list_s *head)
{
	list_s *node = head;
	size_t i = _listlennings(head), j;
	char **strs;
	char *str;

	if (!head || !i)
		return (NULL);
	strs = malloc(sizeof(char *) * (i + 1));

	if (!strs)
		return (NULL);
	for (i = 0; node; node = node->next, i++)
	{
		str = malloc(_stringlen(node->str) + 1);
		if (!str)
		{
			for (j = 0; j < i; j++)
				free(strs[j]);
			free(strs);
			return (NULL);
		}
		str = _stringcpy(str, node->str);
		strs[i] = str;
	}
	strs[i] = NULL;
	return (strs);
}

/**
 * print_listtings - prints all elements of a list_s linked list
 * @h: pointer to first node
 *
 * Return: Size of list
 */

size_t print_listtings(const list_s *h)
{
	size_t i = 0;

	while (h)
	{
		_puttings(changgings_base(h->num, 10, 0));
		_puttingchar(':');
		_puttingchar(' ');
		_puttings(h->str ? h->str : "(nil)");
		_puttings("\n");
		h = h->next;
		i++;
	}
	return (i);
}

/**
 * node_str_starttings - returns node whose string starts with prefix
 * @node: pointer to list head
 * @prefix: string to check
 * @c: the next character after prefix to check
 *
 * Return: match node or null
 */

list_s *node_str_starttings(list_s *node, char *prefix, char c)
{
	char *p = NULL;

	while (node)
	{
		p = starttings_with(node->str, prefix);
		if (p && ((c == -1) || (*p == c)))
			return (node);
		node = node->next;
	}
	return (NULL);
}

/**
 * get_node_indexings - gets the index of a node
 * @head: pointer to list head
 * @node: pointer to the node
 *
 * Return: -1 or index of node
 */

ssize_t get_node_indexings(list_s *head, list_s *node)
{
	size_t i = 0;

	while (head)
	{
		if (head == node)
			return (i);
		head = head->next;
		i++;
	}
	return (-1);
}
