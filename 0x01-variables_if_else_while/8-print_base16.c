#include <stdio.h>
/**
 *main - starting point of the program
 *
 *Return: 0
 */
int main(void)
{
	char alp;

	for (alp = 0; alp <= 9; alp++)
		putchar(alp + '0');
	for (alp = 'a'; alp <= 'f'; alp++)
		putchar(alp);
	putchar('\n');

	return (0);
}
