#define GL_SILENCE_DEPRECATION
#ifdef __APPLE__
#include <GLUT/glut.h>
#else
#include <GL/glut.h>
#endif
#include <iostream>

using namespace std;

GLfloat g[] = {-1, -.8f, 0, 1, -.8f, 0, 1, -1, 0, -1, -1, 0};
GLfloat m[] = {-.9f, -.8f, 0, -.3f, .2f, 0, .2f, -.8f, 0, 0, -.8f, 0, .5f, .4f, 0, .9f, -.8f, 0};
GLfloat s[] = {.55f, .55f, 0, .55f, .75f, 0, .69f, .69f, 0, .75f, .55f, 0, .69f, .41f, 0, .55f, .35f, 0, .41f, .41f, 0, .35f, .55f, 0, .41f, .69f, 0};
GLubyte i[] = {0, 1, 2, 0, 2, 3, 0, 3, 4, 0, 4, 5, 0, 5, 6, 0, 6, 7, 0, 7, 8, 0, 8, 1};

void display()
{
    glClear(GL_COLOR_BUFFER_BIT);
    glEnableClientState(GL_VERTEX_ARRAY);
    glColor3f(.2f, .7f, .2f);
    glVertexPointer(3, GL_FLOAT, 0, g);
    glDrawArrays(GL_QUADS, 0, 4);
    glColor3f(.4f, .4f, .4f);
    glVertexPointer(3, GL_FLOAT, 0, m);
    glDrawArrays(GL_TRIANGLES, 0, 6);
    glColor3f(1, .8f, 0);
    glVertexPointer(3, GL_FLOAT, 0, s);
    glDrawElements(GL_TRIANGLES, 24, GL_UNSIGNED_BYTE, i);
    glDisableClientState(GL_VERTEX_ARRAY);
    glFlush();
}

int main(int c, char **v)
{
    glutInit(&c, v);
    glutInitWindowSize(800, 600);
    glutCreateWindow("RUIZ_PE_15");
    glutDisplayFunc(display);
    glutMainLoop();
    return 0;
}