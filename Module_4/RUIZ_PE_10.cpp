#define GL_SILENCE_DEPRECATION
#ifdef __APPLE__
#include <GLUT/glut.h>
#else
#include <GL/glut.h>
#endif
#include <iostream>

using namespace std;

GLfloat v[] = {-.8f, -.2f, 0, -.4f, -.2f, 0, 0, -.2f, 0, .4f, -.2f, 0, .8f, -.2f, 0, -.8f, .2f, 0, -.4f, .2f, 0, 0, .2f, 0, .4f, .2f, 0, .8f, .2f, 0};
GLubyte a[] = {0, 1, 6, 5}, b[] = {1, 2, 7, 6}, d[] = {2, 3, 8, 7}, e[] = {3, 4, 9, 8};

void display()
{
    glClear(GL_COLOR_BUFFER_BIT);
    glEnableClientState(GL_VERTEX_ARRAY);
    glVertexPointer(3, GL_FLOAT, 0, v);
    glColor3f(1, 1, 1);
    glDrawElements(GL_QUADS, 4, GL_UNSIGNED_BYTE, a);
    glColor3f(0, 0, 0);
    glDrawElements(GL_QUADS, 4, GL_UNSIGNED_BYTE, b);
    glColor3f(1, 1, 1);
    glDrawElements(GL_QUADS, 4, GL_UNSIGNED_BYTE, d);
    glColor3f(0, 0, 0);
    glDrawElements(GL_QUADS, 4, GL_UNSIGNED_BYTE, e);
    glDisableClientState(GL_VERTEX_ARRAY);
    glFlush();
}

int main(int c, char **v2)
{
    glutInit(&c, v2);
    glutInitWindowSize(700, 400);
    glutCreateWindow("RUIZ_PE_10");
    glutDisplayFunc(display);
    glutMainLoop();
    return 0;
}