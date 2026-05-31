#include "lists.h"
#include <stdio.h>

/**
 * print_listint_safe - prints a listint_t linked list (safe version with loops)
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

	/* Special case: single node pointing to itself */
	if (head->next == head)
	{
		printf("[%p] %d\n", (void *)head, head->n);
		printf("-> [%p] %d\n", (void *)head, head->n);
		return (1);
	}

	/* Floyd’s cycle detection */
	while (fast && fast->next)
	{
		slow = slow->next;
		fast = fast->next->next;

		if (slow == fast)
		{
			/* Find start of loop */
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

	/* Print the list */
	slow = head;
	while (slow)
	{
		printf("[%p] %d\n", (void *)slow, slow->n);
		count++;

		if (loop_start && slow->next == loop_start && count > 1)
		{
			printf("-> [%p] %d\n", (void *)slow->next, slow->next->n);
			break;
		}

		slow = slow->next;
	}

	return (count);
}
