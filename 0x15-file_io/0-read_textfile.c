#include "main.h"

/**
* read_textfile - reads a text file and prints it to the POSIX standard output
* @filename: the text file
* @letters: number of letters it should read and print
*
* Return: acutual number of letters it could read and print \
* returns 0 if: \
* the file can not be opened or read or \
* @filename is NULL or \
* write fails or does not write the expected amount of bytes
*/

ssize_t read_textfile(const char *filename, size_t letters)
{
	int f_d;
	ssize_t wr_bytes, rd_bytes;
	char *buffer;

	f_d = open(filename, O_RDONLY);

	if (f_d == -1 || filename == NULL)
		return (0);

	buffer = malloc(sizeof(char) * letters);
	rd_bytes = read(f_d, buffer, letters);

	if (rd_bytes == -1)
	{
		free(buffer);
		close(f_d);
		return (0);
	}

	wr_bytes = write(STDOUT_FILENO, buffer, rd_bytes);

	if (wr_bytes == -1)
	{
		free(buffer);
		close(f_d);
		return (0);
	}

	free(buffer);
	close(f_d);

	return (rd_bytes);
}
