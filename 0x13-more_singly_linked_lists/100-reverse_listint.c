#include "lists.h"
/**
 * reverse_listint - Reverses listint_t linked list
 * @head: List
 * Return: pointer to first node of reversed list
 */

listint_t *reverse_listint(listint_t **head)
{
	listint_t *p;/*Previous*/
	listint_t *n;/*Next*/

	/*Empty list*/
	if (head == NULL || *head == NULL)
		return (NULL);

	p = NULL;
	while (*head != NULL)
	{
		n = (*head)->next;
		(*head)->next = p;
		p = *head;
		*head = n;
	}
	(*head) = p;

	return (*head);
}
