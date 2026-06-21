#include "hash_tables.h"
#include <stdlib.h>
#include <string.h>
#include <stdio.h>

/**
 * shash_table_create - Creates a sorted hash table
 * @size: The size of the array
 *
 * Return: A pointer to the newly created sorted hash table, or NULL on failure
 */
shash_table_t *shash_table_create(unsigned long int size)
{
	shash_table_t *ht;
	unsigned long int i;

	ht = malloc(sizeof(shash_table_t));
	if (ht == NULL)
		return (NULL);

	ht->size = size;
	ht->shead = NULL;
	ht->stail = NULL;

	ht->array = malloc(sizeof(shash_node_t *) * size);
	if (ht->array == NULL)
	{
		free(ht);
		return (NULL);
	}

	for (i = 0; i < size; i++)
		ht->array[i] = NULL;

	return (ht);
}

/**
 * sorted_list_insert - Inserts a node into the sorted doubly linked list
 * @ht: The sorted hash table
 * @new_node: The new node to insert
 *
 * Inserts in ascending ASCII order by key.
 */
static void sorted_list_insert(shash_table_t *ht, shash_node_t *new_node)
{
	shash_node_t *current;

	/* Empty list */
	if (ht->shead == NULL)
	{
		ht->shead = new_node;
		ht->stail = new_node;
		new_node->sprev = NULL;
		new_node->snext = NULL;
		return;
	}

	/* Find insertion point (ascending ASCII order) */
	current = ht->shead;
	while (current != NULL && strcmp(new_node->key, current->key) > 0)
		current = current->snext;

	if (current == NULL)
	{
		/* Insert at end */
		new_node->sprev = ht->stail;
		new_node->snext = NULL;
		ht->stail->snext = new_node;
		ht->stail = new_node;
	}
	else if (current->sprev == NULL)
	{
		/* Insert at beginning */
		new_node->sprev = NULL;
		new_node->snext = ht->shead;
		ht->shead->sprev = new_node;
		ht->shead = new_node;
	}
	else
	{
		/* Insert in middle */
		new_node->sprev = current->sprev;
		new_node->snext = current;
		current->sprev->snext = new_node;
		current->sprev = new_node;
	}
}

/**
 * shash_table_set - Adds or updates a key/value pair in the sorted hash table
 * @ht: The sorted hash table
 * @key: The key (cannot be empty string)
 * @value: The value to associate with the key
 *
 * Return: 1 on success, 0 on failure
 */
int shash_table_set(shash_table_t *ht, const char *key, const char *value)
{
	shash_node_t *new_node, *current;
	unsigned long int index;

	if (ht == NULL || key == NULL || *key == '\0' || value == NULL)
		return (0);

	index = key_index((const unsigned char *)key, ht->size);

	/* Check if key already exists — update value if so */
	current = ht->array[index];
	while (current != NULL)
	{
		if (strcmp(current->key, key) == 0)
		{
			free(current->value);
			current->value = strdup(value);
			if (current->value == NULL)
				return (0);
			return (1);
		}
		current = current->next;
	}

	/* Key not found — create new node */
	new_node = malloc(sizeof(shash_node_t));
	if (new_node == NULL)
		return (0);

	new_node->key = strdup(key);
	if (new_node->key == NULL)
	{
		free(new_node);
		return (0);
	}

	new_node->value = strdup(value);
	if (new_node->value == NULL)
	{
		free(new_node->key);
		free(new_node);
		return (0);
	}

	new_node->next = NULL;
	new_node->sprev = NULL;
	new_node->snext = NULL;

	/* Prepend to the hash array chain (collision handling) */
	new_node->next = ht->array[index];
	ht->array[index] = new_node;

	/* Insert into sorted doubly linked list */
	sorted_list_insert(ht, new_node);

	return (1);
}

/**
 * shash_table_get - Retrieves the value associated with a key
 * @ht: The sorted hash table to search
 * @key: The key to look up
 *
 * Return: The value associated with the key, or NULL if not found
 */
char *shash_table_get(const shash_table_t *ht, const char *key)
{
	shash_node_t *current;
	unsigned long int index;

	if (ht == NULL || key == NULL || *key == '\0')
		return (NULL);

	index = key_index((const unsigned char *)key, ht->size);
	current = ht->array[index];

	while (current != NULL)
	{
		if (strcmp(current->key, key) == 0)
			return (current->value);
		current = current->next;
	}

	return (NULL);
}

/**
 * shash_table_print - Prints the hash table using the sorted linked list
 * @ht: The sorted hash table to print
 *
 * Traverses the sorted linked list (ascending order by key).
 */
void shash_table_print(const shash_table_t *ht)
{
	shash_node_t *current;
	int first = 1;

	if (ht == NULL)
		return;

	printf("{");
	current = ht->shead;
	while (current != NULL)
	{
		if (!first)
			printf(", ");
		printf("'%s': '%s'", current->key, current->value);
		first = 0;
		current = current->snext;
	}
	printf("}\n");
}

/**
 * shash_table_print_rev - Prints the hash table in reverse sorted order
 * @ht: The sorted hash table to print
 *
 * Traverses the sorted linked list backwards using stail.
 */
void shash_table_print_rev(const shash_table_t *ht)
{
	shash_node_t *current;
	int first = 1;

	if (ht == NULL)
		return;

	printf("{");
	current = ht->stail;
	while (current != NULL)
	{
		if (!first)
			printf(", ");
		printf("'%s': '%s'", current->key, current->value);
		first = 0;
		current = current->sprev;
	}
	printf("}\n");
}

/**
 * shash_table_delete - Deletes a sorted hash table and frees all memory
 * @ht: The sorted hash table to delete
 *
 * Uses the sorted list to free all nodes (avoids re-traversing the array).
 */
void shash_table_delete(shash_table_t *ht)
{
	shash_node_t *current, *tmp;

	if (ht == NULL)
		return;

	current = ht->shead;
	while (current != NULL)
	{
		tmp = current->snext;
		free(current->key);
		free(current->value);
		free(current);
		current = tmp;
	}

	free(ht->array);
	free(ht);
}
