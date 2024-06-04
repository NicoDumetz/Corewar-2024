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
    #include "my.h"
    #include "op.h"

union intconverter {
    char bytes[4];
    int value;
};

typedef struct champ_s {
    char *name;
    char *filename;
    int prog_size;
    char *comment;
    char *code;
    char *all;
    int pc;
    int index;
    int reg[15];
    struct champ_s *next;
} champ_t;

typedef struct corewar_s {
    champ_t *list;
    unsigned char board[MEM_SIZE];
    int len_hero;
} corewar_t;

int init_champ(int ac, char **av, corewar_t *game);
void display_memory(corewar_t *game);
void destroy_allchamps(corewar_t *game);
void init_memory(corewar_t *game);
int len_hero(corewar_t *game);
#endif
