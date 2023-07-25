#include "main.h"

/**
 * is_printable - Evaluates if a char is printable
 * @c: Char to be evaluated.
 *
 * Return: 1 if c is printable, 0 otherwise.
 */
int is_printable(char c)
{
	/* Characters with ASCII values between 32 and 126 are printable */
	if (c >= 32 && c < 127)
		return (1);

	return (0);
}

/**
 * append_hexa_code - Append ASCII in hexadecimal format to buffer
 * @buffer: Array of chars.
 * @i: Index at which to start appending.
 * @ascii_code: ASCII code of the non-printable character.
 *
 * Return: Always 3 (length of the hexadecimal representation).
 */
int append_hexa_code(char ascii_code, char buffer[], int i)
{
	char map_to[] = "0123456789ABCDEF";

	/* ASCII code can be negative, so make it positive for representation */
	if (ascii_code < 0)
		ascii_code *= -1;

	buffer[i++] = '\\';
	buffer[i++] = 'x';

	/* Convert the ASCII code into its hexadecimal representation */
	buffer[i++] = map_to[ascii_code / 16];
	buffer[i] = map_to[ascii_code % 16];

	return (3);
}

/**
 * is_digit - Verifies if a char is a digit
 * @c: Char to be evaluated.
 *
 * Return: 1 if c is a digit, 0 otherwise.
 */
int is_digit(char c)
{
	/* Characters with ASCII values between '0' and '9' are digits */
	if (c >= '0' && c <= '9')
		return (1);

	return (0);
}

/**
 * convert_size_number - Casts a number to the specified size
 * @num: Number to be casted.
 * @size: Number indicating the type to be casted (S_LONG, S_SHORT, or default).
 *
 * Return: Casted value of num with the specified size.
 */
long int convert_size_number(long int num, int size)
{
	/* Cast the number to the specified size (long, short, or int) */
	if (size == S_LONG)
		return (num);
	else if (size == S_SHORT)
		return ((short)num);

	return ((int)num);
}

/**
 * convert_size_unsgnd - Casts an unsigned number to the specified size
 * @num: Number to be casted.
 * @size: Number indicating the type to be casted (S_LONG, S_SHORT, or default).
 *
 * Return: Casted value of the unsigned num with the specified size.
 */
long int convert_size_unsgnd(unsigned long int num, int size)
{
	/* Cast the unsigned number to the specified size (long, short, or int) */
	if (size == S_LONG)
		return (num);
	else if (size == S_SHORT)
		return ((unsigned short)num);

	return ((unsigned int)num);
}
