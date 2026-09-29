#define GL_SILENCE_DEPRECATION
#ifdef __APPLE__
#include <GLUT/glut.h>
#else
#include <GL/glut.h>
#endif
#include <iostream>

using namespace std;

GLfloat a[] = {-.85f, -.4f, 0, -.35f, -.4f, 0, -.35f, .4f, 0, -.85f, -.4f, 0, -.35f, .4f, 0, -.85f, .4f, 0};
GLfloat e[] = {.35f, -.4f, 0, .85f, -.4f, 0, .85f, .4f, 0, .35f, .4f, 0};
GLubyte i[] = {0, 1, 2, 0, 2, 3};

void display()
{
    glClear(GL_COLOR_BUFFER_BIT);
    glEnableClientState(GL_VERTEX_ARRAY);
    glColor3f(.2f, .7f, 1);
    glVertexPointer(3, GL_FLOAT, 0, a);
    glDrawArrays(GL_TRIANGLES, 0, 6);
    glColor3f(1, .4f, .2f);
    glVertexPointer(3, GL_FLOAT, 0, e);
    glDrawElements(GL_TRIANGLES, 6, GL_UNSIGNED_BYTE, i);
    glDisableClientState(GL_VERTEX_ARRAY);
    glFlush();
}

int main(int c, char **v)
{
    glutInit(&c, v);
    glutInitWindowSize(800, 500);
    glutCreateWindow("RUIZ_PE_16");
    glutDisplayFunc(display);
    glutMainLoop();
    return 0;
}