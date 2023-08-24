#include "main.h"
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
 * _strstr - returns a string of chars found in another string
 * @haystack: string of chars we are given
 * @needle: the string of chars we are looking for
 * Return: 0 success
 */
char *_strstr(char *haystack, char *needle)
{
	char *l, *p;

	for (; *haystack != '\0'; haystack++)
	{
		 l = haystack;
		 p = needle;

		while (*l == *p && *p != '\0')
		{
			l++;
			p++;
		}

		if (*p == '\0')
			return (haystack);
	}

	return (0);
}
