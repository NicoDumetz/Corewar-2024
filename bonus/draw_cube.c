/*
** EPITECH PROJECT, 2024
** draw_cube
** File description:
** draw_cube
*/
#include "include/bonus.h"


void draw_cube(float x, float y, float z, float size)
{
    glBegin(GL_QUADS);
    glVertex3f(x - size, y - size, z + size);
    glVertex3f(x + size, y - size, z + size);
    glVertex3f(x + size, y + size, z + size);
    glVertex3f(x - size, y + size, z + size);

    glVertex3f(x - size, y - size, z - size);
    glVertex3f(x - size, y + size, z - size);
    glVertex3f(x + size, y + size, z - size);
    glVertex3f(x + size, y - size, z - size);

    glVertex3f(x - size, y - size, z - size);
    glVertex3f(x - size, y - size, z + size);
    glVertex3f(x - size, y + size, z + size);
    glVertex3f(x - size, y + size, z - size);

    glVertex3f(x + size, y - size, z - size);
    glVertex3f(x + size, y + size, z - size);
    glVertex3f(x + size, y + size, z + size);
    glVertex3f(x + size, y - size, z + size);

    glVertex3f(x - size, y + size, z - size);
    glVertex3f(x - size, y + size, z + size);
    glVertex3f(x + size, y + size, z + size);
    glVertex3f(x + size, y + size, z - size);

    glVertex3f(x - size, y - size, z - size);
    glVertex3f(x + size, y - size, z - size);
    glVertex3f(x + size, y - size, z + size);
    glVertex3f(x - size, y - size, z + size);
    glEnd();
}

void manage_cube(void)
{
    float x;
    float z;

    for (int i = 0; i < 78; ++i) {
        for (int p = 0; p < 78; ++p) {
            x = i * 2.0f;
            z = p * 2.0f;
            draw_cube(x, 0, z, 0.5f);
        }
    }
}
