#include <stdio.h>
/**
* main - starting point of the program
* @argc: argument count
* @argv: argument list
*
* Return: Always 0
*/
int main(int argc, char **argv)
{
	while (argc--)
		printf("%s\n", *argv++);

	return (0);
}
