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
    GLfloat v[] = {-.8f, .6f, 0, -.95f, .2f, 0, -.65f, .2f, 0, 0, .6f, 0, -.15f, .2f, 0, .15f, .2f, 0, .8f, .6f, 0, .65f, .2f, 0, .95f, .2f, 0};
    glClear(GL_COLOR_BUFFER_BIT);
    glColor3f(.2f, .8f, .4f);
    glEnableClientState(GL_VERTEX_ARRAY);
    glVertexPointer(3, GL_FLOAT, 0, v);
    glDrawArrays(GL_TRIANGLES, 0, 9);
    glDisableClientState(GL_VERTEX_ARRAY);
    glFlush();
}

int main(int c, char **v)
{
    glutInit(&c, v);
    glutInitWindowSize(700, 500);
    glutCreateWindow("RUIZ_PE_08");
    glutDisplayFunc(display);
    glutMainLoop();
    return 0;
}