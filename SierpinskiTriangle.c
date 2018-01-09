#include<stdio.h>
#include<GL/glut.h>
#include<GL/glu.h>
#include<GL/gl.h>
void init()
{
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluOrtho2D(0.0,50,0.0,50);
    glMatrixMode(GL_MODELVIEW);
    glClearColor(1.0,1.0,1.0,1.0);
    glColor3f(1.0,0.0,0.0);
}
void display()
{
    GLfloat vertices[3][2]={{0,0},{25,50},{50,0}};
    int i,j,k;
    int rand();
    GLfloat p[2]={7.5,5.0};
    glClear(GL_COLOR_BUFFER_BIT);
    glBegin(GL_POINTS);
    for(k=0;k<20000;k++)
    {
        j=rand()%3;
        p[0]=(p[0]+vertices[j][0])/2;
        p[1]=(p[1]+vertices[j][1])/2;
        glVertex2fv(p);
    }
    glEnd();
    glFlush();
}
int main(int argc,char **argv)
{
    glutInit(&argc,argv);
    glutInitDisplayMode(GLUT_SINGLE|GLUT_RGB);
    glutCreateWindow("Gasket Window");
    init();
    glutDisplayFunc(display);
    glutMainLoop();
    return 0;
}
