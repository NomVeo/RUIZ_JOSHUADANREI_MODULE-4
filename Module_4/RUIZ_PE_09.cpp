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
    GLfloat v[] = {0, 0, 0, 0, .7f, 0, .67f, .22f, 0, .41f, -.57f, 0, -.41f, -.57f, 0, -.67f, .22f, 0};
    GLubyte i[] = {0, 1, 2, 3, 4, 5, 1};
    glClear(GL_COLOR_BUFFER_BIT);
    glColor3f(1, .5f, .1f);
    glEnableClientState(GL_VERTEX_ARRAY);
    glVertexPointer(3, GL_FLOAT, 0, v);
    glDrawElements(GL_TRIANGLE_FAN, 7, GL_UNSIGNED_BYTE, i);
    glDisableClientState(GL_VERTEX_ARRAY);
    glFlush();
}

int main(int c, char **v)
{
    glutInit(&c, v);
    glutInitWindowSize(600, 500);
    glutCreateWindow("RUIZ_PE_09");
    glutDisplayFunc(display);
    glutMainLoop();
    return 0;
}