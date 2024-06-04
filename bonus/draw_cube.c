/*
** EPITECH PROJECT, 2024
** draw_cube
** File description:
** draw_cube
*/
#include "include/my.h"
#include "include/corewar.h"
#include "include/op.h"

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

void manage_cube(corewar_t *game)
{
    float x;
    float z;
    int ind = 0;
    GLfloat defaultColor[4];
    glGetFloatv(GL_CURRENT_COLOR, defaultColor);



    for (int i = 0; i < 78; ++i) {
        for (int p = 0; p < 78; ++p) {
            if (game->board[ind].index == -1)
                glColor3f(1.0f, 1.0f, 1.0f); // blanc
            else if (game->board[ind].index == 1)
                glColor3f(1.0f, 0.0f, 0.0f); // rouge
            else if (game->board[ind].index == 2)
                glColor3f(0.0f, 1.0f, 0.0f); // vert
            else if (game->board[ind].index == 3)
                glColor3f(0.0f, 1.0f, 1.0f); // cyan
            else if (game->board[ind].index == 4)
                glColor3f(0.5f, 0.0f, 0.5f); // violet


            x = i * 2.0f;
            z = p * 2.0f;
            draw_cube(x, 0, z, 0.5f);
            ind++;
        }
    }
    glColor4fv(defaultColor);
}
