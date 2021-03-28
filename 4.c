#include<GL/glut.h> 
#include <stdio.h> 
#include<math.h>
int n;

void reshape(int, int);
void init() {
	glClearColor(0.0, 0.0, 0.0, 1.0);
}
void display() {
	glClear(GL_COLOR_BUFFER_BIT);
	glLoadIdentity();
	int x1, y1, x2, y2, x, y;
	printf("Enter the coordinates (x1,y1,x2,y2):");
	scanf("%d,%d,%d,%d", &x1, &y1, &x2, &y2);
	glBegin(GL_LINES);
	glVertex2i(x1, y1);
	glVertex2i(x2, y2);
	glEnd();
	printf("Enter the translation coordinates:");
	scanf("%d,%d", &x, &y);
	x1 += x;
	y1 += y;
	x2 += x;
	y2 += y;

	glBegin(GL_LINES);
	glVertex2i(x1, y1);
	glVertex2i(x2, y2);
	glEnd();
	glFlush();

}
void display2() {
	glClear(GL_COLOR_BUFFER_BIT);
	glLoadIdentity();

	int i;
	int x1, y1, x2, y2, xn, yn;
	double r11, r12, r21, r22, th, c, s, an;
	printf("Enter the coordinates(x1,y1,x2,y2):");
	scanf("%d,%d,%d,%d", &x1, &y1, &x2, &y2);
	printf("\n Old Line");
	glBegin(GL_LINES);
	glVertex2i(x1, y1);
	glVertex2i(x2, y2);
	glEnd();
	printf("\n\nEnter the angle");
	scanf("%lf", &an);
	c = cos(an * 3.14 / 180);
	s = sin(an * 3.14 / 180);
	x1 = floor(x1 * c + y1 * s);
	y1 = floor(-x1 * s + y1 * c);
	x2 = floor(x2 * c + y2 * s);
	y2 = floor(-x2 * s + y2 * c);

	printf("\n New line");
	glBegin(GL_LINES);
	glVertex2i(x1, y1);
	glVertex2i(x2, y2);
	glEnd();
	glFlush();

}
void display3() {
	glClear(GL_COLOR_BUFFER_BIT);
	glLoadIdentity();
	int i;
	int x1, y1, x2, y2, x, y, a, b, c, d;

	printf("Enter the coordinates(x1,y1,x2,y2)");
	scanf("%d,%d,%d,%d", &x1, &y1, &x2, &y2);

	glBegin(GL_LINES);
	glVertex2i(x1, y1);
	glVertex2i(x2, y2);
	glEnd();

	printf("Enter scaling coordinates(x,y):");
	scanf("%d,%d", &x, &y);
	a = (x1 * x);
	b = (y1 * y);
	c = (x2 * x);
	d = (y2 * y);

	glBegin(GL_LINES);
	glVertex2i(a, b);
	glVertex2i(c, d);
	glEnd();
	glFlush();
}
void reshape(int w, int h) {
	glViewport(0, 0, (GLsizei)w, (GLsizei)h);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluOrtho2D(-20, 20, -20, 20);
	glMatrixMode(GL_MODELVIEW);
}

void translate() { display(); }
void rotate() { display2(); }
void scale() { display3(); }

int main(int argc, char** argv)
{
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_RGB);
	glutInitWindowPosition(200, 100);
	glutInitWindowSize(1000,1000);
	glutCreateWindow("New Window");

	printf("Enter \n 1.Translation\n 2.Rotation\n 3.Scaling\n ");
	printf("Enter your choice:\n");
	scanf("%d", &n);

	if (n == 1)
	{
		glutDisplayFunc(translate);
		glutReshapeFunc(reshape);
		init();
	}

	if (n == 2) {
		glutDisplayFunc(rotate);
		glutReshapeFunc(reshape);
		init();
	}

	if (n == 3) {
		glutDisplayFunc(scale);
		glutReshapeFunc(reshape);
		init();
	}
	glutMainLoop();
}