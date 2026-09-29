#define GL_SILENCE_DEPRECATION
#ifdef __APPLE__
#include <GLUT/glut.h>
#else
#include <GL/glut.h>
#endif
#include <iostream>

using namespace std;

int shape = 1;
GLfloat t[] = {0, .7f, 0, -.7f, -.5f, 0, .7f, -.5f, 0}, q[] = {-.5f, -.5f, 0, .5f, -.5f, 0, .5f, .5f, 0, -.5f, .5f, 0}, p[] = {0, .7f, 0, .67f, .22f, 0, .41f, -.57f, 0, -.41f, -.57f, 0, -.67f, .22f, 0};

void display()
{
    glClear(GL_COLOR_BUFFER_BIT);
    glEnableClientState(GL_VERTEX_ARRAY);
    if (shape == 1)
    {
        glColor3f(1, .2f, .2f);
        glVertexPointer(3, GL_FLOAT, 0, t);
        glDrawArrays(GL_TRIANGLES, 0, 3);
    }
    else if (shape == 2)
    {
        glColor3f(.2f, 1, .2f);
        glVertexPointer(3, GL_FLOAT, 0, q);
        glDrawArrays(GL_QUADS, 0, 4);
    }
    else
    {
        glColor3f(.2f, .5f, 1);
        glVertexPointer(3, GL_FLOAT, 0, p);
        glDrawArrays(GL_POLYGON, 0, 5);
    }
    glDisableClientState(GL_VERTEX_ARRAY);
    glFlush();
}

void key(unsigned char k, int, int)
{
    if (k == '1')
        shape = 1;
    if (k == '2')
        shape = 2;
    if (k == '3')
        shape = 3;
    if (k == 27)
        exit(0);
    glutPostRedisplay();
}

int main(int c, char **v)
{
    glutInit(&c, v);
    glutInitWindowSize(600, 600);
    glutCreateWindow("RUIZ_PE_18");
    glutDisplayFunc(display);
    glutKeyboardFunc(key);
    glutMainLoop();
    return 0;
}