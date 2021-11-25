#include "lists.h"

/**
 * add_dnodeint - add a new node at the beginning of a dlistint_t list
 * @head: double pointer to head of linked list
 * @n: value to the new node
 *
 * Return: pointer to the new node, otherwise NULL on failure
 */
dlistint_t *add_dnodeint(dlistint_t **head, const int n)
{
	dlistint_t *new;

	new = malloc(sizeof(dlistint_t));
	if (head == NULL || new == NULL)
		return (NULL);
	new->prev = NULL;
	new->next = *head;
	new->n = n;
	*head = new;
	if (new->next != NULL)
		(new->next)->prev = new;
	return (new);
}
