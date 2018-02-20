#include<stdio.h>
#include<GL/glut.h>
#include<GL/glu.h>
#include<GL/gl.h>

void myInit(){
	glClear(GL_COLOR_BUFFER_BIT);
	glClearColor(1, 1, 1, 0);
	glMatrixMode (GL_PROJECTION);
	gluOrtho2D (0.0, 200.0, 0.0, 150.0);
}

void Disp(){
	glColor3f(1, 1, 1);
	glBegin(GL_LINES);
	glVertex2f(10, 10);
	glVertex2f(50, 50);
	glEnd();
	glFlush();
}
int main(int argc, char **argv){
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_RGB | GLUT_SINGLE);
	glutInitWindowSize(500, 500);
	glutInitWindowPosition(100, 100);
	glutCreateWindow("Line");
	myInit();
	glutDisplayFunc(Disp);
	glutMainLoop();

	return(0);
}
