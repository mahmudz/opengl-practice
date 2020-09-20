import pygame
from pygame.locals import *

from OpenGL.GL import *
from OpenGL.GLU import *
from functions import *
import time

if __name__ == '__main__':
    pygame.init()
    display = (640, 480)
    pygame.display.set_mode(display, DOUBLEBUF|OPENGL)
    gluPerspective(45, (display[0]/display[1]), 0.1, 50.0)
    glTranslatef(0.0, 0.0, -10)

    while True:
        for event in pygame.event.get():
            if event.type == pygame.QUIT:
                pygame.quit()
                quit()

        glClear(GL_COLOR_BUFFER_BIT|GL_DEPTH_BUFFER_BIT)
        glClear (GL_COLOR_BUFFER_BIT)
        glColor3f (1, 1, 1)
        glPointSize(2)

        glPushMatrix()
        circle(0, 0)
        glPopMatrix()

        glFlush()
        pygame.display.flip()
        pygame.time.wait(10)
