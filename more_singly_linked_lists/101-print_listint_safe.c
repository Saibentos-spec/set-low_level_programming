#include "lists.h"
#include <stdio.h>

/**
 * print_listint_safe - prints a listint_t linked list (safe version)
 * @head: pointer to the head of the list
 *
 * Return: number of nodes in the list
 */
size_t print_listint_safe(const listint_t *head)
{
	const listint_t *slow = head;
	const listint_t *fast = head;
	size_t count = 0;
	int loop_detected = 0;

	if (head == NULL)
		return (0);

	while (fast && fast->next)
	{
		slow = slow->next;
		fast = fast->next->next;

		if (slow == fast)
		{
			loop_detected = 1;
			break;
		}
	}

	slow = head;
	count = 0;

	while (head)
	{
		printf("[%p] %d\n", (void *)head, head->n);
		count++;

		if (loop_detected && head->next == slow && count > 1)
		{
			printf("-> [%p] %d\n", (void *)head->next, head->next->n);
			break;
		}

		head = head->next;
	}

	return (count);
}
