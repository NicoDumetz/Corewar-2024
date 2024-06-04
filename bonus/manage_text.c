/*
** EPITECH PROJECT, 2024
** manage text
** File description:
** managet etx
*/

#include "bonus.h"

void create_text(char *msg, float posx, float posy)
{
    char strMsg[100] = {0};

    glPushMatrix();
    glLoadIdentity();
    glRasterPos3f(posx, posy, -5.0f);
    sprintf(strMsg, "%s", msg);
    for (unsigned int i = 0; i < strlen(strMsg); i++)
        glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18, strMsg[i]);

    glPopMatrix();
}

void manage_text(void)
{
    create_text("champ 1", -4.9f, 2.7f);
    create_text("champ 2", 4.2f, 2.7f);
    create_text("champ 3", -4.9f, -2.5f);
    create_text("champ 4", 4.2f, -2.5f);
}