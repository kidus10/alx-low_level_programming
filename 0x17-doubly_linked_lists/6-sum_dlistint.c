#include "lists.h"

/**
 * sum_dlistint - returns the sum of all the data\
 *                 (n) of a dlistint_t linked list
 * @head: pointer to the head of the linked list
 *
 * Return: sum, otherwise 0
 */
int sum_dlistint(dlistint_t *head)
{
	int sum;

	sum = 0;
	while (head != NULL)
	{
		sum += head->n;
		head = head->next;
	}
	return (sum);
}
