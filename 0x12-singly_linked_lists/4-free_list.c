#include "lists.h"

/**
* free_list - frees a list_t list
* @head: pointer to the head of list_t list
*
* Return: Always void
*/
void free_list(list_t *head)
{
	list_t *head_ptr;

	while (head != NULL)
	{
		head_ptr = head;
		head = head->next;

		free(head_ptr->str);

		free(head_ptr);
	}
}
