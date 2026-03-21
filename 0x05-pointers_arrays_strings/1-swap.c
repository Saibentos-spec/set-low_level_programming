#include "main.h"

/**
 * swap_int - swaps two integers
 * @a: first integer pointer
 * @b: second integer pointer
 */
void swap_int(int *a, int *b)
{
	int temp;

	temp = *a;
	*a = *b;
	*b = temp;
}
