#include <stdio.h>
#include <unistd.h>
/**
 * main - starting point of the program
 *
 * Return: 1
 */
int main(void)
{
	String quote = "and that piece of art is useful\" - Dora Korpar, 2015-10-19";
	write(2, quote, sizeof(quote));
	return (1);
}
