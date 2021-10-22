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
void print_type(char *elf_ptr);
void print_entry(char *elf_ptr);

/**
* main - displays the information contained in the ELF \
* header at the start of an ELF file
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

	close(f_d);

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
	elf_header = elf_header + 8;

	print_type(elf_header);
	elf_header = elf_header + 8;

	print_entry(elf_header);

	free(elf_header - 24);
	return (0);
}

/**
* exit_prog - exits the program with a message
* @message: message to be printed
* @e_code: exit code
* @filename: the filename
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
* @elf_ptr: pointer to the elf header buffer
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

	printf("ELF Header:\n");
	printf("  %-9s", "Magic:");
	while (i < 16)
	{
		printf("%02x", *(elf_ptr + i));

		if (i != 15)
			printf(" ");

		i++;
	}
	printf("\n");
}

/**
* print_bit - prints the bit (32 or 64 bit)
* @elf_ptr: pointer to the elf header
*
* Return: Always void
*/
void print_bit(char *elf_ptr)
{
	printf("  %-35s", "Class:");
	if (*elf_ptr == 0x01)
		printf("ELF32\n");
	else if (*elf_ptr == 0x02)
		printf("ELF64\n");
}

/**
* print_data - prints the endian (little or big)
* @elf_ptr: pointer to the elf header
*
* Return: Always void
*/
void print_data(char *elf_ptr)
{
	printf("  %-35s", "Data:");
	if (*elf_ptr == 0x01)
		printf("2's complement, little endian\n");
	else if (*elf_ptr == 0x02)
		printf("2's complement, big endian\n");
}

/**
* print_version - prints the version of the file
* @elf_ptr: pointer to the elf header
*
* Return: Always void
*/
void print_version(char *elf_ptr)
{
	printf("  %-35s", "Version:");
	if (*elf_ptr == 0x01)
		printf("1 (current)\n");
	else
		printf("0x%2x\n", *elf_ptr);
}

/**
* print_OS - prints the OS
* @elf_ptr: pointer to the elf header
*
* Return: Always void
*/
void print_OS(char *elf_ptr)
{
	char os_abi[18][29] = {"System V", "HP-UX", "NetBSD",
		"Linux", "GNU Hurd", "Solaris", "AIX", "IRIX",
		"FreeBSD", "Tru64", "Novell Modesto", "OpenBSD",
		"OpenVMS", "NonStop Kernel", "AROS", "Fenix OS",
		"CloudABI", "Stratus Technologies OpenVOS"};

	printf("  %-35s", "OS/ABI:");
	printf("UNIX - %s\n", *(os_abi + *elf_ptr));
}

/**
* print_ABI - prints the ABI value
* @elf_ptr: pointer to the elf header
*
* Return: Always void
*/
void print_ABI(char *elf_ptr)
{
	printf("  %-35s", "ABI Version:");
	printf("%d\n", *elf_ptr);
}

/**
* print_type - prints the type of the file
* @elf_ptr: pointer to the elf header
*
* Return: Always void
*/
void print_type(char *elf_ptr)
{
	char e_types[5][25] = {"NONE (Unknown file)",
		"REL (Relocatable file)",
		"EXEC (Executable file)",
		"DYN (Shared object file)",
		"CORE (Core file)"};

	printf("  %-35s", "Type:");
	printf("%s\n", *(e_types + *elf_ptr));
}

/**
* print_entry - prints the entry point
* @elf_ptr: pointer to the elf header
*
* Return: Always void
*/
void print_entry(char *elf_ptr)
{
	int i;

	i = 0;

	printf("  %-35s", "Entry point address:");
	printf("0x");
	while (i < 3)
	{
		if (*(elf_ptr + i) < 10)
			printf("0%x", *(elf_ptr + i));
		else
			printf("%x", *(elf_ptr + i));
		i++;
	}
	printf("\n");
}
