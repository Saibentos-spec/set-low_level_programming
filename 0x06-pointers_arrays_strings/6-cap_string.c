#include "main.h"

/**
 * cap_string - capitalizes all words of a string
 * @str: string
 *
 * Return: pointer to str
 */
char *cap_string(char *str)
{
    int i = 0;
    char sep[] = " \t\n,;.!?\"(){}";

    if (str[i] >= 'a' && str[i] <= 'z')
        str[i] -= 32;

    for (i = 1; str[i]; i++)
    {
        int j = 0;

        while (sep[j])
        {
            if (str[i - 1] == sep[j] && str[i] >= 'a' && str[i] <= 'z')
                str[i] -= 32;
            j++;
        }
    }

    return (str);
}
