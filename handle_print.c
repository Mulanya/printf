#include "main.h"

/**
 * handle_print - Prints an argument based on its type.
 * @fmt: Formatted string in which to print the arguments.
 * @ind: Pointer to the current index in the format string.
 * @list: List of arguments to be printed.
 * @buffer: Buffer array to handle print.
 * @flags: Calculates active flags.
 * @width: Width specifier.
 * @precision: Precision specifier.
 * @size: Size specifier.
 *
 * Return: Number of characters printed, or -1 on error.
 */
int handle_print(const char *fmt, int *ind, va_list list, char buffer[],
	int flags, int width, int precision, int size)
{
	int i, unknown_len = 0, printed_chars = -1;

	/* Structure to map format specifiers to corresponding print functions */
	fmt_t fmt_types[] = {
		{'c', print_char}, {'s', print_string}, {'%', print_percent},
		{'i', print_int}, {'d', print_int}, {'b', print_binary},
		{'u', print_unsigned}, {'o', print_octal}, {'x', print_hexadecimal},
		{'X', print_hexa_upper}, {'p', print_pointer}, {'S', print_non_printable},
		{'r', print_reverse}, {'R', print_rot13string}, {'\0', NULL}
	};

	for (i = 0; fmt_types[i].fmt != '\0'; i++)
	{
		/* Check if the format specifier matches any known type */
		if (fmt[*ind] == fmt_types[i].fmt)
			return (fmt_types[i].fn(list, buffer, flags, width, precision, size));
	}

	if (fmt_types[i].fmt == '\0')
	{
		/* Handle unknown format specifier or incomplete format string */
		if (fmt[*ind] == '\0')
			return (-1);

		unknown_len += write(1, "%%", 1);

		/* Handle the case when a space character is before the unknown format specifier */
		if (fmt[*ind - 1] == ' ')
			unknown_len += write(1, " ", 1);
		else if (width)
		{
			/* Handle incomplete format specifier with width specified */
			--(*ind);
			while (fmt[*ind] != ' ' && fmt[*ind] != '%')
				--(*ind);

			if (fmt[*ind] == ' ')
				--(*ind);

			return (1);
		}

		unknown_len += write(1, &fmt[*ind], 1);
		return (unknown_len);
	}

	return (printed_chars);
}
