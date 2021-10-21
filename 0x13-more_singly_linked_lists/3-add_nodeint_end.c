#include "lists.h"

/**
* add_nodeint_end - adds a new node at the end of a listint_t list
* @head: pointer to the head of the list
* @n: the number
*
* Return: address of the new element, or NULL if it failed
*/
listint_t *add_nodeint_end(listint_t **head, const int n)
{
	listint_t *current = *head;
	listint_t *end_node = malloc(sizeof(listint_t));

	while (current->next != NULL)
		current = current->next;

	current->next = end_node;
	end_node->next = NULL;
	end_node->n = n;

	return (end_node);
}
