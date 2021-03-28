#include<GL/glut.h>
#include<stdio.h>
#include<stdlib.h>
int xC,yC,maAX,miAx;
float disPara1,disPara2;
float dx,dy;
int x,y;
void display(void)
{
    initialiseGL(); 
    x=0;
    y=miAx;
    disPara1=miAx*miAx-(maAX*maAX)*miAx+(maAX*maAX)*0.25;
    dx=2*miAx*miAx*x;
    dy=2*maAX*maAX*y;
    while(dx<dy){
        plot(xC+x,yC+y);
        plot(xC-x,yC+y);
        plot(xC+x,yC-y);
        plot(xC-x,yC-y);
        
        if(disPara1<0){
            x=x+1;
            dx=2*miAx*miAx*x;
            disPara1=disPara1+dx+miAx*miAx;
        }
        else{
            x=x+1;
            y=y-1;
            dx=2*miAx*miAx*x;
            dy=2*maAX*maAX*y;
            disPara1=disPara1+dx-dy+miAx*miAx;
        }
    }
    disPara2=miAx*miAx*(x+0.5)*(x+0.5)+maAX*maAX*(y-1)*(y-1)-maAX*maAX*miAx*miAx;
    while(y>0){
        plot(xC+x,yC+y);
        plot(xC-x,yC+y);
        plot(xC+x,yC-y);
        plot(xC-x,yC-y);
        if(disPara2>0){
            x=x;
            y=y-1;
            dy=2*maAX*maAX*y;
            disPara2=disPara2-dy+maAX*maAX;
        }else{
            x=x+1;
            y=y-1;
            dy=dy-2*maAX*maAX;
            dx=dx+2*miAx*miAx;
            disPara2=disPara2+dx-dy+maAX*maAX;
        }//
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
    glVertex2i(xC,yC);//
}

int main(int argc , char** argv){
    glutInit(&argc,argv);
    glutInitDisplayMode(GLUT_SINGLE|GLUT_RGB);
    glutCreateWindow("Ellispse Drawing");
    glClearColor(0.0, 0.0, 0.0, 0.0);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluOrtho2D(0.0, 500.0, 0.0, 500.0);
    printf("Enter the data X,Y,Major Axis,Minor Axis ");
    scanf("%d,%d,%d,%d",&xC,&yC,&maAX,&miAx);
    glutDisplayFunc(display);
    glutMainLoop();
    return 0;
}