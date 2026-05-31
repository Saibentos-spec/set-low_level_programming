#include "lists.h"
#include <stdio.h>

/**
 * print_listint_safe - prints a listint_t linked list safely (handles loops)
 * @head: pointer to the head of the list
 *
 * Return: number of nodes in the list
 */
size_t print_listint_safe(const listint_t *head)
{
	const listint_t *slow = head;
	const listint_t *fast = head;
	const listint_t *loop_start = NULL;
	size_t count = 0;

	if (head == NULL)
		return (0);

	/* Special case: single node loop */
	if (head->next == head)
	{
		printf("[%p] %d\n", (void *)head, head->n);
		printf("-> [%p] %d\n", (void *)head, head->n);
		return (1);
	}

	/* Floyd’s Cycle Detection */
	while (fast && fast->next)
	{
		slow = slow->next;
		fast = fast->next->next;

		if (slow == fast)
		{
			/* Find exact start of the loop */
			slow = head;
			while (slow != fast)
			{
				slow = slow->next;
				fast = fast->next;
			}
			loop_start = slow;
			break;
		}
	}

	/* Print nodes */
	slow = head;
	while (slow)
	{
		printf("[%p] %d\n", (void *)slow, slow->n);
		count++;

		/* Stop before printing the loop node a second time */
		if (loop_start && slow->next == loop_start)
		{
			printf("-> [%p] %d\n", (void *)slow->next, slow->next->n);
			break;
		}

		slow = slow->next;
	}

	return (count);
}
