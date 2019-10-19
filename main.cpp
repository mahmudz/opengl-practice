#include <GL/glut.h>
#include "functions.h"
#include "chessboard.h"
#include "shapes.h"
#include "fan.h"
#include <math.h>
#include <iostream>

using namespace std;

int windowHeight = 500;
int windowWidth = 500;
float zoom = 5;

void timer(int);
void handleMouse(int button, int state, int x, int y);


void setupSettings(void)
{
    glClearColor (0.0,0.1,0.5,1);
}

float x = 0;
float y = 0;

void display (void)
{
    glClear (GL_COLOR_BUFFER_BIT);
    glLoadIdentity();

    chessboard();

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

    glutMainLoop ();
    return 0;
}


void handleMouse(int button, int state, int mouseX, int mouseY)
{

//    cout << "BTN: " << button << "\n";
//    cout << "STATE: " << state << "\n";

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
            float ox = (mouseX/500) - zoom;
            float oy = -(mouseY/500) - zoom;

            cout << "CORDS: ";
            printCords(ox,oy);
            cout << "\n";
        }
    }
}





