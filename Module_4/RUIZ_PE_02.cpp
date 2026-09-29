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
    GLfloat v[] = {0, .7f, 0, .6f, .35f, 0, .6f, -.35f, 0, 0, -.7f, 0, -.6f, -.35f, 0, -.6f, .35f, 0};
    glClear(GL_COLOR_BUFFER_BIT);
    glColor3f(.2f, .7f, 1);
    glEnableClientState(GL_VERTEX_ARRAY);
    glVertexPointer(3, GL_FLOAT, 0, v);
    glDrawArrays(GL_POLYGON, 0, 6);
    glDisableClientState(GL_VERTEX_ARRAY);
    glFlush();
}

int main(int c, char **v)
{
    glutInit(&c, v);
    glutInitWindowSize(600, 500);
    glutCreateWindow("RUIZ_PE_02");
    glutDisplayFunc(display);
    glutMainLoop();
    return 0;
}