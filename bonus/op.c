/*
** EPITECH PROJECT, 2024
** opc
** File description:
** opc
*/
#include "include/op.h"

op_t op_tab[] = {
    {"live", 1, {T_DIR}, 1, 10 - 5, "alive"},
    {"ld", 2, {T_DIR | T_IND, T_REG}, 2, 5 - 3, "load"},
    {"st", 2, {T_REG, T_IND | T_REG}, 3, 5 - 2, "store"},
    {"add", 3, {T_REG, T_REG, T_REG}, 4, 10 - 5, "addition"},
    {"sub", 3, {T_REG, T_REG, T_REG}, 5, 10 - 5, "soustraction"},
    {"and", 3, {T_REG | T_DIR | T_IND, T_REG | T_IND | T_DIR, T_REG}, 6, 6 - 3,
        "et (and  r1, r2, r3   r1&r2 -> r3"},
    {"or", 3, {T_REG | T_IND | T_DIR, T_REG | T_IND | T_DIR, T_REG}, 7, 6 - 3,
        "ou  (or   r1, r2, r3   r1 | r2 -> r3"},
    {"xor", 3, {T_REG | T_IND | T_DIR, T_REG | T_IND | T_DIR, T_REG}, 8, 6 - 3,
        "ou (xor  r1, r2, r3   r1^r2 -> r3"},
    {"zjmp", 1, {T_DIR}, 9, 20 - 10, "jump if zero"},
    {"ldi", 3, {T_REG | T_DIR | T_IND, T_DIR | T_REG, T_REG}, 10, 25 - 15,
        "load index"},
    {"sti", 3, {T_REG, T_REG | T_DIR | T_IND, T_DIR | T_REG}, 11, 25 - 15,
        "store index"},
    {"fork", 1, {T_DIR}, 12, 800 - 400, "fork"},
    {"lld", 2, {T_DIR | T_IND, T_REG}, 13, 10, "long load"},

    {"lldi", 3, {T_REG | T_DIR | T_IND, T_DIR | T_REG, T_REG}, 14, 50 - 25,
        "long load index"},
    {"lfork", 1, {T_DIR}, 15, 1000 - 500, "long fork"},
    {"aff", 1, {T_REG}, 16, 2 - 1, "aff"},
    {0, 0, {0}, 0, 0, 0}
};
