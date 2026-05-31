#include "lists.h"

/**
 * sum_dlistint - sums all elements of list
 * @head: head of list
 *
 * Return: sum or 0
 */
int sum_dlistint(dlistint_t *head)
{
	int sum = 0;

	while (head != NULL)
	{
		sum += head->n;
		head = head->next;
	}

	return (sum);
}
