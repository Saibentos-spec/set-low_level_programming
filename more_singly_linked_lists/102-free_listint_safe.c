#include "lists.h"
#include <stdlib.h>

/**
 * free_listint_safe - frees a listint_t list safely (handles loops)
 * @h: pointer to head pointer
 *
 * Return: number of nodes freed
 */
size_t free_listint_safe(listint_t **h)
{
	size_t count = 0;
	listint_t *slow, *fast, *tmp;

	if (h == NULL || *h == NULL)
		return (0);

	slow = *h;
	fast = *h;

	/* Detect loop using Floyd cycle detection */
	while (fast != NULL && fast->next != NULL)
	{
		slow = slow->next;
		fast = fast->next->next;

		if (slow == fast)
			break;
	}

	/* Free normally until loop or NULL */
	slow = *h;

	while (slow != NULL)
	{
		tmp = slow;
		slow = slow->next;
		free(tmp);
		count++;

		/* If next node is already visited in loop case */
		if (slow == fast)
		{
			fast = NULL;
			break;
		}
	}

	*h = NULL;
	return (count);
}
