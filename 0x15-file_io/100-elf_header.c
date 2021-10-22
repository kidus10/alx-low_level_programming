#include <stdio.h>
#include <fcntl.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>

void exit_prog(char *message, int e_code, char *filename, int flag);
int check_elf(char *elf_ptr);
void print_magic(char *elf_ptr);
void print_bit(char *elf_ptr);
void print_data(char *elf_ptr);
void print_version(char *elf_ptr);
void print_OS(char *elf_ptr);
void print_ABI(char *elf_ptr);

/**
* main - displays the information contained in the ELF header at the start of an ELF file
* @argc: argument count
* @argv: argument list
*
* Return: Always 0
*/
int main(int argc, char **argv)
{
	int f_d, is_elf;
	char *elf_header;
	ssize_t r_bytes;

	if (argc != 2)
		exit_prog("Usage: elf_header elf_file", 98, NULL, 0);

	elf_header = malloc(sizeof(char) * 64);
	f_d = open(argv[1], O_RDONLY);
	
	if (f_d == -1)
		exit_prog("can't open the file", 98, argv[1], 1);

	r_bytes = read(f_d, elf_header, 64);

	if (r_bytes == -1)
		exit_prog("can't read file", 98, argv[1], 1);

	if (r_bytes < 5)
		exit_prog("is not an ELF file", 98, argv[1], 2);

	is_elf = check_elf(elf_header);

	if (is_elf == 0)
		exit_prog("is not an ELF file", 98, argv[1], 2);
	else
		print_magic(elf_header);

	elf_header = elf_header + 4;

	print_bit(elf_header);
	elf_header = elf_header + 1;

	print_data(elf_header);
	elf_header = elf_header + 1;

	print_version(elf_header);
	elf_header = elf_header + 1;

	print_OS(elf_header);
	elf_header = elf_header + 1;

	print_ABI(elf_header);
	elf_header = elf_header + 1;
	return (0);
}

/**
* exit_prog - exits the program with a message
* @message: message to be printed
* @e_code: exit code
* @filename: the filename
* @f_d: the file desccriptor
* @flag: flags
*
* Return: Always void
*/
void exit_prog(char *message, int e_code, char *filename, int flag)
{
	if (flag == 0)
		dprintf(STDERR_FILENO, "%s\n", message);
	else if (flag == 1)
		dprintf(STDERR_FILENO, "Error: %s %s\n", message, filename);
	else if (flag == 2)
		dprintf(STDERR_FILENO, "Error: %s %s\n", filename, message);
	exit(e_code);
}

/**
* check_elf - checks if it's elf
* @ptr_elf - pointer to the elf header buffer
*
* Return: 1 if file is elf, otherwise 0
*/
int check_elf(char *elf_ptr)
{
	int i;
	char e_h[4] = {0x7F, 0x45, 0x4c, 0x46};

	i = 0;
	while (i < 4)
	{
		if (e_h[i] != *(elf_ptr + i))
			return (0);

		i++;
	}
	return (1);
}

/**
* print_magic - prints the magic of the elf filee
* @elf_ptr: pointer to the elf header
*
* Return: Always void
*/
void print_magic(char *elf_ptr)
{
	int i;

	i = 0;

	printf("Magic:\t");
	while (i < 16)
	{
		printf("%02x", *(elf_ptr + i));

		if (i != 15)
			printf(" ");

		i++;
	}
	printf("\n");
}

void print_bit(char *elf_ptr)
{
	printf("Class:\t");
	if (*elf_ptr == 0x01)
		printf("ELF32");
	else if (*elf_ptr == 0x02)
		printf("ELF64");

	printf("\n");
}

void print_data(char *elf_ptr)
{
	printf("Data:\t");
	if (*elf_ptr == 0x01)
		printf("2's complement, little endian");
	else if (*elf_ptr == 0x02)
		printf("2's complement, little endian, big endian");

	printf("\n");
}

void print_version(char *elf_ptr)
{
	printf("Version:\t");
	if (*elf_ptr == 0x01)
		printf("1 (current)");
	else
		printf("0x%2x", *elf_ptr);

	printf("\n");
}

void print_OS(char *elf_ptr)
{
	char os_abi[18][29] = {"System V", "HP-UX", "NetBSD", "Linux", "GNU Hurd", "Solaris", "AIX", "IRIX", "FreeBSD", "Tru64", "Novell Modesto", "OpenBSD", "OpenVMS", "NonStop Kernel", "AROS", "Fenix OS", "CloudABI", "Stratus Technologies OpenVOS"};
	printf("OS/ABI:\t");

	printf("UNIX - %s", *(os_abi + *elf_ptr));
	printf("\n");
}

void print_ABI(char *elf_ptr)
{
	printf("ABI:\t");
	
	printf("%d", *elf_ptr);
	printf("\n");
}
