#include<stdio.h>
#include<string.h>
#include<GL/glut.h>
#include<GL/glu.h>
#include<GL/gl.h>

unsigned char p[] = "Your Song!";

void myInit(){
	glClear(GL_COLOR_BUFFER_BIT);
	glClearColor(1, 1, 1, 0);
	glMatrixMode (GL_PROJECTION);
	gluOrtho2D (0.0, 500.0, 0.0, 500.0);
	glFlush();
}

void Disp(int x, int y){
	glColor3f(1, 1, 1);
       
    y=500-y;
    glRasterPos2f(x, y);   
    int len = strlen(p);
    for (int i = 0; i < len; i++) {
        glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18, p[i]);
    }
    	
	glFlush();
}

void mouse(int button,int state,int x,int y) 
{
    if(button==GLUT_LEFT_BUTTON&&state==GLUT_DOWN){
        Disp(x, y); 
    }
}

int main(int argc, char **argv){
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_RGB | GLUT_SINGLE);
	glutInitWindowSize(500, 500);
	glutInitWindowPosition(100, 100);
	glutCreateWindow("Text Display");
	myInit();
	glutMouseFunc(mouse);
	glutMainLoop();

	return(0);
}
