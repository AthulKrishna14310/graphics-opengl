#include<GL/glut.h>
#include<stdio.h>
#include<stdlib.h>
int xa,xb,ya,yb;
void display(void)
{
	int dx=xb-xa;
    int dy=yb-ya;
    int p=2*dy-dx;
    initialiseGL(); 
    for (int i=0;i<dx;i++){
        if(p<0){
            xa=xa+1;
            plot(xa,ya);
	    p=p+2*dy;
        }else{
            xa=xa+1;
            ya=ya+1;
            plot(xa,ya);
	    p=p+2*dy-2*dx;
        }
    }
    done();
}

void plot(int x, int y){
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
    glutCreateWindow("->Bresman Line Algorithm");
    glClearColor(0.0, 0.0, 0.0, 0.0);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluOrtho2D(0.0, 200.0, 0.0, 150.0);
    printf("->Enter the point x1,y1,x2,y2 ");
    scanf("%d,%d,%d,%d",&xa,&ya,&xb,&yb);
    glutDisplayFunc(display);
    glutMainLoop();
    return 0;
}
