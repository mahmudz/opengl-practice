#include <iostream>

using namespace std;

void printCords(double x, double y)
{

    cout << "(" << x << ", " << y << ")\n";
};

float * normalizeMouseCords(int mouseX, int mouseY, float zoom)
{

    int winHeight = zoom * 100;
    int winWidth = zoom * 100;

    float ox;
    float oy;

    if(mouseX < (winWidth / 2))
    {
        ox = (mouseX - winWidth);
        ox += (winWidth / 2);
        ox *= 2;
    }
    else
    {
        ox = mouseX;
        ox -= (winWidth / 2);
        ox *= 2;
    }

    if(mouseY < (winHeight / 2))
    {
        oy = abs(mouseY - winHeight);
        oy -= (winHeight / 2);
        oy *= 2;
    }
    else
    {
        oy = -(mouseY - (winHeight / 2));
        oy *= 2;
    }


    ox = ox / 100;
    oy = oy / 100;

    float cords[2] = {ox, oy};

    cout << "NORMALIZED CORDS: ";
    printCords(ox,oy);
    cout << "\n";

    return cords;
}
