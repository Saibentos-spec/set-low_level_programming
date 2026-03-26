#include "main.h"

/**
 * reverse_array - reverses an array of integers
 * @a: array of integers
 * @n: number of elements
 *
 * Return: void
 */
void reverse_array(int *a, int n)
{
    int i, tmp;

    for (i = 0; i < n / 2; i++)
    {
        tmp = a[i];
        a[i] = a[n - i - 1];
        a[n - i - 1] = tmp;
    }
}
