#include "main.h"

/**
* main - copies the content of a file to another file
* @argc: argument count
* @argv: argument list
*
* Return: 0 on success
*/

int main(int argc, char **argv)
{
	int f_d_from, f_d_to, c_f_d_from, c_f_d_to;
	ssize_t r_bytes, w_bytes;
	char *buffer;

	r_bytes = 1;

	if (argc != 3)
		exit_prog("Usage: cp file_from file_to", 97, NULL, 0, 0);

	f_d_from = open(argv[1], O_RDONLY);
	if (f_d_from == -1)
		exit_prog("Error: Can't read from file", 98, argv[1], 0, 1);

	f_d_to = open(argv[2], O_WRONLY | O_TRUNC | O_CREAT, 00664);
	if (f_d_to == -1)
		exit_prog("Error: Can't write to", 99, argv[2], 0, 1);

	buffer = safe_buffer(argv[2]);

	while (r_bytes > 0)
	{
		r_bytes = read(f_d_from, buffer, 1024);
		w_bytes = write(f_d_to, buffer, r_bytes);

		if (w_bytes == -1)
			exit_prog("Error: Can't write to", 99, argv[2], 0, 1);
	}
	if (r_bytes == -1)
		exit_prog("Error: Can't read from file", 98, argv[1], 0, 1);

	free(buffer);
	c_f_d_from = close(f_d_from);
	c_f_d_to = close(f_d_to);

	if (c_f_d_from == -1)
		exit_prog("Error: Can't close fd", 100, NULL, f_d_from, 2);
	if (c_f_d_to == -1)
		exit_prog("Error: Can't close fd", 100, NULL, f_d_to, 2);
	return (0);
}

/**
* exit_prog - exits the program with a message
* @message: message to be printed
* @e_code: exit code
* @filename: the filename
* @f_d: the file desccriptor
* @flag: flags, 0-> none, 1-> string, 2 -> int
*
* Return: Always void
*/
void exit_prog(char *message, int e_code, char *filename, int f_d, int flag)
{
	if (flag == 0)
		dprintf(STDERR_FILENO, "%s\n", message);
	else if (flag == 1)
		dprintf(STDERR_FILENO, "%s %s\n", message, filename);
	else if (flag == 2)
		dprintf(STDERR_FILENO, "%s %d\n", message, f_d);

	exit(e_code);
}

/**
* safe_buffer - safely allocate memory
* @filename: the filename
*
* Return: pointer to memory
*/
void *safe_buffer(char *filename)
{
	char *buffer;

	buffer = malloc(sizeof(char) * 1024);

	if (buffer == NULL)
		exit_prog("Error: Can't write to", 99, filename, 0, 1);

	return (buffer);
}
