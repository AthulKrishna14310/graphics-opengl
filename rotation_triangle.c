
#include<GL/glut.h>
#include<stdio.h>
#include<stdlib.h>
#include<math.h>
float xt,yt,xl,yl,xr,yr;
float sinValue,cosValue,angle;
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
    draw(xt,yt);
    draw(xl,yl);
    draw(xr,yr);
    finalise();
    sinValue=sin(angle*3.14/180);
    cosValue=cos(angle*3.14/180);
    xt=floor(xt*cosValue+yt*sinValue);
    yt=floor(-xt*sinValue+yt*cosValue);
    xl=floor(xl*cosValue+yl*sinValue);
    yl=floor(-xl*sinValue+yl*cosValue);
    xr=floor(xr*cosValue+yr*sinValue);
    yr=floor(-xr*sinValue+yr*cosValue);
    initialiseGL();
    glColor3f(1.0,0.5,1.0);
    draw(xt,yt);
    draw(xl,yl);
    draw(xr,yr);
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
    printf("Enter the point xt,yt,xl,yl,xr,yr,angle");
    scanf("%f,%f,%f,%f,%f,%f,%f",&xt,&yt,&xl,&yl,&xr,&yr,&angle);
    glutDisplayFunc(display);
    glutMainLoop();
    return 0;
}