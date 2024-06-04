/*
** EPITECH PROJECT, 2024
** main
** File description:
** main
*/

#include "include/my.h"
#include "include/corewar.h"
#include "include/op.h"
#include "include/errors.h"


static void error_callback(int , const char* description)
{
    fprintf(stderr, "Error: %s\n", description);
}

static void key_callback(GLFWwindow* window, int key, int , int action, int )
{
    if (key == GLFW_KEY_ESCAPE && action == GLFW_PRESS)
        glfwSetWindowShouldClose(window, GLFW_TRUE);
}

int free_tab(char **argv, int return_value)
{
    for (unsigned char i = 0; argv[i]; i++)
        free(argv[i]);
    free(argv);
    return return_value;
}

static char **copy_argv(int ac, char **argv)
{
    char **copy = NULL;

    if (ac > 15) {
        write(2, TO_MANY_ARGS, my_strlen(TO_MANY_ARGS));
        return NULL;
    }
    copy = malloc((ac + 1) * sizeof(char *));
    if (copy == NULL)
        return NULL;
    for (unsigned char i = 0; i <= ac; i++)
        copy[i] = 0;
    for (unsigned char i = 0; argv[i]; i++) {
        copy[i] = my_strdup(argv[i]);
        if (copy[i] == NULL) {
            free_tab(copy, 0);
            return NULL;
        }
    }
    return copy;
}

int main(int ac, char **av)
{
    GLFWwindow* window;
    corewar_t game;

    av = copy_argv(ac, av);
    if (av == NULL)
        return 84;
    if (check_dump(av, &game))
        return free_tab(av, 84);
    if (init_champ(av, &game))
        return 84;
    if (init_memory(&game)) {
        destroy_allchamps(&game);
        return 84;
    }
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