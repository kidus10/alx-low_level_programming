#include <stdio.h>
/**
 * main - starting point of the program
 *
 * Return: 0
 */
int main(void)
{
	int counter;

	counter = 25;

	while (counter >= 0)
	{
		putchar(counter + 'a');
		counter--;
	}
	putchar('\n');

	return (0);
}
