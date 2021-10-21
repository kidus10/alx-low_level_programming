#include "lists.h"

/**
* listint_len - returns the number of elements in a linked listint_t list
* @h: pointer to the head of the linked list
*
* Return: number of elements in the linked list
*/
size_t listint_len(const listint_t *h)
{
	size_t n_count = 0;

	while (h->next != NULL)
	{
		h = h->next;
		n_count++;
	}

	n_count++;

	return (n_count);
}
