/*
** EPITECH PROJECT, 2024
** kjfnze
** File description:
** knjze
*/
#include <GL/glut.h>
#include "bonus.h"

void test(unsigned char key, int x, int y) {
    if (key == 'q' || key == 'Q') {
        printf("caca\n");
        exit(0);
    }
    printf("%c\n", key);
}

void drawCube(float x, float y, float z, float size) {
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
        for (int j = 0; j < 78; ++j) {
            x = i * 2.0f;
            z = j * 2.0f;
            drawCube(x, 0, z, 0.5f);
        }
    }
}

void game_loop(void)
{
    float camera_angle = 0.0f;
    float camX;
    float camZ;

    while (1) {
        glClearColor(0.1f, 0.1f, 0.1f, 1.0f);
        glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
        glMatrixMode(GL_PROJECTION);
        glLoadIdentity();
        gluPerspective(60.0f, 1900.0f / 1000.0f, 0.1f, 1000.0f);
        glMatrixMode(GL_MODELVIEW);
        gluPerspective(45.0f, 800.0f / 600.0f, 0.1f, 100.0f);
        glMatrixMode(GL_MODELVIEW);
        glLoadIdentity();
        camX = sin(camera_angle * M_PI / 180.0f) * 20.0f;
        camZ = cos(camera_angle * M_PI / 180.0f) * 20.0f;
        gluLookAt(camX + 50, 50.0f, camZ + 20, 50.0f, 0.0f, 50.0f, 0.0f, 1.0f, 0.0f);
        manage_cube();
        manage_profil();
        manage_img();
        manage_text();
        glutSwapBuffers();
        glutPostRedisplay();
        camera_angle += 0.5f;
    }
}

int main(int argc, char **argv) {
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB);
    glutInitWindowSize(1900, 1000);
    glutCreateWindow("Small bytes Small bytes");
    glutDisplayFunc(game_loop);
    glutKeyboardFunc(test);
    glutMainLoop();
    return 0;
}