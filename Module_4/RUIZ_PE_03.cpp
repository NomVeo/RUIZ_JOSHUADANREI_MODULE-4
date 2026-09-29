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
    GLfloat v[] = {-.8f, .5f, 0, .8f, .5f, 0, -.8f, -.5f, 0, .8f, -.5f, 0};
    glClear(GL_COLOR_BUFFER_BIT);
    glColor3f(1, 1, 0);
    glLineWidth(5);
    glEnableClientState(GL_VERTEX_ARRAY);
    glVertexPointer(3, GL_FLOAT, 0, v);
    glDrawArrays(GL_LINES, 0, 4);
    glDisableClientState(GL_VERTEX_ARRAY);
    glFlush();
}

int main(int c, char **v)
{
    glutInit(&c, v);
    glutInitWindowSize(600, 500);
    glutCreateWindow("RUIZ_PE_03");
    glutDisplayFunc(display);
    glutMainLoop();
    return 0;
}