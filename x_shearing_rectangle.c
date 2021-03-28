#include<GL/glut.h>
#include<stdio.h>
#include<stdlib.h>

void initialiseGL(){
    glBegin(GL_COLOR_BUFFER_BIT);
    glColor3f(1.0,1.0,1.0);
    glBegin(GL_POLYGON);

}
void draw(GLint x, GLint y){
    glVertex2i(x,y);
}
void finalise(){
    glEnd();
    glFlush();
}
void display(void){
    initialiseGL();
    draw(100,100);
    draw(100,150);
    draw(200,150);
    draw(200,100);
    finalise();
    initialiseGL();
    glColor3f(1.0,0.5,1.0);
    int xS=50;
    draw(100,100);
    draw(100+xS,150);
    draw(200+xS,150);
    draw(200,100);
    finalise();
}
int main(int argc , char** argv){
    glutInit(&argc,argv);
    glutInitDisplayMode(GLUT_SINGLE|GLUT_RGB);
    glutCreateWindow("Triangle Algorithm");
    glClearColor(0.0, 0.0, 0.0, 0.0);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluOrtho2D(0.0, 400.0, 0.0, 400.0);
    glutDisplayFunc(display);
    glutMainLoop();
    return 0;
}