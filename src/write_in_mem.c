/*
** EPITECH PROJECT, 2024
** write
** File description:
** write
*/

#include "../include/corewar.h"
#include "../include/op.h"
#include "../include/my.h"
#include "stddef.h"
#include <sys/stat.h>


static int calculate_address(int pc, int offset)
{
    int address = pc + offset;

    if (address < 0)
        address += MEM_SIZE;
    if (address >= MEM_SIZE)
        address %= MEM_SIZE;
    return address;
}

void write_int_to_memory(int value, corewar_t *game, int address)
{
    int byte = 0;
    int addr;

    for (int i = 0; i < 4; i++) {
        byte = (value >> (8 * (3 - i))) & 0xFF;
        addr = calculate_address(address, i);
        game->board[addr] = byte;
    }
}

int read_int_from_memory(corewar_t *game, int address)
{
    int value = 0;
    int byte = 0;

    for (int i = 0; i < 4; i++) {
        byte = game->board[(address + i) % MEM_SIZE];
        value |= byte << (8 * (3 - i));
    }
    return value;
}
