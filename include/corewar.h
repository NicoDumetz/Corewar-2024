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
    int alive;
    int prog_size;
    char *comment;
    char *code;
    char *all;
    int pc;
    int index;
    int reg[REG_NUMBER];
    int carry;
    struct champ_s *next;
} champ_t;

typedef struct corewar_s {
    champ_t *list;
    unsigned char board[MEM_SIZE];
    int len_hero;
} corewar_t;
typedef struct command_s {
    char *name;
    void (*com)(champ_t *, corewar_t *);
} command_t;

int init_champ(int ac, char **av, corewar_t *game);
void display_memory(corewar_t *game);
void destroy_allchamps(corewar_t *game);
void init_memory(corewar_t *game);
int len_hero(corewar_t *game);
int game_loop(corewar_t *game);
void display_winner(corewar_t *game);
void live(champ_t *champ, corewar_t *game);
int how_many_are_alive(corewar_t *game);
void add_pc(champ_t *champ, int nbr);
#endif
