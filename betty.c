#include "shell.h"
#include <stdio.h>

/**
 * numbers_addition - Function that adds two numbers
 * @y: Number one
 * @z: Number two
 * Return: The total numbers
 */
int numbers_addition(int y, int z)
{
	return (y + z);
}

/**
 * main - Programm entry point
 * Return: 0 always
 */
int main(void)
{
	int fig1 = 5;
	int fig2 = 10;
	int total;

	total = numbers_addition(fig1, fig2);

	printf("The total is: %d\n", total);

	return (0);
}
