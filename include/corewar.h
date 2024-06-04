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

typedef struct param_s {
    int value;
    int size;
    int type;
} param_t;

typedef struct champ_s {
    char *name;
    char *comment;
    char *filename;
    char *code;
    char *all;
    int prog_size;
    int alive;
    int pc;
    int index;
    int reg[REG_NUMBER];
    int carry;
    int cycle_die;
    int wait;
    struct champ_s *next;
} champ_t;

typedef struct corewar_s {
    champ_t *list;
    unsigned char board[MEM_SIZE];
    int len_hero;
    int cycle_die;
    int cycle_delta;
    int nbr_live;
    int dump;
    int last_index;
    char *last_name;
} corewar_t;
typedef struct command_s {
    char *name;
    void (*com)(champ_t *, corewar_t *);
} command_t;
extern command_t com_tab[];
void insert_champ(champ_t *champ, corewar_t *game);
int check_flags(int argc, char **argv, corewar_t *game);
int init_champ(int ac, char **av, corewar_t *game);
void display_memory(corewar_t *game);
void destroy_allchamps(corewar_t *game);
void init_memory(corewar_t *game);
int len_hero(corewar_t *game);
int game_loop(corewar_t *game);
void display_winner(corewar_t *game);
int how_many_are_alive(corewar_t *game);
void add_pc(champ_t *champ, int nbr);
char *my_revstr_convert(char *str);
char *dec_to_octet(unsigned long nb, char *base, int size);
param_t *read_param(int len, char *bin);
void reset_dir(param_t *list);
void live(champ_t *champ, corewar_t *game);
void ld_cor(champ_t *champ, corewar_t *game);
void stock(champ_t *champ, corewar_t *game);
void add(champ_t *champ, corewar_t *game);
void sub(champ_t *champ, corewar_t *game);
void and_cor(champ_t *champ, corewar_t *game);
void or_cor(champ_t *champ, corewar_t *game);
void xor_cor(champ_t *champ, corewar_t *game);
void zjmp(champ_t *champ, corewar_t *game);
void ldi(champ_t *champ, corewar_t *game);
void sti(champ_t *champ, corewar_t *game);
void fork_cor(champ_t *champ, corewar_t *game);
void lld(champ_t *champ, corewar_t *game);
void lldi(champ_t *champ, corewar_t *game);
void lfork_cor(champ_t *champ, corewar_t *game);
void aff(champ_t *champ, corewar_t *game);
void manage_cycle_to_die(corewar_t *game);
void fill_value(champ_t *champ, corewar_t *game, param_t *list, int len);
int value_of_param(champ_t *champ, corewar_t *game, param_t list);
void write_int_to_memory(int value, corewar_t *game, int address);
int read_int_from_memory(corewar_t *game, int address);
void fill_value_except(champ_t *champ, corewar_t *game,
    param_t *list, int len);
param_t *read_param_except(int len, char *bin);
void write_short_to_memory(short value, corewar_t *game, int address);
int check_only_reg(param_t *list);
#endif
