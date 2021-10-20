#include "lists.h"

/**
* add_node - adds a new node at the beginning of a list_t list
* @head: pointer to the head of the list
* @str: string
*
* Return: addres of the new element, NULL if failed
*/
list_t *add_node(list_t **head, const char *str)
{
	int i = 0;
	list_t *new_node = malloc(sizeof(list_t));

	if (new_node == NULL)
		return (NULL);

	new_node->next = *head;

	new_node->str = strdup(str);

	while (*(new_node->str + i) != '\0')
		i++;

	new_node->len = i;

	*head = new_node;

	return (new_node);
}
