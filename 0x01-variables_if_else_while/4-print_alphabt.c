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

	while (counter <= 25) /* total size of alphabet -> 25+1 */
	{
		if ((counter == 4) || (counter == 16)) /* 4+1 is e, 16+1 is q */
			continue;

		putchar(counter + 'a');
		counter++;
	}
	putchar('\n');

	return (0);
}
