#include<GL/glut.h>
#include<stdio.h>
#include<stdlib.h>
int xa,ya;
int radius;
void display(void)
{
    initialiseGL(); 
    int tempX=0;
    int tempY=radius;
    
    float decision=(5/4)-radius;
    while(tempY>tempX){
        if(decision<0){
            tempX++;
            decision+=2*tempX+1;
        }else{
            tempX++;
            tempY--;
            decision+=2*(tempX-tempY)+1;
        }
        plot(tempX,tempY);
        plot(-tempX,tempY);
        plot(tempX,-tempY);
        plot(-tempX,-tempY);
        plot(tempY,tempX);
        plot(-tempY,tempX);
        plot(tempY,-tempX);
        plot(-tempY,-tempX);
    
    }
   
    done();
}

void plot(GLint x, GLint y){
    glVertex2i(x+xa,y+ya);
}

void done(){
    glEnd();
    glFlush();
}
void initialiseGL(){
    glClear(GL_COLOR_BUFFER_BIT);
    glColor3f(1.0f,1.0f,1.0f);
    glBegin(GL_POINTS);
    glPointSize(4.0);
}

int main(int argc , char** argv){
    glutInit(&argc,argv);
    glutInitDisplayMode(GLUT_SINGLE|GLUT_RGB);
    glutCreateWindow("Circle Drawing");
    glClearColor(0.0, 0.0, 0.0, 0.0);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluOrtho2D(0.0, 400.0, 0.0, 400.0);
    printf("Enter the point x,y,radius ");
    scanf("%d,%d,%d",&xa,&ya,&radius);
    glutDisplayFunc(display);
    glutMainLoop();
    return 0;
}