/*
** EPITECH PROJECT, 2024
** asm header
** File description:
** header
*/

#ifndef MY_NAVY_HEADER
    #define MY_NAVY_HEADER
    #define ABS(x) (((x) < 0) ? -(x) : (x))
    #include <signal.h>
    #include <unistd.h>
    #include <stdio.h>
    #include <stdarg.h>
    #include <stdlib.h>
    #include <fcntl.h>
    #include <errno.h>
    #include <stdint.h>
    #include <stddef.h>
    #include <wchar.h>
char *my_memset(char *str, int size);
FILE *write_header(char **name, char **comment, char *filename, int size);
int get_board_size(char *str);
void free_board(char ***command);
void assign_line(char ***command, char *str, int *i);
int write_command(FILE *file, char ***command, int from);
char *int_to_str(int nb);
int write_num_file(FILE *file, int num);
char *my_convert(unsigned long nb, char *base);
int write_codingbytes(char *p1, char *p2, char *p3, FILE *file);
int bin_to_dec(const char *bin);
int write_param(char ***command, int i, int j, FILE *file);
int manage_labels(char ***command, int i, int j, int dec);
int is_2bytes(char *instruction);
int print_labels(char ***command, int i, int j, FILE *file);
int reverse_bytes_int(uint8_t *bytes, int len);
int errors_handling(char ***command, int *from);
int get_size(char ***command, int from);
int write_int(FILE *file, int num);
#endif
