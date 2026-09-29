#define GL_SILENCE_DEPRECATION
#ifdef __APPLE__
#include <GLUT/glut.h>
#else
#include <GL/glut.h>
#endif
#include <iostream>
#include <cmath>

using namespace std;

const int N = 40;
void display()
{
    GLfloat v[(N + 2) * 3], c[(N + 2) * 3];
    v[0] = v[1] = v[2] = 0;
    c[0] = 1;
    c[1] = c[2] = 0;
    for (int i = 0; i <= N; i++)
    {
        float a = 2 * 3.1415926f * i / N;
        int p = (i + 1) * 3;
        v[p] = .6f * cosf(a);
        v[p + 1] = .6f * sinf(a);
        v[p + 2] = 0;
        float t = (float)i / N;
        c[p] = 1 - t;
        c[p + 1] = t;
        c[p + 2] = .5f;
    }
    glClear(GL_COLOR_BUFFER_BIT);
    glEnableClientState(GL_VERTEX_ARRAY);
    glEnableClientState(GL_COLOR_ARRAY);
    glVertexPointer(3, GL_FLOAT, 0, v);
    glColorPointer(3, GL_FLOAT, 0, c);
    glDrawArrays(GL_TRIANGLE_FAN, 0, N + 2);
    glDisableClientState(GL_COLOR_ARRAY);
    glDisableClientState(GL_VERTEX_ARRAY);
    glFlush();
}

int main(int c, char **v)
{
    glutInit(&c, v);
    glutInitWindowSize(600, 600);
    glutCreateWindow("RUIZ_PE_11");
    glutDisplayFunc(display);
    glutMainLoop();
    return 0;
}