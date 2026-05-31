#include "lists.h"

/**
 * delete_nodeint_at_index - deletes the node at a given index
 * @head: pointer to pointer to the head of the list
 * @index: index of the node to delete (starts at 0)
 *
 * Return: 1 if it succeeded, -1 if it failed
 */
int delete_nodeint_at_index(listint_t **head, unsigned int index)
{
	listint_t *current, *temp;
	unsigned int i = 0;

	if (head == NULL || *head == NULL)
		return (-1);

	current = *head;

	/* Delete head node */
	if (index == 0)
	{
		*head = current->next;
		free(current);
		return (1);
	}

	/* Traverse to the node before the one to delete */
	while (current && i < index - 1)
	{
		current = current->next;
		i++;
	}

	/* If index is out of range */
	if (current == NULL || current->next == NULL)
		return (-1);

	/* Delete the node */
	temp = current->next;
	current->next = temp->next;
	free(temp);

	return (1);
}
