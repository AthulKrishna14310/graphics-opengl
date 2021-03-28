#include<GL/glut.h>
#include<stdio.h>
#include<stdlib.h>
#include<math.h>
int xa,xb,ya,yb;
int tFx,tFy;
int tempXa,tempXb,tempYa,tempYb;
int dx,dy,p;
int i;
double angle;
float sinValue,cosValue;


void display(void)
{
    tempXa=xa;
    tempYa=ya;
    tempXb=xb;
    tempYb=yb;
	dx=xb-xa;
    dy=yb-ya;
    p=2*dy-dx;
    initialiseGL(); 
    for (i=0;i<dx;i++){
        if(p<0){
            xa=xa+1;
            plot(xa,ya);
        }else{
            xa=xa+1;
            ya=ya+1;
            plot(xa,ya);
        }
    }
    
    glColor3f(1.0,0.5,1.0);
    xa=tempXa;
    xb=tempXb;
    ya=tempYa;
    yb=tempYb;
    cosValue=cos(angle*3.14/180);
    sinValue=sin(angle*3.14/180);
    xa=floor(xa*cosValue+ya*sinValue);
    ya=floor(-xa*sinValue+ya*cosValue);
    xb=floor(xb*cosValue+yb*sinValue);
    yb=floor(-xb*sinValue+yb*cosValue);
    dx=xb-xa;
    dy=yb-ya;
    p=2*dy-dx;
    for (i=0;i<dx;i++){
        if(p<0){
            xa=xa+1;
            plot(xa,ya);
        }else{
            xa=xa+1;
            ya=ya+1;
            plot(xa,ya);
        }
    }
    done();
}

void plot(GLint x, GLint y){
    glVertex2i(x,y);
}

void done(){
    glEnd();
    glFlush();
}
void initialiseGL(){
    glClear(GL_COLOR_BUFFER_BIT);
    glColor3f(1.0,1.0,1.0);
    glBegin(GL_POINTS);
    glVertex2i(xa,ya);
}

int main(int argc , char** argv){
    glutInit(&argc,argv);
    glutInitDisplayMode(GLUT_SINGLE|GLUT_RGB);
    glutCreateWindow("Line Algorithm");
    glClearColor(0.0, 0.0, 0.0, 0.0);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluOrtho2D(0.0, 400.0, 0.0, 400.0);
    printf("Enter the point x1,y1,x2,y2,angle");
    scanf("%d,%d,%d,%d,%lf",&xa,&ya,&xb,&yb,&angle);
    glutDisplayFunc(display);
    glutMainLoop();
    return 0;
}