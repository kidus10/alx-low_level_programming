#include "main.h"
/**
* clear_bit - sets the value of a bit to 0 at index
* @n: the decimal number
* @index: the index
*
* Return: 1 is successful, -1 if error
*/
int clear_bit(unsigned long int *n, unsigned int index)
{
	unsigned int clearer;

	clearer = ~(power(2, index));
	*n = *n & clearer;

	return (1);
}

/**
* power - give the power of the number
* @a: number to be powered
* @b: the power
*
* Return: result of the power
*/

unsigned int power(unsigned int a, unsigned int b)
{
	unsigned int p_result;

	p_result = 1;

	if (b == 0)
		return (1);
	if (b == 1)
		return (a);

	while (b)
	{
		p_result *= a;
		b--;
	}

	return (p_result);
}
