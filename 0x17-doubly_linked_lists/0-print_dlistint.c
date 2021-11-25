#include "lists.h"

/**
 * print_dlistint - prints all the elements of a dlistint_t list
 * @h: pointer to a dlistint_t list
 *
 * Return: the number of nodes
 */
size_t print_dlistint(const dlistint_t *h)
{
	size_t count;

	count = 0;

	while (h->prev != NULL)
		h = h->prev;

	while (h->next != NULL)
	{
		count++;
		h = h->next;
	}

	return (count + 1);
}
