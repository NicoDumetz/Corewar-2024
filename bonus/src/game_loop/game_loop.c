/*
** EPITECH PROJECT, 2024
** game_loop
** File description:
** game_loop
*/

#include "../../include/corewar.h"
#include "../../include/op.h"
#include "../../include/my.h"
#include "stddef.h"
#include <sys/stat.h>

void add_pc(champ_t *champ, int nbr)
{
    int add = nbr > 0 ? 1 : -1;
    int stop = nbr < 0 ? nbr * -1 : nbr;

    for (int i = 0; i < stop; i++) {
        champ->pc += add;
        if (champ->pc >= MEM_SIZE)
            champ->pc = 0;
        if (champ->pc < 0)
            champ->pc = MEM_SIZE - 1;
    }
}

char *which_command(champ_t *champ, corewar_t *game)
{
    for (int i = 0; op_tab[i].code; i++) {
        if (game->board[champ->pc].c == op_tab[i].code && champ->wait == 0)
            return op_tab[i].mnemonique;
        if (game->board[champ->pc].c == op_tab[i].code && champ->wait <= -1) {
            champ->wait = op_tab[i].nbr_cycles - 1;
            return NULL;
        }
    }
    return NULL;
}

void execute_champion(champ_t *champ, corewar_t *game)
{
    char *command = NULL;

    champ->wait--;
    champ->cycle_die--;
    command = which_command(champ, game);
    if (command == NULL) {
        if (champ->wait <= -1)
            add_pc(champ, 1);
        return;
    }
    for (int i = 0; com_tab[i].name; i++) {
        if (my_strcmp(command, com_tab[i].name) == 0) {
            com_tab[i].com(champ, game);
        }
    }
    return;
}

static int in_game(corewar_t *game, int *cycle)
{
    champ_t *champ = NULL;
    if (*cycle == game->dump) {
        display_memory(game);
        return 0;
    }
    champ = game->list;
    for (; champ; champ = champ->next) {
        if (champ->alive == 1)
            execute_champion(champ, game);
    }
    manage_cycle_to_die(game);
    *cycle += 1;
    return 1;
}


// float camera_angle = 0.0f;

//     while (!glfwWindowShouldClose(window)) {
//         initialize_scene();
//         render_scene(camera_angle);
//         handle_events(window);
//         update_camera(&camera_angle);
//     }

int game_loop(corewar_t *game, GLFWwindow *window)
{
    int cycle = 0;
    float camera_angle = 0.0f;

    while (how_many_are_alive(game) > 1 || !glfwWindowShouldClose(window)) {
        if (in_game(game, &cycle) == 0)
            return 0;
        initialize_scene();
        render_scene(camera_angle, game);
        handle_events(window);
        update_camera(&camera_angle);
    }
    display_winner(game);
    return 0;
}
