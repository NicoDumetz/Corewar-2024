/*
** EPITECH PROJECT, 2024
** tab com
** File description:
** tab com
*/

#include "../include/corewar.h"
#include "../include/op.h"
#include "../include/my.h"
#include "stddef.h"
#include <sys/stat.h>

command_t com_tab[] = {
    {"live", live},
    {"ld", ld_cor},
    {"st", stock},
    {"add", add},
    {"sub", sub},
    {"and", and_cor},
    {"or", or_cor},
    {"xor", xor_cor},
    {"zjmp", zjmp},
    {"ldi", ldi},
    {"sti", sti},
    {"fork", fork_cor},
    {"lld", lld},
    {"lldi", lldi},
    {"lfork", lfork_cor},
    {"aff", aff},
    {0, 0}
};
