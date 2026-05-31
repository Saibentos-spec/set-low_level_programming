#include "lists.h"
#include <stdlib.h>

/**
 * free_listint_safe - frees a listint_t list safely (handles loops)
 * @h: pointer to pointer to head
 *
 * Return: size of the list that was freed
 */
size_t free_listint_safe(listint_t **h)
{
	size_t count = 0;
	listint_t *current, *next;
	listint_t *slow, *fast;

	if (h == NULL || *h == NULL)
		return (0);

	slow = *h;
	fast = *h;

	/* Detect loop */
	while (fast != NULL && fast->next != NULL)
	{
		slow = slow->next;
		fast = fast->next->next;
		if (slow == fast)
			break;
	}

	current = *h;
	if (slow == fast && fast != NULL) /* Loop detected */
	{
		/* Find loop start */
		slow = *h;
		while (slow != fast)
		{
			slow = slow->next;
			fast = fast->next;
		}

		/* Free up to loop */
		while (current != slow)
		{
			next = current->next;
			free(current);
			current = next;
			count++;
		}

		/* Free the loop nodes once */
		next = current->next;
		free(current);
		count++;
		while (next != current)
		{
			listint_t *temp = next;
			next = next->next;
			free(temp);
			count++;
		}
	}
	else
	{
		/* No loop, free normally */
		while (current != NULL)
		{
			next = current->next;
			free(current);
			current = next;
			count++;
		}
	}

	*h = NULL;
	return (count);
}
