#include "main.h"

/**
 * rev_string - reverses a string
 * @s: string
 */
void rev_string(char *s)
{
	int i = 0;
	int len = 0;
	char temp;

	while (s[len] != '\0')
		len++;

	while (i < len / 2)
	{
		temp = s[i];
		s[i] = s[len - 1 - i];
		s[len - 1 - i] = temp;
		i++;
	}
}
