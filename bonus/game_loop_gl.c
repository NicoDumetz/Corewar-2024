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
    float targetX = (78 - 1) * 2.0f / 2.0f;
    float targetY = 0.0f;
    float targetZ = (78 - 1) * 2.0f / 2.0f;
    float radius = 100.0f;
    float camX = targetX + sin(camera_angle * M_PI / 180.0f) * radius;
    float camY = 50.0f;
    float camZ = targetZ + cos(camera_angle * M_PI / 180.0f) * radius;

    glClearColor(0.1f, 0.1f, 0.1f, 1.0f);
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glLoadIdentity();

    gluLookAt(camX, camY, camZ,
              targetX, targetY, targetZ,
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
