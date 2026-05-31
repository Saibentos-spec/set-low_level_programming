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
	listint_t *visited[1024];
	size_t count = 0;
	size_t size;

	if (h == NULL || *h == NULL)
		return (0);

	size = free_nodes(*h, visited, &count);

	*h = NULL;
	return (size);
}
