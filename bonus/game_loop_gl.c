/*
** EPITECH PROJECT, 2024
** game_loop
** File description:
** game_loop
*/

#include "include/bonus.h"

static void initialize_scene()
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

static void render_scene(float camera_angle)
{
    float camX = sin(camera_angle * M_PI / 180.0f) * 20.0f;
    float camZ = cos(camera_angle * M_PI / 180.0f) * 20.0f;

    glClearColor(0.1f, 0.1f, 0.1f, 1.0f);
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glLoadIdentity();
    gluLookAt(camX + 50, 50.0f, camZ + 20, 50.0f, 0.0f, 50.0f, 0.0f, 1.0f, 0.0f);
    manage_cube();
}

static void update_camera(float* camera_angle) {
    *camera_angle += 0.5f;
}

void handle_events(GLFWwindow* window) {
    glfwSwapBuffers(window);
    glfwPollEvents();
}

void game_loop(GLFWwindow* window) {
    float camera_angle = 0.0f;

    while (!glfwWindowShouldClose(window)) {
        initialize_scene();
        render_scene(camera_angle);
        handle_events(window);
        update_camera(&camera_angle);
    }
}
