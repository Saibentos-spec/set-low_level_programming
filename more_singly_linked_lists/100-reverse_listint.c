#include "lists.h"

/**
 * reverse_listint - reverses a listint_t linked list
 * @head: pointer to pointer to the head of the list
 *
 * Return: pointer to the first node of the reversed list
 */
listint_t *reverse_listint(listint_t **head)
{
	listint_t *prev = NULL;
	listint_t *current = *head;

	while (current)
	{
		*head = current->next;        /* Move head to next node */
		current->next = prev;         /* Reverse the link */
		prev = current;               /* Move prev forward */
		current = *head;              /* Move current forward */
	}

	*head = prev;   /* Update head to new first node */

	return (*head);
}
