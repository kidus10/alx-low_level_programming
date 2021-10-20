#include "lists.h"

/**
* add_node_end - adds a new node at the end of a list_t list
* @head: pointer to the head of the list
* @str: string
*
* Return: address of the new element, or NULL if it failed
*/
list_t *add_node_end(list_t **head, const char *str)
{
	int len = 0;
	list_t *current = *head;
	list_t *end_node = malloc(sizeof(list_t));

	while (current->next != NULL)
		current = current->next;

	current->next = end_node;

	end_node->next = NULL;

	end_node->str = strdup(str);

	while (*(end_node->str + len) != '\0')
		len++;

	end_node->len = len;

	return (end_node);
}
