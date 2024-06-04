/*
** EPITECH PROJECT, 2024
** game_loop
** File description:
** game_loop
*/

#include "include/corewar.h"
#include "include/my.h"
#include "include/op.h"

void initialize_scene()
{
    glClearColor(0.1f, 0.1f, 0.1f, 1.0f);
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glLoadIdentity();
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluPerspective(60.0f, 1900.0f / 1000.0f, 0.1f, 1000.0f);
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
}

void render_scene(float camera_angle, corewar_t *game)
{
    float camX = sin(camera_angle * M_PI / 180.0f) * 100.0f; // radius du tour camera
    float camZ = cos(camera_angle * M_PI / 180.0f) * 100.0f;

    glClearColor(0.1f, 0.1f, 0.1f, 1.0f);
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glLoadIdentity();
    gluLookAt(50 + camX, 50.0f, 50 + camZ,    // valeur camera
          100, 0.0f, 100,
          0.0f, 1.0f, 0.0f);
    manage_cube(game);
}

void update_camera(float* camera_angle)
{
    *camera_angle += 0.5f;
}

void handle_events(GLFWwindow* window)
{
    glfwSwapBuffers(window);
    glfwPollEvents();
}
