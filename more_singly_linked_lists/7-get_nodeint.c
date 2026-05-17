#include "lists.h"

/**
 * get_nodeint_at_index - returns node at index
 * @head: pointer to list
 * @index: index of node (starting at 0)
 *
 * Return: pointer to node, or NULL
 */
listint_t *get_nodeint_at_index(listint_t *head, unsigned int index)
{
	unsigned int i = 0;

	while (head != NULL)
	{
		if (i == index)
			return (head);

		head = head->next;
		i++;
	}

	return (NULL);
}
