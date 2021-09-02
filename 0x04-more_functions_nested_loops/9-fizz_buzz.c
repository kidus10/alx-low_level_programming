#include <stdio.h>
/**
* main - starting point of the program
*
* Return: Always 0
*/
int main(void)
{
	int i;

	for (i = 1 ; i <= 99 ; i++)
	{
		if (((i % 3) == 0) && ((i % 5) == 0))
		{
			printf("FizzBuzz ");
			continue;
		}
		else if ((i % 3) == 0)
		{
			printf("Fizz ");
			continue;
		}
		else if ((i % 5) == 0)
		{
			printf("Buzz ");
			continue;
		}
		printf("%d ", i);
	}
	printf("Buzz\n");
}
