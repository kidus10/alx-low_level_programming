#include "main.h"

/**
* create_file - function that creates file
* @filename: the file name
* @text_content: string to write to the file
*
* Return: -1 if: \
* on any kind of failiure and if @filename is NULL
* on success returns 1
*/

int create_file(const char *filename, char *text_content)
{
	int f_d;
	size_t str_len;
	ssize_t w_bytes;

	f_d = open(filename, O_WRONLY | O_TRUNC | O_CREAT, 00600);

	if (f_d == -1 || filename == NULL)
		return (-1);

	if (text_content == NULL)
	{
		close(f_d);
		return (1);
	}

	str_len = find_length(text_content);

	w_bytes = write(f_d, text_content, str_len);

	if (w_bytes == -1)
	{
		close(f_d);
		return (-1);
	}
	close(f_d);

	return (1);
}

/**
* find_length - finds the length of the string
* @text: the string
*
* Return: length of the string
*/
size_t find_length(char *text)
{
	size_t len;

	len = 0;

	while (*text != '\0')
	{
		len++;
		text++;
	}

	return (len);
}
