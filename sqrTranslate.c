#include <GL/glut.h>
#include <math.h>
#define size 20
#define pi 3.14159265359
int x = 30,y = 30;


void init2D(float r, float g, float b)
{
	glClearColor(r,g,b,0.0);  
	glClear(GL_COLOR_BUFFER_BIT);
	glMatrixMode (GL_PROJECTION);
	gluOrtho2D (0, 500, 0, 500);
	glColor3f(1,0,0);
}
void key(unsigned char k)
{
	switch(k)
	{
		case '+' : glScaled(2,2,0);
					glutPostRedisplay();break;
		case '-' : glScaled(0.5,0.5,0);
					glutPostRedisplay(); break;
	}
}

void key1(unsigned char k)
{
	switch(k)
	{
		case GLUT_KEY_UP : glTranslated(0,5,0);
					glutPostRedisplay();break;
		case GLUT_KEY_DOWN : glTranslated(0,-5,0);
					glutPostRedisplay();break;
		case GLUT_KEY_RIGHT : glTranslated(5,0,0);
					glutPostRedisplay();break;
		case GLUT_KEY_LEFT : glTranslated(-5,0,0);
					glutPostRedisplay();break;
	}
}

void mouse(int button, int state)
{
		if(button == GLUT_LEFT_BUTTON && state == GLUT_DOWN)
		{//glRotated(10,0,0,1);
		glRotated(10,0,0,1);
			glutPostRedisplay();
		}
		else if(button == GLUT_RIGHT_BUTTON && state == GLUT_DOWN)
		{glRotated(-10,0,0,1);
			glutPostRedisplay();}
}



void display(void)
{
	glClear(GL_COLOR_BUFFER_BIT);
	glColor3f(1,0,0);
	glBegin(GL_POLYGON);
	glVertex2i(x+size,y+size);
	glVertex2i(x-size,y+size);
	glVertex2i(x-size,y-size);
	glVertex2i(x+size,y-size);
	glEnd();
	glFlush();	

}

void main(int argc,char *argv[])
{
	glutInit(&argc,argv);
	glutInitDisplayMode (GLUT_SINGLE | GLUT_RGB);
	glutInitWindowSize (500, 500);
	glutInitWindowPosition (100, 100);
	glutCreateWindow ("points and lines");
	init2D(0.0,0.0,0.0);
	glutDisplayFunc(display);
	glutMouseFunc(mouse);
	glutKeyboardFunc(key);
	glutSpecialFunc(key1);
	glutMainLoop();
}
