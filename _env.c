#include <stdio.h>
#include <string.h>

void env()
{
	char *env_elements[] = {
		"USER=daisy",
		"LOGNAME=daisy",
		"SESSION=ubuntu",
		"DISPLAY=:0",
		"PATH=/usr/local/sbin:/usr/local/bin:/usr/sbin:/usr/bin:/sbin:/bin",
		NULL 
	};

	for (int i = 0; env_elements[i] != NULL; i++)
	{
		printf("%s\n", env_elements[i]);
	}
}

int main()
{
	env();
	return (0);
}
