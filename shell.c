#include "shell.h"

/**
 * main - entry point to compiling our shell
 * @argc:  argument count
 * @argv: argument vector
 *Return: 0 when successful, -1 otherwise
 */
int main(int argc, char *argv[]__attribute__((unused)))
{
	char *testr, *line = NULL;
	size_t buff;
	int nget;

	if (isatty(STDIN_FILENO) == 0 && argc == 1)
	{
		while ((nget = getline(&line, &buff, stdin)) > 0)
		{
			testr = malloc(sizeof(char) * nget + 1);
			_strcpy(testr, line);
			finalizer(testr);
			wait(NULL);
		}
		free(line);
		return (0);
	}
	do {
		testr = collect_args();
		if (testr[0] == '\0' || _strcmp(testr, "\n") == 0)
		{
			free(testr);
			continue;
		}
		finalizer(testr);
		wait(NULL);
		free(testr);
	} while (1);
	return (0);
}
