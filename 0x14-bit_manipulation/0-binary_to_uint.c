#include "main.h"
/**
* binary_to_uint - converts a binary to an unsigned int
* @b: string containing binary
*
* Return: converted number or 0 if:
* there is one or more chars in the string b that is not 0 or 1 or
* b is NULL
*/

unsigned int binary_to_uint(const char *b)
{
	unsigned int result, length, i;
	const char *current;

	current = b;
	length = 0;
	result = 0;
	i = 0;

	if (b == (void *)0) /* Same as if (b == NULL) */
		return (0);

	while (*current != '\0') /* loop through the string to find it's length */
	{
		if (*current == '0' || *current == '1') /* if it's not 0 or 1 returns 0 */
		{
			length++;
			current++;
		}
		else
		{
			return (0);
		}
	}

	while (i < length)
	{
		result += ((power(2, i)) * (bin_to_int(*(b + i))));
		i++;
	}

	return (result);
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

/**
* bin_to_int - converts the 0s and 1s in the string to int
* @c: binary string
*
* Return: 1 for 1, 0 for 0 and -1 if neither
*/

unsigned int bin_to_int(char c)
{
	if (c == '0')
		return (0);
	else if (c == '1')
		return (1);

	return (-1);
}
