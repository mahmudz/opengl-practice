from OpenGL.GL import *
from OpenGL.GLU import *
from math import cos, sin

def drawDot (x, y, r = 1, g = 1, b = 1):
    glColor3f(r,g,b)
    glPointSize(2)
    glBegin (GL_POINTS)
    glVertex2f(x,y)
    glEnd()

def drawLine(x1, x2, y1, y2, pointSize = 1):
    x = 0
    y = 0
    step = 0

    dx = x2 - x1
    dy = y2 - y1

    if(abs(dx) > abs(dy)):
        step = abs(dx)
    else:
        step = abs(dy)

    step *= 60

    incX = dx / step
    incY = dy / step

    glBegin(GL_POINTS)
    for i in range(0, step):
        x = x + incX
        y = y + incY
        glVertex2f(x, y)
    glEnd()

def rect(x, y, height = 1, width = 1):
    glBegin(GL_QUADS)
    glVertex2f(x,y)
    glVertex2f(x,y-height)
    glVertex2f(x+width,y-height)
    glVertex2f(x+width, y)
    glEnd()

def circle(x, y, radius = 0.3):
    twicePi = 2.0 * 3.142
    glBegin(GL_LINES)

    for i in range(0, 500):
        glVertex2f (
            (x + (radius * cos(i * twicePi / 211))),
            (y + (radius * sin(i * twicePi / 211)))
        )
    
    glEnd()

def midPointCircle(x_centre = 0, y_centre = 0, r = 1.5):
    x = r
    y = 0

    glBegin(GL_POINTS)

    glVertex2f( x + x_centre, y + y_centre)
    if (r > 0):
        glVertex2f( x + x_centre, -y + y_centre)
        glVertex2f( y + x_centre, x + y_centre)
        glVertex2f( -y + x_centre, x + y_centre)


    P = 0.1 - r
    while (x > y):
        y += 0.1
        if (P <= 0):
            P = P + 2 * y + 0.1
        else:
            x -= 0.1
            P = P + (2 * y) - (2 * x) + 0.1
          
        if (x < y):
            break
          
        glVertex2f( x + x_centre, y + y_centre)
        glVertex2f( -x + x_centre, y + y_centre)
        glVertex2f( x + x_centre, -y + y_centre)
        glVertex2f( -x + x_centre, -y + y_centre)
          
        if (x != y):
            glVertex2f( y + x_centre, x + y_centre)
            glVertex2f( -y + x_centre, x + y_centre)
            glVertex2f( y + x_centre, -x + y_centre)
            glVertex2f( -y + x_centre, -x + y_centre)
    glEnd()

def drawEllipse(cx, cy, rx, ry, num_segments):
    theta = 2 * 3.1415926
    c = cos(theta)
    s = sin(theta)
    t = 0

    x = 1
    y = 0 

    glBegin(GL_POINTS) 
    for i in range(0, num_segments):
        glVertex2f(x * rx + cx, y * ry + cy)
        t = x
        x = c * x - s * y
        y = s * t + c * y
    glEnd()

def midEllipse(rx, ry, xc, yc):
      
    x = 0;  
    y = ry;  
  
    # Initial decision parameter of region 1  
    d1 = ((ry * ry) - (rx * rx * ry) +
                      (0.25 * rx * rx));  
    dx = 2 * ry * ry * x;  
    dy = 2 * rx * rx * y;  
  
    # For region 1  
    while (dx < dy):  
  
        # Print points based on 4-way symmetry  
        glVertex2f(x + xc, y + yc)
        glVertex2f(-x + xc, y + yc)
        glVertex2f(x + xc, -y + yc)  
        glVertex2f(-x + xc, -y + yc)
  
        # Checking and updating value of  
        # decision parameter based on algorithm  
        if (d1 < 0):  
            x += 1;  
            dx = dx + (2 * ry * ry);  
            d1 = d1 + dx + (ry * ry);  
        else: 
            x += 1;  
            y -= 1;  
            dx = dx + (2 * ry * ry);  
            dy = dy - (2 * rx * rx);  
            d1 = d1 + dx - dy + (ry * ry);  
  
    # Decision parameter of region 2  
    d2 = (((ry * ry) * ((x + 0.5) * (x + 0.5))) +
          ((rx * rx) * ((y - 1) * (y - 1))) - 
           (rx * rx * ry * ry));  
  
    # Plotting points of region 2  
    while (y >= 0): 
  
        # printing points based on 4-way symmetry  
        glVertex2f(x + xc, y + yc)
        glVertex2f(-x + xc, y + yc)
        glVertex2f(x + xc, -y + yc)
        glVertex2f(-x + xc, -y + yc)
  
        # Checking and updating parameter  
        # value based on algorithm  
        if (d2 > 0): 
            y -= 1;  
            dy = dy - (2 * rx * rx);  
            d2 = d2 + (rx * rx) - dy;  
        else: 
            y -= 1;  
            x += 1;  
            dx = dx + (2 * ry * ry);  
            dy = dy - (2 * rx * rx);  
            d2 = d2 + dx - dy + (rx * rx); 