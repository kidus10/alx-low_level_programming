#include "main.h"
 #include <stdlib.h>

/**
  * _realloc - function that reallocates a memory block.
  * @ptr: the old pointer
  * @old_size: size in bytes allocated for the old pointer.
  * @new_size: size in bytes of the new pointer.
  *
  * Return: pointer to new mem block, NULL or ptr.
  */

void *_realloc(void *ptr, unsigned int old_size, unsigned int new_size)
{
	char *new_ptr;
	unsigned int i;

	if (new_size == old_size)
		return (ptr);
	if ((new_size == 0) && (ptr != NULL))
	{
		free(ptr);
		return (NULL);
	}
	if (ptr == NULL)
	{
		new_ptr = malloc(new_size);
		if (new_ptr == NULL)
			return (NULL);
	}
	if (new_size > old_size && (ptr != NULL))
	{
		new_ptr = malloc(new_size);
		if (new_ptr == NULL)
			return (new_ptr);
		for (i = 0; i < old_size; i++)
			new_ptr[i] = *((char *)ptr + 1);
		free(ptr);
	}

	return (new_ptr);
}
