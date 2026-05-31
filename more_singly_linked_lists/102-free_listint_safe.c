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
	listint_t *tmp, *checker;

	if (h == NULL)
		return (0);

	while (*h != NULL)
	{
		/* check if node was already seen */
		checker = *h;

		tmp = *h;

		/* detect loop by scanning already freed nodes */
		while (checker && checker != tmp)
			checker = checker->next;

		/* free current node */
		tmp = *h;
		*h = (*h)->next;
		free(tmp);
		count++;

		/* if loop detected, stop safely */
		if (*h == tmp)
			break;
	}

	*h = NULL;
	return (count);
}
