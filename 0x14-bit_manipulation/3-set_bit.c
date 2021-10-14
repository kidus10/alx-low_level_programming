 #include "main.h"
/**
* set_bit - sets the given index to 1
* @n: the number
* @index: the index
*
* Return: 1 on success, -1 on failiure
*/
int set_bit(unsigned long int *n, unsigned int index)
{
	unsigned int setter;

	setter = power(2, index);

	*n = *n ^ setter;

	return (1);
}

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
