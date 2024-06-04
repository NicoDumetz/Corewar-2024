/*
** EPITECH PROJECT, 2024
** B-CPE-200-LIL-2-1-corewar-matisse.dufour
** File description:
** insert_champ.c
*/

#include "corewar.h"

void insert_champ(champ_t *champ, corewar_t *game)
{
    champ_t *current = game->list;
    champ_t *prev = NULL;

    for (; current && current->index <= champ->index; current = current->next)
        prev = current;
    champ->next = current;
    if (prev)
        prev->next = champ;
    else
        game->list = champ;
}
