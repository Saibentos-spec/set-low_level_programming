#include "lists.h"

/**
 * find_listint_loop - finds the loop in a linked list
 * @head: pointer to the head
 *
 * Return: address of node where loop starts, or NULL
 */
listint_t *find_listint_loop(listint_t *head)
{
	listint_t *slow = head;
	listint_t *fast = head;

	if (head == NULL)
		return (NULL);

	while (fast != NULL && fast->next != NULL)
	{
		slow = slow->next;
		fast = fast->next->next;

		if (slow == fast)
		{
			/* Loop found, find start */
			slow = head;
			while (slow != fast)
			{
				slow = slow->next;
				fast = fast->next;
			}
			return (slow);
		}
	}
	return (NULL);
}
