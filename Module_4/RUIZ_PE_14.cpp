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
    GLfloat v[] = {-.8f, -.7f, 0, -.8f, -.4f, 0, -.4f, -.7f, 0, -.4f, -.1f, 0, 0, -.7f, 0, 0, .2f, 0, .4f, -.7f, 0, .4f, .5f, 0, .8f, -.7f, 0, .8f, .8f, 0};
    GLfloat c[] = {1, 0, 0, 1, 0, 0, 0, 1, 0, 0, 1, 0, 0, 0, 1, 0, 0, 1, 1, 1, 0, 1, 1, 0, 1, 0, 1, 1, 0, 1};
    glClear(GL_COLOR_BUFFER_BIT);
    glEnableClientState(GL_VERTEX_ARRAY);
    glEnableClientState(GL_COLOR_ARRAY);
    glVertexPointer(3, GL_FLOAT, 0, v);
    glColorPointer(3, GL_FLOAT, 0, c);
    glDrawArrays(GL_QUAD_STRIP, 0, 10);
    glDisableClientState(GL_COLOR_ARRAY);
    glDisableClientState(GL_VERTEX_ARRAY);
    glFlush();
}

int main(int c, char **v)
{
    glutInit(&c, v);
    glutInitWindowSize(700, 600);
    glutCreateWindow("RUIZ_PE_14");
    glutDisplayFunc(display);
    glutMainLoop();
    return 0;
}