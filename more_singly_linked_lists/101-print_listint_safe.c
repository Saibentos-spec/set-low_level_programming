#include "lists.h"
#include <stdio.h>

/**
 * print_listint_safe - prints a listint_t linked list safely
 * @head: pointer to the first node
 *
 * Return: number of nodes in the list
 */
size_t print_listint_safe(const listint_t *head)
{
	const listint_t *slow, *fast, *loop_node = NULL;
	size_t count = 0;

	if (head == NULL)
		return (0);

	slow = fast = head;

	/* Floyd's cycle detection */
	while (fast && fast->next)
	{
		slow = slow->next;
		fast = fast->next->next;

		if (slow == fast)
		{
			loop_node = slow;
			break;
		}
	}

	slow = head;

	while (slow)
	{
		printf("[%p] %d\n", (void *)slow, slow->n);
		count++;

		if (loop_node && slow->next == loop_node && count > 1)
		{
			printf("-> [%p] %d\n", (void *)slow->next, slow->next->n);
			break;
		}

		slow = slow->next;
	}

	return (count);
}
