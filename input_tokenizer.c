#include "shell.h"

/**
 * _strtok - breaks string str into a series of tokens
 * using the delimiter delim
 *
 * @str: string to be split into tokens
 * @delim: specified delimeter
 * Return: next token
 */
char *_strtok(char *str, const char *delim)
{
	static char *last_token = NULL;
	char *token;

	if (str != NULL)
		last_token = str;

	if (last_token == NULL)
		return (NULL);

	while (*last_token && strchr(delim, *last_token))
		last_token++;
	if (!*last_token)
	{
		last_token = NULL;
		return (NULL);
	}

	token = last_token;

	while (*last_token && !strchr(delim, *last_token))
		last_token++;

	if (*last_token)
	{
		*last_token = '\0';
		last_token++;
	}

	else
		last_token = NULL;

	return (token);
}
