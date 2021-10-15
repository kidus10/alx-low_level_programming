#include <stdio.h>
/**
 * main - starting point of the program
 *
 * Return: 0
 */
int main(void)
{
	int counter;

	counter = 0;

	while (counter <= 25)
	{
		putchar(counter + 'a');
		counter++;
	}

	counter = 0;

	while (counter <= 25)
	{
		putchar(counter + 'A');
		counter++;
	}
	putchar('\n');

	return (0);
}
