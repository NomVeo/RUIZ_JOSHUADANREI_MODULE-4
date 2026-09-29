#define GL_SILENCE_DEPRECATION
#ifdef __APPLE__
#include <GLUT/glut.h>
#else
#include <GL/glut.h>
#endif
#include <iostream>

using namespace std;

GLfloat v[] = {0, 0, 0, -.5f, .1f, 0, -.5f, -.1f, 0, .5f, .1f, 0, .5f, -.1f, 0, -.1f, .5f, 0, .1f, .5f, 0, -.1f, -.5f, 0, .1f, -.5f, 0};
GLfloat c[] = {1, 1, 1, 1, 0, 0, 0, 1, 0, 0, 0, 1, 1, 1, 0, 1, 0, 1, 0, 1, 1, 1, .5f, 0, .5f, 0, 1};
GLubyte i[] = {0, 1, 2, 0, 3, 4, 0, 5, 6, 0, 7, 8};

void display()
{
    glClear(GL_COLOR_BUFFER_BIT);
    glEnableClientState(GL_VERTEX_ARRAY);
    glEnableClientState(GL_COLOR_ARRAY);
    glVertexPointer(3, GL_FLOAT, 0, v);
    glColorPointer(3, GL_FLOAT, 0, c);
    glDrawElements(GL_TRIANGLES, 12, GL_UNSIGNED_BYTE, i);
    glDisableClientState(GL_COLOR_ARRAY);
    glDisableClientState(GL_VERTEX_ARRAY);
    glFlush();
}

int main(int x, char **y)
{
    glutInit(&x, y);
    glutInitWindowSize(600, 600);
    glutCreateWindow("RUIZ_PE_13");
    glutDisplayFunc(display);
    glutMainLoop();
    return 0;
}