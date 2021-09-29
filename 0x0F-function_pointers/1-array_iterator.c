#include "function_pointers.h"
/**
* array_iterator - function executes a fucntion given as a parameter
* on each elememt of an array
* @array: array to be iterated
* @size: is the size of the array
* @action: pointer to the function to be executed
* Return: returns nothing
*/
void array_iterator(int *array, size_t size, void (*action)(int))
{
	size_t i;

	if (array == NULL || action == NULL)
		return;
	for (i = 0; i < size; i++)
		action(array[i]);
}
