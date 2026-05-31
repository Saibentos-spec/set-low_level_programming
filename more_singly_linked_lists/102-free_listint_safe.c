#include "lists.h"

/**
 * free_listint_safe - frees a listint_t list, handling loops
 * @h: pointer to pointer to the head of the list
 *
 * Return: size of the list that was freed
 */
size_t free_listint_safe(listint_t **h)
{
	listint_t *slow;
	listint_t *fast;
	size_t count;
	listint_t *tmp;

	if (h == NULL || *h == NULL)
		return (0);

	slow = *h;
	fast = *h;
	count = 0;

	while (fast != NULL && fast->next != NULL)
	{
		slow = slow->next;
		fast = fast->next->next;
		if (slow == fast)
			break;
	}

	if (fast == NULL || fast->next == NULL)
	{
		while (*h != NULL)
		{
			tmp = (*h)->next;
			free(*h);
			*h = tmp;
			count++;
		}
		return (count);
	}

	/* Loop exists - find loop start and count unique nodes */
	slow = *h;
	while (slow != fast)
	{
		slow = slow->next;
		fast = fast->next;
	}

	/* Break the loop */
	fast = slow->next;
	while (fast != slow)
	{
		fast = fast->next;
	}
	/* fast now points to node just before loop start — find it */
	fast = *h;
	if (fast != slow)
	{
		while (fast->next != slow)
			fast = fast->next;
		fast->next = NULL;
	}
	else
	{
		/* loop starts at head, find last node */
		fast = slow->next;
		while (fast->next != slow)
			fast = fast->next;
		fast->next = NULL;
	}

	/* Now free normally */
	while (*h != NULL)
	{
		tmp = (*h)->next;
		free(*h);
		*h = tmp;
		count++;
	}

	*h = NULL;
	return (count);
}
