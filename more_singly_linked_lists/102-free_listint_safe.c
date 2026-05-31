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
	size_t i;
	listint_t *tmp;
	listint_t **array = NULL;

	if (h == NULL || *h == NULL)
		return (0);

	while (*h != NULL)
	{
		tmp = *h;

		/* check if node was already visited */
		for (i = 0; i < count; i++)
		{
			if (array[i] == tmp)
			{
				*h = NULL;
				free(array);
				return (count);
			}
		}

		array = realloc(array, sizeof(listint_t *) * (count + 1));
		if (array == NULL)
			return (count);

		array[count] = tmp;
		count++;

		*h = (*h)->next;
		free(tmp);
	}

	free(array);
	*h = NULL;

	return (count);
}
