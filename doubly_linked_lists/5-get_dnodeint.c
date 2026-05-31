#include "lists.h"

/**
 * get_dnodeint_at_index - returns node at index
 * @head: head of list
 * @index: index to search
 *
 * Return: pointer to node or NULL
 */
dlistint_t *get_dnodeint_at_index(dlistint_t *head, unsigned int index)
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
