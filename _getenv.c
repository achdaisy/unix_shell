#include "main.h"

/**
 * _getenv - gets an environment variable
 *
 * Return: 0
 */

char *_getenv(const char *string)
{
        extern char **environ;
        size_t n;
        int result, i;

        n = _strlen(string);
        for (i = 0; environ[i] != NULL; i++)
        {
                result = strncmp(string, environ[i], n);
                if (result == 0 && environ[i][n] == '=')
                {
                        return &environ[i][n + 1];
                }
        }
        return NULL; /*if the variable is not found in the environment*/
}
int main()
{
	char *buff;
	buff = _getenv("PATH");
	printf("%s\n", buff);
	return (0);
}
