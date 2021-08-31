#include "main.h"
/**
* print_alphabet - print the alphabet in lowercae followed by  a newline
*
* Return: void
*/

void print_alphabet(void)
{
	char ch;

	for (ch = 'a' ; ch <= 'z' ; ch++)
	{
		_putchar(ch);
	}
	_putchar('\n');
}

