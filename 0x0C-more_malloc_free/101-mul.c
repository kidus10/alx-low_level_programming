#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

/**
 * main - program that multiplies two positive numbers.
 * @argc: number of command line arguments.
 * @argv: array containing the program command line arguments
 * Return: 0
 */

int main(int argc, char *argv[])
{
	int i = 1;
	int num1;
	int num2;
	int mul;

	while (i < argc)
	{
		if (!isdigit(*argv[i]))
		{
			printf("Error\n");
			exit(98);
		}
		else
		{
			num1 = atoi(argv[1]);
			num2 = atoi(argv[2]);
			mul = num1 * num2;
			i++;
		}
	}
	printf("%d\n", mul);
	return (0);
}
