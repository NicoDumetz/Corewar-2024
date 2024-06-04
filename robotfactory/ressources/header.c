/*
** EPITECH PROJECT, 2024
** header
** File description:
** header file
*/
#include "../include/asm.h"
#include "../include/my.h"
#include "../include/op.h"

static int write_name(char **name, FILE *file)
{
    unsigned char magic[] = {0x00, 0xea, 0x83, 0xf3};
    char name_ent[132];

    my_memset(name_ent, 132);
    my_strcpy(name_ent, name[1]);
    name_ent[0] = name_ent[0] == 10 ? 0 : name_ent[0];
    if (fwrite(magic, sizeof(unsigned char), sizeof(magic),
        file) != sizeof(magic) || fwrite(name_ent, sizeof(char),
        sizeof(name_ent), file) != sizeof(name_ent)) {
        write(2, "error in namie write name\n", 26);
        return 84;
    }
    return 0;
}

static int write_comment(char **comment, FILE *file, int size)
{
    char comment_ent[2052];

    my_memset(comment_ent, 2052);
    if (comment == 0 || my_strcmp(comment[0], ".comment") != 0) {
        if (write_int(file, size) == -1 || fwrite(comment_ent, sizeof(char),
        sizeof(comment_ent), file) != sizeof(comment_ent)) {
            write(2, "error in comment write comment 1\n", 28);
            return 84;
        }
        return 0;
    }
    my_strcpy(comment_ent, comment[1]);
    if (comment_ent[0] == '\n')
        comment_ent[0] = '\0';
    if (write_int(file, size) == -1 || fwrite(comment_ent, sizeof(char),
        sizeof(comment_ent), file) != sizeof(comment_ent)) {
        write(2, "error in comment write comment\n", 26);
        return 84;
    }
    return 0;
}

static char *clear_slash(char *str)
{
    char *src;
    char *dst;

    if (str == NULL || my_strlen(str) < 2)
        return str;
    if (my_strncmp(str, "./", 2) == 0) {
        src = str + 2;
        dst = str;
        for (; *src != '\0';) {
            *dst = *src;
            ++src;
            ++dst;
        }
        *dst = '\0';
    }
    return str;
}

FILE *write_header(char **name, char **comment, char *filename, int size)
{
    FILE *file;
    int slash = -1;
    char path[1024];

    my_memset(path, 1024);
    filename = clear_slash(filename);
    for (int i = 0; filename[i] != '.'; i++)
        path[i] = filename[i];
    my_strcat(path, ".cor");
    for (int i = 0; path[i]; i++)
        slash = (path[i] == '/') ? i : slash;
    my_strcpy(path, path + slash + 1);
    file = fopen(path, "w");
    if (file == NULL)
        return NULL;
    if (write_name(name, file) == -1 || write_comment(comment,
        file, size) == -1)
        return NULL;
    return file;
}
