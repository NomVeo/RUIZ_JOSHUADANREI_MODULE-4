#define GL_SILENCE_DEPRECATION
#ifdef __APPLE__
#include <GLUT/glut.h>
#else
#include <GL/glut.h>
#endif
#include <iostream>
#include <cmath>

using namespace std;


const int P = 12;
GLfloat pv[P * 9], pc[P * 9], cv[P + 2][3], gv[] = {-1, -.8f, 0, 1, -.8f, 0, 1, -1, 0, -1, -1, 0};
GLubyte ci[P + 2];

void gen()
{
    const float PI = 3.1415926f;
    float cx = 0, cy = .15f, in = .12f, out = .65f;
    for (int n = 0; n < P; n++)
    {
        float a = 2 * PI * n / P, h = PI / P * .65f, a1 = a - h, a2 = a + h;
        int z = n * 9;
        pv[z] = cx + in * cosf(a);
        pv[z + 1] = cy + in * sinf(a);
        pv[z + 2] = 0;
        pv[z + 3] = cx + out * cosf(a1);
        pv[z + 4] = cy + out * sinf(a1);
        pv[z + 5] = 0;
        pv[z + 6] = cx + out * cosf(a2);
        pv[z + 7] = cy + out * sinf(a2);
        pv[z + 8] = 0;
        float r = .5f + .5f * cosf(a), g = .5f + .5f * sinf(a);
        for (int j = 0; j < 3; j++)
        {
            pc[z + j * 3] = r;
            pc[z + j * 3 + 1] = g;
            pc[z + j * 3 + 2] = .8f;
        }
    }
    cv[0][0] = cx;
    cv[0][1] = cy;
    cv[0][2] = 0;
    ci[0] = 0;
    for (int n = 0; n <= P; n++)
    {
        float a = 2 * PI * n / P;
        cv[n + 1][0] = cx + in * cosf(a);
        cv[n + 1][1] = cy + in * sinf(a);
        cv[n + 1][2] = 0;
        ci[n + 1] = n + 1;
    }
}

void display()
{
    glClear(GL_COLOR_BUFFER_BIT);
    glEnableClientState(GL_VERTEX_ARRAY);
    glEnableClientState(GL_COLOR_ARRAY);
    glVertexPointer(3, GL_FLOAT, 0, pv);
    glColorPointer(3, GL_FLOAT, 0, pc);
    glDrawArrays(GL_TRIANGLES, 0, P * 3);
    glDisableClientState(GL_COLOR_ARRAY);
    glColor3f(1, .8f, 0);
    glVertexPointer(3, GL_FLOAT, 0, cv);
    glDrawElements(GL_TRIANGLE_FAN, P + 2, GL_UNSIGNED_BYTE, ci);
    glColor3f(.2f, .7f, .2f);
    glVertexPointer(3, GL_FLOAT, 0, gv);
    glDrawArrays(GL_QUADS, 0, 4);
    glDisableClientState(GL_VERTEX_ARRAY);
    glFlush();
}

int main(int c, char **v)
{
    glutInit(&c, v);
    glutInitWindowSize(800, 700);
    glutCreateWindow("RUIZ_PE_20");
    gen();
    glutDisplayFunc(display);
    glutMainLoop();
    return 0;
}