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
    GLint v[] = {0, 75, -75, 0, 75, 0};
    glClear(GL_COLOR_BUFFER_BIT);
    glColor3f(1, .3f, .7f);
    glEnableClientState(GL_VERTEX_ARRAY);
    glVertexPointer(2, GL_INT, 0, v);
    glPushMatrix();
    glScalef(.01f, .01f, 1);
    glDrawArrays(GL_TRIANGLES, 0, 3);
    glPopMatrix();
    glDisableClientState(GL_VERTEX_ARRAY);
    glFlush();
}

int main(int c, char **v)
{
    glutInit(&c, v);
    glutInitWindowSize(600, 500);
    glutCreateWindow("RUIZ_PE_05");
    glutDisplayFunc(display);
    glutMainLoop();
    return 0;
}