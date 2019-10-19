float f = 0;

void wing()
{
    glBegin(GL_POLYGON);
    glColor3f(0.066, 0.415, 0.533);
    glVertex3f(-0.1,0.3,0);
    glVertex3f(0.1,0.3,0);
    glVertex3f(0,0,0);
    glEnd();
}


void full_fan(void){

	wing();

	glRotatef(90,0,0,1);
	wing();

	glRotatef(180,0,0,1);
	wing();

	glRotatef(270,0,0,1);
	wing();

}

void rorateFan(void){
	glRotatef(f+=1,1,0,0);
}
