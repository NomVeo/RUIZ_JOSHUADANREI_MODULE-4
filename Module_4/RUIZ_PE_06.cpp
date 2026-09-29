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
    GLubyte i[] = {2, 0, 1};
    glClear(GL_COLOR_BUFFER_BIT);
    glColor3f(.3f, 1, .3f);
    glEnableClientState(GL_VERTEX_ARRAY);
    glVertexPointer(3, GL_FLOAT, 0, v);
    glDrawElements(GL_TRIANGLES, 3, GL_UNSIGNED_BYTE, i);
    glDisableClientState(GL_VERTEX_ARRAY);
    glFlush();
}

int main(int c, char **v)
{
    glutInit(&c, v);
    glutInitWindowSize(600, 500);
    glutCreateWindow("RUIZ_PE_06");
    glutDisplayFunc(display);
    glutMainLoop();
    return 0;
}