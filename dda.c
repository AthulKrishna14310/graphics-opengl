#include<GL/glut.h>
#include<stdio.h>
#include<stdlib.h>
float xa,xb,ya,yb;
float length;
float xInc,yInc,tempX,tempY;
    
void display(void)
{
	initialiseGL(); 
    length=abs(xb-xa);
    if(abs(yb-ya)>length){
        length=abs(yb-ya);
    }
     xInc=(xb-xa)/length;
     yInc=(yb-ya)/length;
     tempX=xa;
     tempY=ya;
    for (int i=0;i<length;i++){
        plot((int)(tempX+0.5),(int)(tempY+0.5));
        tempX=tempX+xInc;
        tempY=tempY+yInc;
    }
    
    done();
}

void plot(GLint x, GLint y){
    glVertex2i(x, y);
}

void done(){
    glEnd();
    glFlush();
}
void initialiseGL(){
    glClear(GL_COLOR_BUFFER_BIT);
    glColor3f(1.0,1.0,1.0);
    glBegin(GL_POINTS);
}

int main(int argc , char** argv){
    glutInit(&argc,argv);
    glutInitDisplayMode(GLUT_SINGLE|GLUT_RGB);
    glutCreateWindow("DDA Line Algorithm");
    glClearColor(0.0, 0.0, 0.0, 0.0);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluOrtho2D(0.0, 400.0, 0.0, 400.0);
    printf("Enter the point x1,y1,x2,y2 ");
    scanf("%f,%f,%f,%f",&xa,&ya,&xb,&yb);
    glutDisplayFunc(display);
    glutMainLoop();
    return 0;
}