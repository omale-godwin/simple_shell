#include "simple_shell.h"

/**
 * is_delimed - Check if char is equal to delim.
 * @c: character.
 * @delim: " "
 * Return: 0 if no match, 1 if matched.
 */

int is_delimed(char c, const char *delim)
{
	while (delim && *delim)
	{
		if (c == *delim)
		{
			return (1);
		}
		++delim;
	}
	return (0);
}

/**
 * _stringtok - Mimics strtok, which tokenizes a string and turn to array.
 * @src: String from getline.
 * @delim: " ";
 * Return: Individual token in array format.
 */

char *_stringtok(char *src, const char *delim)
{
	static char *s;
	static unsigned int i;
	char *result = NULL;
	int is_space = 0;

	if (src)
	{
		s = src;
		for (i = 0; s[i]; i++)
		{
			if (is_delimed(s[i], delim))
				s[i] = '\0';
		}
	}

	if (s == NULL || *s == '\0')
		return (NULL);
	result = s;
	i = _stringlen(s);
	if (s[i] == '\0' && _stringlen(s) > 0)
		is_space = 1;
	s = s + _stringlen(s) + is_space;
	return (result);
}

/**
 *controlc - Control C handler.
 *@signum: The signal number received.
 *
 *Return: Void.
 */
void controlc(int signum)
{
	(void)signum;

	write(STDOUT_FILENO, "\n#cisfun$ ", 10);
}


/**
 * getting_line - Stores into malloced buffer the user's command into shell.
 * @str: Buffer.
 * Return: Number of characters read.
 */
ssize_t getting_line(char **str)
{
	ssize_t i = 0, size = 0, t = 0, t2 = 0, n = 0;
	char buff[1024];

	/* read while there's stdin greater than buffsize; -1 to add a '\0' */
	while (t2 == 0 && (i = read(STDIN_FILENO, buff, 1024 - 1)))
	{
		if (i == -1) /* check if read errored */
			return (-1);

		buff[i] = '\0'; /* terminate buff with \0 to use with _strcattings */

		n = 0; /* last loop if \n is found in the stdin read */
		while (buff[n] != '\0')
		{
			if (buff[n] == '\n')
				t2 = 1;
			n++;
		}

		/* copy what's read to buff into getting_line's buffer */
		if (t == 0) /* malloc the first time */
		{
			i++;
			*str = malloc(sizeof(char) * i);
			*str = _stringcpy(*str, buff);
			size = i;
			t = 1;
		}
		else /* _realloc via _strcattings with each loop */
		{
			size += i;
			*str = _strcattings(*str, buff);
		}
	}
	return (size);
}
/**
 *  _stringdup - Duplicates string.
 *  @str: String to duplicate.
 *  Return: Pointer to duplicated string in allocated memory.
 */
char *_stringdup(char *str)
{
	char *duplicate_str;
	int i, len = 0;

	if (str == NULL)
		return (NULL);
	while (str[len])
		len++;
	len++; /* add null terminator to length */
	duplicate_str = malloc(sizeof(char) * len);
	if (duplicate_str == NULL)
		return (NULL);
	i = 0;
	while (i < len)
	{
		duplicate_str[i] = str[i];
		i++;
	}
	return (duplicate_str);
}