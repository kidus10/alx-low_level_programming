#include "main.h"
/**
 * main - starting point of the program
 * 
 * Return: Always 0.
 */
int main(void)
{
	int i;

	char ch[] = "Holberton";

	for (i = 0 ; i < 9 ; i++)
	{
		_putchar(ch[i]);
	}
	_putchar('\n');
	return (0);
}
