#include "shell.h"
/**
 * _strtok -custom strtok function
 * @str: string of chars passed
 * @delim: delimiters specified
 * Return: pointer to the newly tokenized string
 */
char *_strtok(char *str, char *delim)
{
	static char *last_token;
	char *token;

	if (str == NULL && last_token == NULL)
		/* reached the end */
		return (NULL);
	if (str == NULL)
		/* then move to the next one in line */
		str = last_token;
	str += _strspn(str, delim); /* remove all the trailing delimiters */
	if (*str == '\0')
	{
		/* check whether we've reached the end of the string */
		last_token = NULL;
		return (NULL);
	}
	token = str + _strcspn(str, delim); /* update the token */
	*token++ = '\0'; /* make it point to a null terminator */
	last_token = token;  /* update the last token */
	return (str);
}
/**
 * _strspn - Entry point
 * @s: input
 * @accept: input
 * Return: Always 0 (Success)
 */
unsigned int _strspn(char *s, char *accept)
{
	unsigned int n = 0;
	int r, match;

	while (*s)
	{
		match = 0; /* checks for any match from s */
		for (r = 0; accept[r]; r++)
		{
			if (*s == accept[r]) /* looks for all the matching char */
			{
				match = 1;
				break; /* once you see one exit the loop */
			}
		}
		if (!match)
			break;
		n++; /* position of where the match ends */
		s++;
	}
	return (n);
}
/**
 * _strcspn - Entry point
 * @s: input
 * @rejects: input
 * Return: Always 0 (Success)
 */
unsigned int _strcspn(char *s, char *rejects)
{
	unsigned int n = 0;
	int r, match;

	while (*s)
	{
		match = 0; /* checks for any match from s */
		for (r = 0; rejects[r]; r++)
		{
			if (*s != rejects[r]) /* looks for all the non-matching char */
			{
				match = 1;
				break; /* once you see one exit the loop */
			}
		}
		if (!match)
			break;
		n++; /* position of where the non-match ends */
		s++;
	}
	return (n);
}
