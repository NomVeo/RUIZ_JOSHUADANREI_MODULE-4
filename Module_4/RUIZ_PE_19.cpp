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
    GLfloat d[] = {0, .7f, 0, 1, 0, 0, .6f, .35f, 0, 1, .5f, 0, .6f, -.35f, 0, 1, 1, 0, 0, -.7f, 0, 0, 1, 0, -.6f, -.35f, 0, 0, 1, 1, -.6f, .35f, 0, .2f, .3f, 1};
    GLubyte i[] = {0, 1, 2, 3, 4, 5};
    GLsizei s = 6 * sizeof(GLfloat);
    glClear(GL_COLOR_BUFFER_BIT);
    glEnableClientState(GL_VERTEX_ARRAY);
    glEnableClientState(GL_COLOR_ARRAY);
    glVertexPointer(3, GL_FLOAT, s, d);
    glColorPointer(3, GL_FLOAT, s, d + 3);
    glDrawElements(GL_POLYGON, 6, GL_UNSIGNED_BYTE, i);
    glDisableClientState(GL_COLOR_ARRAY);
    glDisableClientState(GL_VERTEX_ARRAY);
    glFlush();
}

int main(int c, char **v)
{
    glutInit(&c, v);
    glutInitWindowSize(600, 600);
    glutCreateWindow("RUIZ_PE_19");
    glutDisplayFunc(display);
    glutMainLoop();
    return 0;
}