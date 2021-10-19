#ifndef MAIN_H
#define MAIN_H

#include <fcntl.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <stdio.h>

ssize_t read_textfile(const char *filename, size_t letters);
int create_file(const char *filename, char *text_content);
size_t find_length(char *text);
int append_text_to_file(const char *filename, char *text_content);
void exit_prog(char *message, int e_code, char *filename, int f_d, int flag);
void *safe_buffer(char *filename);

#endif /* MAIN_H */
