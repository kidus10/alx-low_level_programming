#include "lists.h"

/**
* exec_before_main - prints strings before main is executed
*
* Return: Always Void
*/
void __attribute__ ((constructor)) exec_before_main(void)
{

	printf("You're beat! and yet, you must allow,\n");
	printf("I bore my house upon my back!\n");
}
