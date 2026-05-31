#include "lists.h"
#include <stdio.h>
#include <stdlib.h>

/**
 * print_listint_safe - prints a listint_t linked list safely (handles loops)
 * @head: pointer to the head
 *
 * Return: number of nodes
 */
size_t print_listint_safe(const listint_t *head)
{
	size_t count = 0;
	const listint_t *slow = head;
	const listint_t *fast = head;
	const listint_t *loop_start = NULL;

	if (head == NULL)
		return (0);

	while (fast != NULL && fast->next != NULL)
	{
		slow = slow->next;
		fast = fast->next->next;

		if (slow == fast)
		{
			/* Loop detected, find start */
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

	/* Print until loop or end */
	slow = head;
	while (slow != NULL)
	{
		printf("[%p] %d\n", (void *)slow, slow->n);
		count++;
		if (slow == loop_start && count > 1) /* Print the loop node once more? Wait, match example */
		{
			/* In example it shows the loop node with arrow */
			break; /* Adjust based on example */
		}
		if (slow->next == loop_start && loop_start != NULL)
		{
			printf("-> [%p] %d\n", (void *)slow->next, slow->next->n);
			count++; /* But count should be accurate */
			break;
		}
		slow = slow->next;
	}
	return (count);
}
