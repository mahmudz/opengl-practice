#include <GL/glut.h>
#include "functions.h"
#include "chessboard.h"
#include "shapes.h"
#include "fan.h"
#include <math.h>
#include <iostream>
#include <random>

using namespace std;

int windowHeight = 500;
int windowWidth = 500;
float zoom = 5;

void timer(int);
void handleMouse(int button, int state, int x, int y);
void handleKeyboard(unsigned char,int,int);
void animate(int);

void setupSettings(void)
{
    glClearColor (0.0,0.0,0.0,1);
}

float boxX = 0;
float boxY = -4.5;
float boxHeight = 0.2;
float boxWidth = 2;

float circleX = 0;
float circleY = 0;
int circleAngle = 0;

void display (void)
{
    glClear (GL_COLOR_BUFFER_BIT);
    glLoadIdentity();

    // Draw Red Line
    //glColor3d(1,0,0);
    //drawRect(-5,-4.8,boxHeight,10);

    // Draw Saver
    //glColor3d(1,1,0);
    //drawRect(boxX,-4.8,boxHeight,boxWidth);

    // Draw Circle
    //circle(circleX,circleY);

    glutSwapBuffers();
}



void reshape(int w, int h)
{
    float sx = w / 100;
    float sy = h / 100;


    glViewport(0,0, w, h);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();

    gluOrtho2D(-zoom,zoom,-zoom,zoom);
    glMatrixMode(GL_MODELVIEW);
}


int main (int argc, char **argv)
{
    glutInit (&argc, argv);
    glutInitDisplayMode (GLUT_DOUBLE);

    glutInitWindowSize (500, 500);
    glutInitWindowPosition (600, 100);
    glutCreateWindow ("A basic OpenGL Window");

    setupSettings();

    glutDisplayFunc (display);
    glutReshapeFunc (reshape);
    glutMouseFunc(handleMouse);
    glutKeyboardFunc(handleKeyboard);
    //glutTimerFunc(0, animate, 0);

    glutMainLoop ();
    return 0;
}


void handleKeyboard(unsigned char ascii, int a, int b)
{
    cout << "ASCII: " << ascii << "\n";
    if(ascii == 'd')
    {
        boxX += 0.3;
        cout << "Go right. \n";
        display();

    }
    else if(ascii == 'a')
    {
        cout << "Go left. \n";
        boxX -= 0.3;
        display();
    }
}


void handleMouse(int button, int state, int mouseX, int mouseY)
{
    float *mouseCords;

    cout << "BTN: " << button << "\n";
    cout << "STATE: " << state << "\n";

    /*
        BTN STATE:
        0 - Clicked, 1 - Release

        BTN :
        0 - Left, 1 - Middle, 2 Right
        3 - Scroll Up, 4 - Scroll Down
    */

    if(state  == 0)
    {
        if(button == 4)
        {
            if(zoom < 10)
            {
                zoom += 0.2;
                cout << "Zoomed Out: " << zoom << "\n";
                reshape(500,500);
                display();
            }
        }
        else if(button == 3)
        {
            if(zoom > 1)
            {
                zoom -= 0.2;
                cout << "Zoomed In: " << zoom << "\n";
                reshape(500,500);
                display();
            }
        }
        else if(button == 0)
        {
//            mouseCords = normalizeMouseCords(mouseX, mouseY, zoom);
//            boxX = mouseCords[0]-(boxWidth / 2);
//            boxY = mouseCords[1]+(boxHeight / 2);
        }
    }
}
int flag = 0;
int angle = 0;

void animate(int)
{
    glutPostRedisplay();
    glutTimerFunc(1000/60, animate, 0);

    switch(flag)
    {
    case 0: // Go Down
        if(circleY < 4.6)
        {
            circleX += angle;
            circleY += 0.1;
        }
        else
        {
            cout << "Set Go Down.\n";
            angle = 0.2;

            flag = 1;
        }
    break;
    case 1:
        if(circleY > -4.4)
        {
            circleY -= 0.1;
            circleX += 0.1;
        }
        else
        {
            glRotatef(circleY,circleY,circleY,circleY);
            cout << "Set Go Up.\n";
            angle = 0.2;
            flag = 0;
        }
    break;
    }


    display();
}




