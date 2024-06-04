/*
** EPITECH PROJECT, 2024
** rev bytes
** File description:
** inverser les bytes
*/
#include "../include/asm.h"
#include "../include/my.h"
#include "../include/op.h"

void reverse_bytes(uint8_t *bytes, int len)
{
    int i;
    uint8_t temp;

    for (i = 0; i < len / 2; i++) {
        temp = bytes[i];
        bytes[i] = bytes[len - i - 1];
        bytes[len - i - 1] = temp;
    }
}
