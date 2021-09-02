#include "main.h"
/**
* more_numbers - prints 10 times the numbers from 0 to 14
*
* Return: Always Void
*/
void more_numbers(void)
{
	int i, j;

	char otf[] = "01234567891011121314";

	for (i = 0 ; i < 10 ; i++)
	{
		for (j = 0 ; j < 20 ; j++)
		{
			_putchar(otf[j]);
		}
		_putchar('\n');
	}
}
