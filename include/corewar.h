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
    #include <stdbool.h>
    #include "my.h"
    #include "op.h"
    #define HELP1 "USAGE\n./corewar [-dump nbr_cycle] [[-n prog_number] "
    #define HELP2 "[-a load_adress] prog_name] ...\n"
    #define HELP3 "DESCRIPTION\n-dump nbr_cycle dump the memory after the "
    #define HELP4 "nbr_cycle execution (if the round isn't already over) with "
    #define HELP5 "the following format: 32 bytes/line in hexadecimal\n"
    #define HELP6 "-n prog_number sets the next program's number. By default, "
    #define HELP7 "the first free number in the parameter order\n"
    #define HELP8 "-a load_adress sets the next program's loading adress. When"
    #define HELP9 " no adress is specified, optimize the adresses so that the "
    #define HELP10 "processes are as far away from each other as possible."
    #define HELP11 HELP10 "The adresses are MEM_SIZE modulo.\n"
    #define HELP HELP1 HELP2 HELP3 HELP4 HELP5 HELP6 HELP7 HELP8 HELP9 HELP11


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
int set_pc_champ(corewar_t *game);
int free_tab(char **argv, int return_value);
int fetch_options(char **argv, unsigned char *i, champ_t *new,
    corewar_t *game);
void insert_champ(champ_t *champ, corewar_t *game);
bool is_num(char *str);
int check_dump(char **argv, corewar_t *game);
int init_champ(char **av, corewar_t *game);
void display_memory(corewar_t *game);
void destroy_allchamps(corewar_t *game);
int init_memory(corewar_t *game);
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
int check_reg(param_t *list);
int check_var_ld(param_t *list);
void copy_of_champ(champ_t *champ, champ_t *new);
int fill_types_except(param_t *list, int i, char *bin, int ind);
#endif
