/*
** EPITECH PROJECT, 2023
** my_printf.h
** File description:
** header to include usefull data or prototypes functions
*/

#ifndef MY_PRINTF
    #define MY_PRINTF
    #include <unistd.h>
    #include <stdio.h>
    #include <stdarg.h>
    #include <stdlib.h>
    #include <fcntl.h>
    #include <errno.h>
    #include <stdint.h>
    #include <stddef.h>
    #include <wchar.h>
typedef int(*fonc_t)();
typedef struct disp {
    char c;
    fonc_t f;
} disp_t;
long my_print_nbr(long nb);
int my_intlen(long nb);
int print_int(va_list list, int *compt, int *list_flagscompt);
int print_char(va_list list, int *compt, int *list_flagscompt);
int print_str(va_list list, int *compt, int *list_flagscompt);
int print_mod(va_list list, int *compt, int *list_flagscompt);
int my_printf(const char *format, ...);
int my_put_float(long double nb, int precision);
int print_float(va_list list, int *compt, int *list_flagscompt);
char *my_put_convert_base(unsigned long nb, char *base);
int print_oct(va_list list, int *compt, int *list_flagscompt);
int print_dec(va_list list, int *compt, int *list_flagscompt);
int print_hex(va_list list, int *compt, int *list_flagscompt);
int print_hex_maj(va_list list, int *compt, int *list_flagscompt);
int print_science(va_list list, int *compt, int *list_flagscompt);
int my_put_sci_nbr(long double nb, int upper, int precision);
int print_hex(va_list list, int *compt, int *list_flagscompt);
int print_adresse(va_list list, int *compt, int *list_flagscompt);
char *my_put_convert_base_ptr(unsigned long long nb, char *base);
int print_science_lowercase(va_list list, int *compt, int *list_flagscompt);
int print_science_uppercase(va_list list, int *compt, int *list_flagscompt);
int print_compt(va_list list, int *compt, int *list_flagscompt);
int print_g(va_list list, int *compt, int *list_flagscompt);
int point_g(long double nb, int precision, int upper);
int my_gotnbr(char const *str);
int my_putstr_prec(char const *str, int precision);
long my_putnbr_prec(long nb, int precision);
char *my_put_convert_base_prec(unsigned long nb, char *base, int precision);
int print_g_maj(va_list list, int *compt, int *list_flagscompt);
long check_int(va_list list, int *list_flagscompt);
unsigned long check_int_u(va_list list, int *list_flagscompt);
long double check_float(va_list list, int *flagscompt);
void check_flags_float(long double nb, int *compt, int *list_flagscompt);
int point_a(double nb, int precision, char *base);
int print_a(va_list list, int *compt, int *list_flagscompt);
int print_a_maj(va_list list, int *compt, int *list_flagscompt);
int print_bin(va_list list, int *compt, int *list_flagscompt);
int error_handling(char const *format);
int fatal_error_handling(char const *format);
int print_bin_maj(va_list list, int *compt, int *list_flagscompt);
int science_precision(long double nb, double precision);
int get_expos(long double nb);
static const disp_t fonc_list[] = {
    {'d', &print_int},
    {'i', &print_int},
    {'s', &print_str},
    {'c', &print_char},
    {'%', &print_mod},
    {'f', &print_float},
    {'o', &print_oct},
    {'u', &print_dec},
    {'x', &print_hex},
    {'X', &print_hex_maj},
    {'e', &print_science_lowercase},
    {'E', &print_science_uppercase},
    {'p', &print_adresse},
    {'n', &print_compt},
    {'g', &print_g},
    {'G', &print_g_maj},
    {'F', &print_float},
    {'a', &print_a},
    {'A', &print_a_maj},
    {'b', &print_bin},
    {'B', &print_bin_maj},
    {0, NULL}
};

static const char list_flags[] = {'#', '0', '-', ' ', '+', 0};
static const char list_modi[] = {'h', 'l', 'j', 'z', 't', 'L', 'q', 0};
#endif
