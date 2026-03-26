#include "main.h"

/**
 * leet - encodes a string into 1337
 * @str: string to encode
 *
 * Return: pointer to str
 */
char *leet(char *str)
{
    int i, j;
    char letters[] = "aAeEoOtTlL";
    char codes[] = "4433007711";

    for (i = 0; str[i]; i++)
    {
        for (j = 0; letters[j]; j++)
        {
            if (str[i] == letters[j])
            {
                str[i] = codes[j];
                break;
            }
        }
    }

    return (str);
}
