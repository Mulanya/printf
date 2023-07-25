#include "main.h"

/**
 * get_flags - Calculates active flags from the format string.
 * @format: Formatted string in which to print the arguments.
 * @i: Pointer to the current index in the format string.
 * Return: Flags representing the active formatting options.
 */
int get_flags(const char *format, int *i)
{
	/* Flags represented by characters: - + 0 # ' ' */
	const char FLAGS_CH[] = {'-', '+', '0', '#', ' ', '\0'};

	/* Corresponding flag values: F_MINUS, F_PLUS, F_ZERO, F_HASH, F_SPACE */
	const int FLAGS_ARR[] = {F_MINUS, F_PLUS, F_ZERO, F_HASH, F_SPACE, 0};

	int j, curr_i;
	int flags = 0;

	for (curr_i = *i + 1; format[curr_i] != '\0'; curr_i++)
	{
		/* Check if the character in the format string corresponds to a flag */
		for (j = 0; FLAGS_CH[j] != '\0'; j++)
		{
			if (format[curr_i] == FLAGS_CH[j])
			{
				flags |= FLAGS_ARR[j];
				break;
			}
		}

		/* If the character is not part of the flags, exit the loop */
		if (FLAGS_CH[j] == '\0')
			break;
	}

	/* Update the current index to the end of the flags in the format string */
	*i = curr_i - 1;

	return (flags);
}
