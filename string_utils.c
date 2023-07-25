#include "shell.h"

/**
 * _strcat - Concatenates two strings
 *  @dest: The string to be appended upon.
 *  @src: The string to be appended to dest.
 *  Return: A pointer to the resulting string dest.
 *
 */
char *_strcat(char *dest, char *src)
{
	int index = 0, dest_len = 0;

	while (dest[index++])
		dest_len++;
	for (index = 0; src[index]; index++)
		dest[dest_len++] = src[index];
	return (dest);
}

/**
 * _strcpy - copies the string pointed to by src
 * @dest: pointer to the destiination address
 * @src: pointer to the string
 * Return: destination to pointer
 */

char *_strcpy(char *dest, char *src)
{
	char *dest_ptr = dest;

	if (dest == NULL)
		return (NULL);
	while (*src != '\0')
	{
		*dest = *src;
		dest++;
		src++;
	}
	*dest = '\0';
	return (dest_ptr);
}

/**
 * _strcmp - Compares pointers to two strings.
 * @s1: A pointer to the first string to be compared.
 * @s2: A pointer to the second string to be compared.
 * Return: Comparison betw
 * If str1 < str2, the negative difference of the first unmatched characters.
 * If str1 == str2, 0.
 * If str1 > str2, the positive difference of the first unmatched characters.
 */
int _strcmp(char *s1, char *s2)
{
while ((*s1 && *s2) && (*s1 == *s2))
{
s1++;
s2++;
}
return (*s1 - *s2);
}

/**
 *_strlen- calculates the length of a string
 *@s:string parameter to calculate the length
 *Return: Length of the string
 */

int _strlen(char *s)
{
	int countchar = 0;

	while (s[countchar] != '\0')
	{
		countchar++;
	}
	return (countchar);
}
