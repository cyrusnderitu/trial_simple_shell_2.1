#include "shell.h"

/**
 *collect_args - collects input from user
 *Return: pointer to array
 */
char *collect_args(void)
{
	size_t len = 0;
	char *ptr = NULL, *line = NULL;
	ssize_t nread;

	write(STDOUT_FILENO, "#cisfun$ ", 9);
	while ((nread = getline(&line, &len, stdin)) != -1)
	{
		ptr = malloc(nread + 1);
		_strcpy(ptr, line);
		free(line);
		break;
	}
	if (nread == -1)
	{
		write(1, "\n", 1);
		exit(0);
	}
	return (ptr);
}
