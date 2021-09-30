#include <stdarg.h>
/**
* sum_them_all - sums all the variables
* @n: Numbers
*
* Return: sum of all @n
*/
int sum_them_all(const unsigned int n, ...)
{
	va_list ap;
	unsigned int i, sum;

	if (n == 0)
		return (0);

	sum = 0;

	va_start(ap, n);

	for (i = 0 ; i < n ; i++)
	{
		sum += va_arg(ap, unsigned int);
	}

	va_end(ap);

	return ((int) sum);
}
