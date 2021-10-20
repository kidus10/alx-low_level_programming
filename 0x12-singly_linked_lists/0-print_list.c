#include "lists.h"

/**
* print_list - prints all the elements of list_t list
* @h: pointer to the list_t header
*
* Return: the number of nodes
*/
size_t print_list(const list_t *h)
{
	const list_t *current = h;
	size_t n_count = 0;

	while (current->next != NULL)
	{
		if (current->str == NULL)
			printf("[0] (nil)\n");
		else
			printf("[%d] %s\n", current->len, current->str);

		current = current->next;
		n_count++;
	}

	n_count++;

	if (current->str == NULL)
		printf("[0] (nil)\n");
	else
		printf("[%d] %s\n", current->len, current->str);

	return (n_count);
}
