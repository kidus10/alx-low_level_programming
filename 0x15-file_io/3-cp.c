#include "main.h"

/**
* main - copies the content of a file to another file
* @argc: argument count
* @argv: argument list
*
* Return: 1 on success
*/

int main(int argc, char **argv)
{
	int f_d_from, f_d_to, count, c_f_d_from, c_f_d_to;
	ssize_t r_bytes, w_bytes;
	char *buffer;

	if (argc != 3)
	{
		dprintf(STDERR_FILENO, "Usage: cp file_from file_to\n");
		exit(97);
	}

	f_d_from = open(argv[1], O_RDONLY);

	if (f_d_from == -1)
	{
		dprintf(STDERR_FILENO, "Error: Can't read from file %s\n", argv[1]);
		exit(98);
	}

	f_d_to = open(argv[2], O_WRONLY | O_TRUNC | O_CREAT, 00664);

	if (f_d_to == -1)
	{
		dprintf(STDERR_FILENO, "Error: Can't write to %s\n", argv[2]);
		exit(99);
	}

	buffer = malloc(sizeof(char) * 1024);

	while (r_bytes)
	{
		r_bytes = read(f_d_from, buffer, 1024);
		count++;
	}
	w_bytes = write(f_d_to, buffer, (1024 * count));

	if (w_bytes == -1)
	{
		dprintf(STDERR_FILENO, "Error: Can't write to %s\n", argv[2]);
		exit(99);
	}

	free(buffer);
	c_f_d_from = close(f_d_from);
	c_f_d_to = close(f_d_to);

	if (c_f_d_from == -1)
	{
		dprintf(STDERR_FILENO, "Error: Can't close fd %d\n", f_d_from);
		exit(100);
	}
	if (c_f_d_to == -1)
	{
		dprintf(STDERR_FILENO, "Error: Can't close fd %d\n", f_d_to);
		exit(100);
	}

	return (0);
}
