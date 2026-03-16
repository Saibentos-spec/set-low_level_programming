#include <stdio.h>
#include "main.h"

/**
 * print_remaining_days - prints remaining days in year
 * @month: month
 * @day: day
 * @year: year
 */

void print_remaining_days(int month, int day, int year)
{
	int days_in_year = 365;

	if ((year % 4 == 0 && year % 100 != 0) || (year % 400 == 0))
	{
		days_in_year = 366;

		if (month > 2)
			day += 1;
	}

	if (month == 2 && day == 60 && days_in_year == 365)
	{
		printf("Invalid date: %02d/%02d/%04d\n", month, day - 31, year);
	}
	else
	{
		printf("Day of the year: %d\n", day);
		printf("Remaining days: %d\n", days_in_year - day);
	}
}
