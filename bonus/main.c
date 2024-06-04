/*
** EPITECH PROJECT, 2024
** main
** File description:
** main
*/

#include "include/my.h"
#include "include/corewar.h"
#include "include/op.h"


static void error_callback(int , const char* description)
{
    fprintf(stderr, "Error: %s\n", description);
}

static void key_callback(GLFWwindow* window, int key, int , int action, int )
{
    if (key == GLFW_KEY_ESCAPE && action == GLFW_PRESS)
        glfwSetWindowShouldClose(window, GLFW_TRUE);
}

int main(int ac, char **av)
{
    GLFWwindow* window;
    corewar_t game;

    if (check_flags(ac, av, &game))
        return 84;
    if (init_champ(ac, av, &game) == 84)
        return 84;
    init_memory(&game);
    glfwSetErrorCallback(error_callback);
    if (!glfwInit())
        exit(EXIT_FAILURE);
    window = glfwCreateWindow(1900, 1000, "Small bytes", NULL, NULL);
    if (!window) {
        glfwTerminate();
        exit(EXIT_FAILURE);
    }
    glfwMakeContextCurrent(window);
    glfwSwapInterval(1);
    glfwSetKeyCallback(window, key_callback);
    game_loop(&game, window);
    glfwDestroyWindow(window);
    glfwTerminate();
    destroy_allchamps(&game);
    exit(EXIT_SUCCESS);
}