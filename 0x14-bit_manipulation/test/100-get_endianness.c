#include "main.h"
/**
* get_endianness - determines if the system is big endian or little endian
*
* Return: 0 if big endian, 1 if little endian
*/
int get_endianness(void)
{
	char *str, *k_ptr;

	str = "KW";
	k_ptr = str;

	return ((*k_ptr == 'K') ? 0 : 1);
} 
