
void chessboard()
{

    GLfloat x, y;
    x = -4;
    y = 4;
    GLfloat blockSize = 1;

    int row;
    int col;
    int c = 0;


    for (row = 1; row <= 8; row++)
    {
        for (col = 1; col <= 8; col++)
        {
            glBegin(GL_QUADS);

            if(c == 1)
            {
                glColor3f(1, 1, 1);
                c = 0;
            }
            else
            {
                glColor3f(0, 0, 0);
                c = 1;
            }


            glVertex2f(x,y);
            glVertex2f(x,y-blockSize);
            glVertex2f(x+blockSize,y-blockSize);
            glVertex2f(x+blockSize, y);

            glEnd();


            x = x + blockSize;
        }
        y = y - blockSize;
        x = -4;
        c = !c;
    }
}


