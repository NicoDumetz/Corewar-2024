/*
** EPITECH PROJECT, 2024
** write_number
** File description:
** write
*/
#include "../include/asm.h"
#include "../include/my.h"
#include "../include/op.h"

int reverse_bytes_int(uint8_t *bytes, int len)
{
    int i;
    uint8_t temp;

    for (i = 0; i < len / 2; i++) {
        temp = bytes[i];
        bytes[i] = bytes[len - i - 1];
        bytes[len - i - 1] = temp;
    }
    return 0;
}

int write_num_file(FILE *file, int num)
{
    unsigned char nbr = (unsigned char)num;

    fwrite(&nbr, sizeof(unsigned char), 1, file);
    return 0;
}

int write_int(FILE *file, int num)
{
    reverse_bytes_int((uint8_t *)&num, sizeof(num));
    fwrite(&num, sizeof(int), 1, file);
    return 0;
}

static char *check_type(char *param)
{
    if (param == NULL)
        return "00";
    if (param[0] == 'r')
        return "01";
    if (param[0] == '%')
        return "10";
    if ((param[0] >= '0' && param[0] <= '9') || param[0] == '-' ||
        param[0] == ':')
        return "11";
    return "00";
}

int write_codingbytes(char *p1, char *p2, char *p3, FILE *file)
{
    char bin[9];
    int dec;

    my_memset(bin, 9);
    my_strcat(bin, check_type(p1));
    my_strcat(bin, check_type(p2));
    my_strcat(bin, check_type(p3));
    my_strcat(bin, "00");
    dec = bin_to_dec(bin);
    write_num_file(file, dec);
    return 0;
}

static int write_register(char *rn, FILE *file)
{
    int reg = my_getnbr(rn + 1);

    write_num_file(file, reg);
    return 0;
}

static int write_direct(FILE *file, char ***command, int i, int j)
{
    int reg = my_getnbr(command[j][i] + 1);
    short reg_short = my_getnbr(command[j][i] + 1);

    if (command[j][i][1] == ':')
        return print_labels(command, i, j, file);
    if (is_2bytes(command[j][0]) || is_2bytes(command[j][1])) {
        reverse_bytes_int((uint8_t *)&reg_short, sizeof(reg_short));
        fwrite(&reg_short, sizeof(reg_short), 1, file);
    } else {
        reverse_bytes_int((uint8_t *)&reg, sizeof(reg));
        fwrite(&reg, sizeof(reg), 1, file);
    }
    return 0;
}

int write_param(char ***command, int i, int j, FILE *file)
{
    short indir;
    short reg_short;

    if (command[j][i][0] == 'r')
        return write_register(command[j][i], file);
    if (command[j][i][0] == '%')
        return write_direct(file, command, i, j);
    if (command[j][i][0] == ':') {
        reg_short = (short)manage_labels(command, i, j, 1);
        reverse_bytes_int((uint8_t *)&reg_short, sizeof(reg_short));
        fwrite(&reg_short, sizeof(reg_short), 1, file);
        return 0;
    }
    indir = (short)my_getnbr(command[j][i]);
    reverse_bytes_int((uint8_t *)&indir, sizeof(indir));
    fwrite(&indir, sizeof(short), 1, file);
    return 0;
}
