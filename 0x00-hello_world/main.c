#include "main.h"
#include <stdio.h>

/**
 * main - test all functions
 *
 * Return: Always 0
 */
int main(void)
{
	int n = 402;
	int a = 98, b = 42;
	char str1[] = "Hello World!";
	char str2[100];
	int array[5] = {98, 402, -198, 298, -1024};

	printf("=== Task 0 ===\n");
	printf("Before: n = %d\n", n);
	reset_to_98(&n);
	printf("After: n = %d\n\n", n);

	printf("=== Task 1 ===\n");
	printf("Before: a = %d, b = %d\n", a, b);
	swap_int(&a, &b);
	printf("After: a = %d, b = %d\n\n", a, b);

	printf("=== Task 2 ===\n");
	printf("Length: %d\n\n", _strlen(str1));

	printf("=== Task 3 ===\n");
	_puts(str1);

	printf("\n=== Task 4 ===\n");
	print_rev(str1);

	printf("\n=== Task 5 ===\n");
	printf("Before: %s\n", str1);
	rev_string(str1);
	printf("After: %s\n\n", str1);

	printf("=== Task 6 ===\n");
	puts2("0123456789");

	printf("\n=== Task 7 ===\n");
	puts_half("0123456789");

	printf("\n=== Task 8 ===\n");
	print_array(array, 5);

	printf("\n=== Task 9 ===\n");
	_strcpy(str2, "Copy this string!");
	printf("%s\n", str2);

	return (0);
}
