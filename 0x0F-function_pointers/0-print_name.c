#include "function_pointers.h"
/**
* print_name - fucntion prints a name
* using a fucntion pointer
* @name: name to be printed
* @f: fucntion to be executed
* Return: function returns nothing
*/
void print_name(char *name, void (*f)(char *))
{
	if (name == NULL || f == NULL)
		return;
	f(name);
}
