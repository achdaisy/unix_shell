#include "main.h"

/**
 * print_a_char - prints a single character to standard output
 * @a: character to be printed.
 * Return: 1 else -1
 */

int print_a_char(char a)
{
	return (write(1, &a, 1));
}

/**
 * print_a_str - prints chars to standard output
 * @buff: first argument in the list.
 * Return: 1
 */

ssize_t print_a_str(const char *buff, ...)
{
	va_list ap;
	const char *buff2;
	ssize_t total_written = 0, written;
	size_t len;

	va_start(ap, buff);
	len = _strlen(buff);
	written = write(1, buff, len);
	if (written < 0)
	{
		return (-1);
	}
	total_written += written;

	while ((buff2 = va_arg(ap, const char *)) != NULL)
	{
		len = _strlen(buff2);
		written = write(1, buff2, len);
		if (written < 0)
		{
			return (-1);
		}
		total_written += written;
	}
	va_end(ap);
	return (total_written);
}
