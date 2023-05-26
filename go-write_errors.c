#include "shell.h"
/**
 * puttings_err - prints an input string
 * @string: the stringing to be printed
 *
 * Return: Nothing
 */
void puttings_err(char *string)
{
	int i = 0;

	if (!string)
		return;
	while (string[i] != '\0')
	{
		putttingchar_err(string[i]);
		i++;
	}
}
/**
 * putttingchar_err - writes the character c to stderr
 * @d: The character to print
 *
 * Return: On success 1.
 * On failure, -1 is returned
 */
int putttingchar_err(char d)
{
	static int i;
	static char buf[BUFFER_SIZE_WRITE];

	if (d == NEG_ONE || i >= BUFFER_SIZE_WRITE)
	{
		write(2, buf, i);
		i = 0;
	}
	if (d != NEG_ONE)
		buf[i++] = d;
	return (1);
}
/**
 * writting_char - writes the character c to given fd
 * @c: The character to print
 * @fdle: The filedescriptor to write to
 *
 * Return: On success 1.
 * On failure, -1 is returned
 */
int writting_char(char c, int fdle)
{
	static int i;
	static char buf[BUFFER_SIZE_WRITE];

	if (c == NEG_ONE || i >= BUFFER_SIZE_WRITE)
	{
		write(fdle, buf, i);
		i = 0;
	}
	if (c != NEG_ONE)
		buf[i++] = c;
	return (1);
}
/**
 * written_chars - prints an input string
 * @str: the string to be printed
 * @fdle: the filedescriptor to write to
 *
 * Return: the number of chars put
 */
int written_chars(char *strings, int fdle)
{
	int i = 0;

	if (!strings)
		return (0);
	while (*strings)
	{
		i += writting_char(*strings++, fdle);
	}
	return (i);
}
