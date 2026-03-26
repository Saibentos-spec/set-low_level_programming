#include "main.h"

/**
 * _strncat - concatenates two strings using at most n bytes from src
 * @dest: destination string
 * @src: source string
 * @n: max bytes from src
 *
 * Return: pointer to dest
 */
char *_strncat(char *dest, char *src, int n)
{
    int i = 0, j = 0;

    while (dest[i])
        i++;

    while (src[j] && j < n)
    {
        dest[i] = src[j];
        i++;
        j++;
    }

    dest[i] = '\0';
    return (dest);
}
