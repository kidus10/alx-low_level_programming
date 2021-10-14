#include "main.h"
/**
* print_binary - converts int to binary and prints it
* @n: the number
*
* Return: Void
*/
void print_binary(unsigned long int n)
{
	if (n > 1)
		print_binary(n >> 1);

	_putchar((n & 1) + '0');
}
