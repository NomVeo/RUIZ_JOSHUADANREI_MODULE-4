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
    GLfloat v[] = {0, .7f, 0, -.7f, -.5f, 0, .7f, -.5f, 0};
    GLfloat c[] = {1, 0, 0, 0, 1, 0, 0, 0, 1};
    glClear(GL_COLOR_BUFFER_BIT);
    glEnableClientState(GL_VERTEX_ARRAY);
    glEnableClientState(GL_COLOR_ARRAY);
    glVertexPointer(3, GL_FLOAT, 0, v);
    glColorPointer(3, GL_FLOAT, 0, c);
    glDrawArrays(GL_TRIANGLES, 0, 3);
    glDisableClientState(GL_COLOR_ARRAY);
    glDisableClientState(GL_VERTEX_ARRAY);
    glFlush();
}

int main(int c, char **v)
{
    glutInit(&c, v);
    glutInitWindowSize(600, 500);
    glutCreateWindow("RUIZ_PE_07");
    glutDisplayFunc(display);
    glutMainLoop();
    return 0;
}