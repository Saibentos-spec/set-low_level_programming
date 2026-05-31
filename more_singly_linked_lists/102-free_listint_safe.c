#include "lists.h"
#include <stdlib.h>
/**
 * free_listint_safe - frees a listint_t list safely (handles loops)
 * @h: pointer to pointer to the head of the list
 *
 * Return: the size of the list that was freed
 */
size_t free_listint_safe(listint_t **h)
{
	listint_t *slow = *h;
	listint_t *fast = *h;
	listint_t *temp;
	size_t count = 0;

	if (h == NULL || *h == NULL)
		return (0);

	/* Detect if there is a loop */
	while (fast && fast->next)
	{
		slow = slow->next;
		fast = fast->next->next;

		if (slow == fast)
			break;
	}

	slow = *h;
	while (slow)
	{
		count++;
		temp = slow;
		slow = slow->next;

		/* If we detect the loop again, stop after freeing current node */
		if (fast && temp == fast)
		{
			free(temp);
			break;
		}

		free(temp);
	}

	*h = NULL;

	return (count);
}
