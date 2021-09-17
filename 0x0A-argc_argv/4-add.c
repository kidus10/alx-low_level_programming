#include <stdio.h>
#include <stdlib.h>
/**
* main - starting point of the program
* @argc: argument count
* @argv: argument list
*
* Return: Always 0
*/
int main(int argc, char **argv)
{
	int a, b, sum;

	sum = 0;

	b = argc - 1;

	if (argc <= 1)
	{
		printf("0\n");

		return (0);
	}

	while (b)
	{
		a = atoi(argv[b]);

		if (a == 0)
		{
			printf("Error\n");

			return (1);
		}

		sum += a;

		b--;
	}

	printf("%d\n", sum);

	return (0);
}
