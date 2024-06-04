/*
** EPITECH PROJECT, 2024
** draw_rect
** File description:
** draw_rect
*/

#include "include/my.h"
#include "include/corewar.h"
#include "include/op.h"

void draw_rect(float x, float y, int right)
{
    glBegin(GL_QUADS);
    if (right == 0)
        glVertex2f(x, y);
    else
        glVertex2f(x - 200, y);
    if (right == 0) {
        glVertex2f(x + 300.0f, y);
        glVertex2f(x + 300.0f, y + 100.0f);
    } else {
        glVertex2f(x + 100.0f, y);
        glVertex2f(x + 100, y + 100.0f);
    }
    if (right == 0)
        glVertex2f(x, y + 100.0f);
    else
        glVertex2f(x - 200, y + 100.0f);
    glEnd();
}

void manage_profil(void)
{
    GLfloat defaultColor[4];
    int windowWidth = 1900;
    int windowHeight = 1000;

    glMatrixMode(GL_PROJECTION);
    glPushMatrix();
    glLoadIdentity();
    gluOrtho2D(0, windowWidth, 0, windowHeight);
    glMatrixMode(GL_MODELVIEW);
    glPushMatrix();
    glLoadIdentity();
    glGetFloatv(GL_CURRENT_COLOR, defaultColor);
    glColor3f(0.7f, 0.7f, 0.7f);
    draw_rect(0.0f, 0.0f, 0);
    draw_rect(windowWidth - 100.0f, 0.0f, 1);
    draw_rect(windowWidth - 100.0f, windowHeight - 100, 1);
    draw_rect(0.0f, windowHeight - 100, 0);
    glColor4fv(defaultColor);
    glPopMatrix();
    glMatrixMode(GL_PROJECTION);
    glPopMatrix();
    glMatrixMode(GL_MODELVIEW);
}