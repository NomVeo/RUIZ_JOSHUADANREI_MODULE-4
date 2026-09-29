#define GL_SILENCE_DEPRECATION
#ifdef __APPLE__
#include <GLUT/glut.h>
#else
#include <GL/glut.h>
#endif
#include <iostream>
using namespace std;

void display()
{
    GLfloat v[] = {-.6f, .6f, 0, 0, 0, 0, .6f, -.6f, 0, -.6f, -.6f, 0, .6f, .6f, 0};
    glClear(GL_COLOR_BUFFER_BIT);
    glPointSize(15);
    glColor3f(1, 1, 1);
    glEnableClientState(GL_VERTEX_ARRAY);
    glVertexPointer(3, GL_FLOAT, 0, v);
    glDrawArrays(GL_POINTS, 0, 5);
    glDisableClientState(GL_VERTEX_ARRAY);
    glFlush();
}

int main(int c, char **v)
{
    glutInit(&c, v);
    glutInitWindowSize(600, 500);
    glutCreateWindow("RUIZ_PE_01");
    glutDisplayFunc(display);
    glutMainLoop();
    return 0;
}