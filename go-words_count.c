#include "shell.h"

/**
 * words_countting - counts the number of words in a string specified by
 *				 one or more delimiter. It also counts the length of
 *				 each word and stores them in an array.
 * @string: Stringing to be parsed.
 * @separatorssing: One or more delimiters to separate the stringing by.
 * @arr: Pointer to array where the word lengths will be stored.
 *
 * Return: Number of words.
 */

int words_countting(char *string, char *separatorssing, unsigned int *arr)
{
	unsigned int c, d, word_len = 1;
	unsigned int word_count = 0;
	char *str_copy = string;
	bool start = false, delimiter;

	/* If the string is empty */
	if (!string)
		return (0);

	/* Shift string pointer to first non-delimiter character */
	while (!start)
		for (d = 0; separatorssing[d]; d++)
		{
			if (*str_copy == separatorssing[d])
				str_copy++;
			else
				start = true;
		}

	/* If the string has only one character */
	if (!*(str_copy + 1))
	{
		arr[0] = 1;
		return (1);
	}

	for (c = 1; str_copy[c]; c++)
	{
		/* Compare each delimiter with the current character */
		delimiter = is_a_delimiter(str_copy[c], separatorssing);

		/* If current char is a delimiter and previous char is not */
		if (delimiter && !(is_a_delimiter(str_copy[c - 1], separatorssing)))
		{
			arr[word_count] = word_len;
			word_count++;
		}

		/* If we're at the end of the string and its not a delimiter */
		if ((!str_copy[c + 1]) && !delimiter)
		{
			word_len++;
			arr[word_count] = word_len;
			word_count++;
			break;
		}

		if (!delimiter)
			word_len++;
		else
			word_len = 0;
	}

	return (word_count);
}
