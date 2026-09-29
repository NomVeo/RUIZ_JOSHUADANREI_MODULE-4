#define GL_SILENCE_DEPRECATION
#ifdef __APPLE__
#include <GLUT/glut.h>
#else
#include <GL/glut.h>
#endif
#include <iostream>
#include <cmath>

using namespace std;

const int T = 12, V = T * 2;
GLfloat v[V * 3];
GLubyte i[T * 3];

void gen()
{
    for (int n = 0; n < V; n++)
    {
        float a = 2 * 3.1415926f * n / V, r = n % 2 ? .75f : .55f;
        v[n * 3] = r * cosf(a);
        v[n * 3 + 1] = r * sinf(a);
        v[n * 3 + 2] = 0;
    }
    for (int n = 0; n < T; n++)
    {
        i[n * 3] = 0;
        i[n * 3 + 1] = (n * 2 + 1) % V;
        i[n * 3 + 2] = (n * 2 + 2) % V;
    }
}

void display()
{
    glClear(GL_COLOR_BUFFER_BIT);
    glColor3f(.9f, .3f, .2f);
    glEnableClientState(GL_VERTEX_ARRAY);
    glVertexPointer(3, GL_FLOAT, 0, v);
    glDrawElements(GL_TRIANGLES, T * 3, GL_UNSIGNED_BYTE, i);
    glDisableClientState(GL_VERTEX_ARRAY);
    glFlush();
}

int main(int c, char **v2)
{
    glutInit(&c, v2);
    glutInitWindowSize(600, 600);
    glutCreateWindow("RUIZ_PE_17");
    gen();
    glutDisplayFunc(display);
    glutMainLoop();
    return 0;
}