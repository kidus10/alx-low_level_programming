#include "main.h"
/**
* more_numbers - prints 10 times the numbers from 0 to 14
*
* Return: Always Void
*/
void more_numbers(void)
{
	int i, j;
	char str[] = "01234567891011121314";

	i = 0;
	j = 0;

	while (i < 10)
	{
		while (j < 20)
		{
			_putchar(str[j]);
			j++;
		}
		_putchar('\n');

		i++;
	} 
}
