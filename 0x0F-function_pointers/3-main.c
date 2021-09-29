#include <stdio.h>
#include "3-calc.h"

/**
 * main - main function
 * @argc: elemt of array
 * @argv: an array
 * Return: 0 value
 */


int main(int argc, char *argv[])
{
int x, y;
int (*opern)(int, int);

if (argc != 4)
{
printf("Error\n");
exit(98);
}
if (argv[2][1])
{
printf("Error\n");
exit(99);
}

opern = get_op_func(argv[2]);

if (opern == NULL)
{
printf("Error\n");
exit(99);
}
x = atoi(argv[1]);
y = atoi(argv[3]);

printf("%d\n", opern(x, y));

return (0);
}
