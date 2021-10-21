#include "lists.h"

/**
* print_listint - prints all the elements of a listint_t list
* @h: pointer to the head of the listint_t list
*
* Return: the number of nodes
*/
size_t print_listint(const listint_t *h)
{
	const listint_t *current = h;
	size_t n_count = 0;

	while (current->next != NULL)
	{
		printf("%d\n", current->n);

		current = current->next;
		n_count++;
	}

	n_count++;
	printf("%d\n", current->n);

	return (n_count);
}
