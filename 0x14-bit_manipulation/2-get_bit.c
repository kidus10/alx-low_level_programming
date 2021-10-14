#include "main.h"
/**
* get_bit - gets the bit at specified index
* @n: the decimal number
* @index: the index required
*
* Return: the index or -1 if error
*/
int get_bit(unsigned long int n, unsigned int index)
{
	unsigned int i, result;

	i = 0;

	while (i <= index && n > 0)
	{
		result = n % 2;
		n = n / 2;
		i++;
	}

	return (result);
}
