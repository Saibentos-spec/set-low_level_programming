#include "lists.h"
#include <stdlib.h>
#include <stdio.h>

/**
 * print_listint_safe - prints a listint_t list safely (handles loops)
 * @head: pointer to list
 *
 * Return: number of nodes printed
 */
size_t print_listint_safe(const listint_t *head)
{
	const listint_t *nodes[1024];
	size_t i, j = 0;
	size_t count = 0;

	while (head != NULL)
	{
		/* check if node already visited */
		for (i = 0; i < j; i++)
		{
			if (nodes[i] == head)
			{
				printf("-> [%p] %d\n", (void *)head, head->n);
				return (count);
			}
		}

		nodes[j++] = head;

		printf("[%p] %d\n", (void *)head, head->n);
		count++;

		head = head->next;
	}

	return (count);
}
