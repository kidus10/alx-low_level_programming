#include "main.h"
#include <stdio.h>

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

int main()
{
	unsigned int n;

	n = power(2, 0);
	printf("n is:%u\n", n);

        n = power(2, 1);
        printf("n is:%u\n", n);

        n = power(2, 2);
        printf("n is:%u\n", n);

        n = power(2, 4);
        printf("n is:%u\n", n);

        n = power(2, 9);
        printf("n is:%u\n", n);

        n = power(2, 10);
        printf("n is:%u\n", n);

        n = power(2, 20);
        printf("n is:%u\n", n);

	return 0;
}	
