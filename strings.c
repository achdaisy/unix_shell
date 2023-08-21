#include "main.h"
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
	/*allocate memory to the duplicate string as the previous one
	 */
	str_dup = malloc((i + 1) * sizeof(char));
	if (!str_dup) /*check for failure*/
	{
		perror("Whops!! Memory allocation failed");
		exit(EXIT_FAILURE);
	}
	for (; len < i; len++)
	{
		str_dup[len] = str[len]; /*copy contents*/
	}
	str_dup[len] = '\0'; /*add null terminator*/
	return (str_dup);
}
/**
 * _strcat - append to a string
 * @s: pointer to what is to be appended
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
