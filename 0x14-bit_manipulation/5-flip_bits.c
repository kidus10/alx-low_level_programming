#include "main.h"
/**
* flip_bits - finds number of bits needed to be flipped \
* to get from one number to another
* @n: the decimal number
* @m: the other decimal number
*
* Return: number of bits needed to be flipped
*/
unsigned int flip_bits(unsigned long int n, unsigned long int m)
{
	unsigned long int flips, exposed_flip;

	exposed_flip = n ^ m;
	flips = 0;
	find_flip(exposed_flip, &flips);

	return (flips);
}

/**
* find_flip - counts the number of flips required
* @n: the exposed flip
* @flips: flip counter
*
* Return: always void
*/
void find_flip(unsigned long int n, unsigned long int *flips)
{
	if (n > 1)
		find_flip(n >> 1, flips);

	if (((n & 1) + '0') == '1')
		*flips = *flips + 1;
}
