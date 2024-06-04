/*
** EPITECH PROJECT, 2024
** display
** File description:
** display
*/

#include "../include/corewar.h"
#include "../include/op.h"
#include "../include/my.h"
#include "stddef.h"
#include <sys/stat.h>

void display_memory(corewar_t *game)
{
    int k = 0;
    int pos = 0;

    for (int j = 0; j < MEM_SIZE / 32; j++) {
        my_printf("%X\t:", pos);
        for (int i = 0; i < 32; i++) {
            my_printf(" %02.2X", game->board[k].c);
            k++;
        }
        pos += 32;
        my_printf("\n");
    }
}
