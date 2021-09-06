#include "main.h"
/**
* print_rev - prints a string in reverse
* @s : string
*
* Return: Always Void
*/
void print_rev(char *s)
{
	int len = _strlen(s);

	while (len >= 0)
	{
		_putchar(*(s + i));
		len--;
	}
}
