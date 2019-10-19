#include <iostream>
#include <math.h>
#define TWO_PI 6.28318530718

using namespace std;


void printCords(float x, float y)
{

    cout << "(" << x << ", " << y << ")\n";
};


void star(float x, float y, float radius1 = 3, float radius2= 1, int npoints = 5)
{

    float  angle = TWO_PI / npoints;
    float  halfAngle = angle / 2.0;

    float sx;
    float sy;

    glBegin(GL_POLYGON);
    for (float a = 0; a < TWO_PI; a += angle)
    {

        sx = x + cos(a) * radius2;
        sy = y + sin(a) * radius2;

        glVertex2f(sx, sy);

        sx = x + cos(a + halfAngle) * radius1;
        sy = y + sin(a + halfAngle) * radius1;
        glVertex2f(sx, sy);

    }
    glEnd();
}




void drawRect(float x, float y, float height, float width)
{
    glColor3f(1,1,1);
    glBegin(GL_QUADS);
    glVertex2f(x,y);
    glVertex2f(x,y-height);
    glVertex2f(x+width,y-height);
    glVertex2f(x+width, y);
    glEnd();
}


void triangle(float a[2], float b[2], float c[2])

{
    glBegin(GL_TRIANGLES);
    glVertex2f(a[0],a[1]);
    glVertex2f(b[0],b[1]);
    glVertex2f(c[0],c[1]);
    glEnd();
}


void house (void)
{
    glBegin(GL_POLYGON);
    glColor3f(0, 1, 0);
    glVertex2f(-2,1);
    glVertex2d(0,3);
    glVertex2d(2,1);
    glEnd();

    glBegin(GL_POLYGON);
    glColor3f(1,1,1);
    glVertex2f(-2,1);
    glVertex2f(2,1);
    glVertex2f(2,-2);
    glVertex2f(-2,-2);
    glEnd();

    glBegin(GL_POLYGON);
    glColor3f(0,0,1);
    glVertex2f(-0.6,0);
    glVertex2f(0.6,0);
    glVertex2f(0.6,-2);
    glVertex2f(-0.6,-2);
    glEnd();

    glBegin(GL_POLYGON);
    glColor3f(1,0,0);
    glVertex2f(-1.6,-0.4);
    glVertex2f(-1,-0.4);
    glVertex2f(-1,-1);
    glVertex2f(-1.6,-1);
    glEnd();

    glBegin(GL_POLYGON);
    glColor3f(1,0,0);
    glVertex2f(1,-0.4);
    glVertex2f(1.6,-0.4);
    glVertex2f(1.6,-1);
    glVertex2f(1,-1);
    glEnd();
}
