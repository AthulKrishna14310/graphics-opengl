#include<GL/glut.h>
#include<stdio.h>
#include<stdlib.h>

void display(void){
    glBegin(GL_POLYGON);
    glColor3f(1,0.5,1);
    glVertex2i(200,200);
    glVertex2i(200,300);
    glVertex2i(300,300);
    glVertex2i(300,200);
    glEnd();    
    glFlush();
    glBegin(GL_POLYGON);
    glColor3f(1,1,1);
    glVertex2i(200,300);
    glVertex2i(250,350);
    glVertex2i(300,300);
    glEnd(); 
    glFlush();
    glBegin(GL_POLYGON);
    glColor3f(1,1,0.5);
    glVertex2i(225,200);
    glVertex2i(225,275);
    glVertex2i(250,275);
    glVertex2i(250,200);
    glEnd();
    glFlush();
    
}

int main(int argc , char** argv){
    glutInit(&argc,argv);
    glutInitDisplayMode(GLUT_SINGLE|GLUT_RGB);
    glutCreateWindow("Algorithm");
    glClearColor(0.0, 0.0, 0.0, 0.0);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluOrtho2D(0.0, 400.0, 0.0, 400.0);
    glutDisplayFunc(display);
    glutMainLoop();
    return 0;
}