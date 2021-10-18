#include "main.h"

/**
* append_text_to_file - appends text at the end of file
* @filename: the file
* @text_content: string to be appended
*
* Return: 1 on success, -1 on failiure \
* -1 if @filename is NULL
*/

int append_text_to_file(const char *filename, char *text_content)
{
	int f_d;
	ssize_t w_bytes;
	size_t str_len;

	f_d = open(filename, O_WRONLY | O_APPEND);

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
