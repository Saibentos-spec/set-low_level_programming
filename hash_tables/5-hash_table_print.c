#include "hash_tables.h"
#include <stdio.h>

/**
 * hash_table_print - Prints the hash table in array order
 * @ht: The hash table to print
 *
 * Format: {'key': 'value', 'key': 'value'}
 * If ht is NULL, prints nothing
 */
void hash_table_print(const hash_table_t *ht)
{
	hash_node_t *current;
	unsigned long int i;
	int first = 1;

	if (ht == NULL)
		return;

	printf("{");
	for (i = 0; i < ht->size; i++)
	{
		current = ht->array[i];
		while (current != NULL)
		{
			if (!first)
				printf(", ");
			printf("'%s': '%s'", current->key, current->value);
			first = 0;
			current = current->next;
		}
	}
	printf("}\n");
}
