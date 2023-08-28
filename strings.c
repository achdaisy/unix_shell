#include "shell.h"
#include <stdio.h>
#include <stdlib.h>
/**
 * _strlen - return the length of an array
 * @s: array of chars
 * Return: number of chars in a string
 */
size_t _strlen(const char *s)
{
	size_t len = 0;

	while (s && s[len])
	{
		len++;
	}
	return (len);
}
/**
 * _strdup - returns duplicate value of string passed
 * @str: the original string passed
 * Return: pointer to the newly duplicate string
 */
char *_strdup(const char *str)
{

	int len = 0, i = 0; /*keep track of for loop*/
	char *str_dup; /*used to store the duplicate*/

	if (!str) /*check if the string is empty*/
	{
		perror("Error reading string");
		exit(EXIT_FAILURE);
	}
	/*check the length of the string*/
	while (str[i] != '\0')
	{
		i++;
	}
	str_dup = MALLOC_CHECK(malloc((i + 1) * sizeof(char)));
	for (; len < i; len++)
	{
		str_dup[len] = str[len]; /*copy contents*/
	}
	str_dup[i] = '\0'; /*add null terminator*/
	return (str_dup);
	free(str_dup);
}
/**
 * _strcat - append to a string
 * @s: pointer to what is to be appnded
 * @ap: what is to be appeded to the newly created string
 * Return: pointer to the newly created string
 */
char *_strcat(char *s, const char *ap)
{
	char *temp = s;

	while (*s != '\0')
	{
		s++;
	}
	while (*ap != '\0')
	{
		*s = *ap;
		s++;
		ap++;
	}
	*s = '\0';
	return (temp);
}
/**
 * _strcmp - compares two strings together
 * @s1: the first string
 * @s2: second string of chars to compare to
 * Return: 0 successful 2 no comparison -1 fail
 */
int _strcmp(const char *s1, const char *s2)
{
	unsigned int i = 0;

	while (s1[i] != '\0' && s2[i] != '\0')
	{
		if (s1[i] < s2[i]) /*differ in length*/
		{
			return (-1);
		}
		else if (s1[i] > s2[i])
		{
			return (1);
		}
		i++;
	}
	if (s1[i] == '\0' && s2[i] == '\0') /*same length and char*/
	{
		return (0);
	}
	else if (s1[i] == '\0') /*less char on s1*/
	{
		return (-1);
	}
	else /*less char on s2*/
	{
		return (1);
	}
}
/**
 * _strcpy - a copied string of chars
 * @copy: pointer to the new copied string
 * @original: pointer to the original string
 * Return: pointer to the newly copied string
 */
char *_strcpy(char *copy, const char *original)
{
	unsigned int i = 0;

	while (original[i] != '\0')
	{
		copy[i] = original[i];
		i++;
	}
	copy[i] = '\0';
	return (copy);
}
/*EOF - check helper.c for more helper functions*/
