#include "shell.h"
/**
 * _atoi - return an int value from a string
 * @str: string value passed
 * Return: the int value from a string
 */
int _atoi(char *str)
{
	int sign = 1, i = 0;
	unsigned int result = 0;

	while (!(str[i] <= '9' && str[i] >= '0') && str[i] != '\0')
	{
		if (str[i] == '-')
		{
			sign *= -1;
		}
		i++;
	}
	while (str[i] <= '9' && (str[i] >= '0' && str[i] != '\0'))
	{
		result = (result * 10) + (str[i] - '0');
		i++;
	}
	result *= sign;
	return (result);
}
/**
 * _getenv - gets the environment variable
 * @string: the environment variable to be looked up for
 * Return: environment variable values
 */
char *_getenv(char *string)
{
	size_t n;
	int result, i;

	char *penviron[] = {
		"USER=daisy",
		"LOGNAME=daisy",
		"SESSION=ubuntu",
		"DISPLAY=:0",
		"PATH=/usr/local/sbin:/usr/local/bin:/usr/sbin:/usr/bin:/sbin:/bin",
		NULL
	};

	n = _strlen(string);
	for (i = 0; penviron[i] != NULL; i++)
	{
		result = strncmp(string, penviron[i], n);
		if (result == 0 && penviron[i][n])
		{
			return (&penviron[i][n + 1]);
		}
	}
	return (NULL);
}

/**
 * _putchar - prints a single character to standard output
 * @a: character to be printed.
 * Return: 1 else -1
 */
int _putchar(char a)
{
	return (write(1, &a, 1));
}

/**
 * print - prints chars to standard output
 * @buff: first argument in the list.
 * Return: 1
 */

ssize_t print(const char *buff, ...)
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
