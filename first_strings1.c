#include "simple_shell.h"

/**
 * _stringlen - Returns length of a string.
 * @s: Pointer to string.
 * Return: Length of s.
 */
int _stringlen(char *s)
{
	int index;

	index = 0;
	while (s[index] != '\0')
	{
		index++;
	}
	return (index);
}
/**
 * _strcattings - Concatenates two strings.
 * @destnt: Pointer to string to be conatenated upon.
 * @src: Pointer to string to append to destnt.
 * Return: Pointer to destnt.
 */
char *_strcattings(char *destnt, char *src)
{
	char *destAddress;
	int destLen;

	destAddress = destnt;
	destLen = _stringlen(destnt);
	destAddress = destAddress + destLen;
	while (*src != '\0')
	{
		*destAddress = *src;
		src++;
		destAddress++;
	}
	*destAddress = '\0';

	return (destnt);
}

/**
 * _check_white_space - checks for white space.
 * @s: Pointer to string to check.
 * Return: integer.
 */
unsigned int _check_white_space(char *s)
{
	int i, count = 0;

	for (i = 0; s[i] != '\0'; i++)
	{
		if (s[i]  == ' ' || s[i] == '\t' || s[i] == '\n')
			count++;
	}
	return (count);
}

/**
 * _strtotokenised - splits a string into words.
 * @strg: Pointer to string.
 * Return: Pointer to array of words.
 */
char **_strtotokenised(char *strg)
{
	int i = 0;
	const char delimeter[] = " \t\n";
	int space = _check_white_space(strg);
	char **tokens = malloc(sizeof(char *) * (space + 1));
	char *token;

	if (!tokens)
	{
		free(tokens);
		fprintf(stderr, "sh: allocation error\n");
		exit(1);
	}

	token = strtok(strg, delimeter);

	while (token != NULL)
	{
		tokens[i] = token;
		token = strtok(NULL, delimeter);
		i++;
	}
	tokens[i] =  NULL;

	return (tokens);
}



/**
 * _putttind - prints a string, followed by a new line, to stdout.
 * @strg: string to print.
 */

void _putttind(char *strg)
{
	unsigned long i = 0;

	while (strg[i] != '\0')
	{
		_puttingchar(strg[i]);
		i++;
	}

	_puttingchar('\n');
}