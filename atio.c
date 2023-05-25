#include "shell.h"

/**
 * _atoi_with_error - Function to find the error value.
 * @s: the string.
 * Return: int or -1.
 */

int _atoi_with_error(char *s)
{
	int i = 0;
	unsigned long int digit = 0;

	if (*s == '+')
		s++;

	for (i = 0; s[i] != '\0'; i++)
	{
		if (s[i] >= '0' && s[i] <= '9')
		{
			digit *= 10;
			digit += (s[i] - '0');
			if (digit > INT_MAX)
				return (-1);
		}
		else
			return (-1);
	}

	return (digit);
}

/**
 * int_to_string - Function that converts int to string.
 * @number: the number.
 * @str: the string.
 * Return: nothing
 */

void int_to_string(int number, char *str)
{
	int i = 0;
	int j = 0;
	int isNegative = 0;
	int length;
	char temp;

	if (number < 0)
	{
		isNegative = 1;
		number = -number;
	}

	do {
		str[i++] = number % 10 + '0';
		number /= 10;
	} while (number > 0);

	if (isNegative)
	{
		str[i++] = '-';
	}

	str[i] = '\0';

	length = i;
	for (j = 0; j < length / 2; j++)
	{
		temp = str[j];
		str[j] = str[length - j - 1];
		str[length - j - 1] = temp;
	}
}
