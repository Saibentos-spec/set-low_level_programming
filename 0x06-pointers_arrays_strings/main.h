#ifndef MAIN_H
#define MAIN_H

/* Standard library header not allowed in some files */
/* You can include stdlib.h or stdio.h in main.c only if needed */

/* 0. strcat */
char *_strcat(char *dest, char *src);

/* 1. strncat */
char *_strncat(char *dest, char *src, int n);

/* 2. strncpy */
char *_strncpy(char *dest, char *src, int n);

/* 3. strcmp */
int _strcmp(char *s1, char *s2);

/* 4. reverse_array */
void reverse_array(int *a, int n);

/* 5. string_toupper */
char *string_toupper(char *str);

/* 6. cap_string */
char *cap_string(char *str);

/* 7. leet */
char *leet(char *str);

/* _putchar function prototype */
int _putchar(char c);

#endif /* MAIN_H */
