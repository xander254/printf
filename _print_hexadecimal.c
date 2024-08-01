#include "main.h"

/**
  *_print_hexadecimal - function that prints hexadecimals
  *@number: Number to be printed in hexadecimal
  *@uppercase: flag indicating whether to use uppercase letters
  *
  * Return: number of characters to be printed
  */

int _print_hexadecimal(unsigned int number, int uppercase)
{
	int i = 8;
	char buffer[9];
	int total_chars = 0;
	const char (*digits) = (uppercase) ? "0123456789ABCDEF" : "0123456789abcdef";

	buffer[i--] = '\0';

	if (number == 0)
	{
		buffer[i--] = '0';
	}
	else
	{
		while (number > 0 && i >= 0)
		{
			buffer[i--] = digits[number % 16];
			number /= 16;
		}
	}

	total_chars = write(1, &buffer[i + 1], 8 - i - 1);

	return (total_chars);
}
