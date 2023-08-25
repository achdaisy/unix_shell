#include "shell.h"
#include <linux/limits.h>
/**
 * MALLOC_CHECK - simple malloc checker function
 * @ptr: pointer to check for allocation failure
 * Return: pointer to the newly allocated memory
 */
void *MALLOC_CHECK(void *ptr)
{
	if (ptr == NULL)
	{
		perror("Allocation failed");
		return (NULL); /* we don't want to exit the shell */
	}
	return (ptr);
}
