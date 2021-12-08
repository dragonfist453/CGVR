#include <iostream>
#include <stdlib.h>
#include <math.h>
#include <GLUT/glut.h>
using namespace std;

int window1, window2, t;

void draw_circle(float xc,float yc, int rad) {
	float x,y,theta;
	x=rad,y=0;
	for(theta=0;theta<=360;theta+=0.25) {
		x=rad*cos(theta);
		y=rad*sin(theta);
		glBegin(GL_POINTS);
		glVertex2d(x+xc,y+yc);
		glEnd();
	}
}

void display_cylinder() {
	glClear(GL_COLOR_BUFFER_BIT);
	glColor3f(0,1,0);
	int xc = 150;
	int radius = 50;
	int yc = 100;
	for(float y=0;y<50;y+=2) {
		// if(y<5) {
		// 	glColor3f(1,0,0);
		// }
		// if(y>=5 && y<=95) {
		// 	glColor3f(0,1,0);
		// }
		// if(y>95) {
		// 	glColor3f(1,0,0);
		// }
		draw_circle(xc,yc+y,radius);
	}
	glFlush();
}

void draw_rectangle(float x, float y, float w, float h, int primitive) {
	glBegin(primitive);
	glVertex2f(x,y);
	glVertex2f(x+w,y);
	glVertex2f(x+w,y+h);
	glVertex2f(x,y+h);
	glEnd();
}

void display_parallelopiped() {
	glClear(GL_COLOR_BUFFER_BIT);
	glColor3f(0,0,1);
	float x,y;
	float x_off=100,y_off=100;
	float w=100,h=80;
	
	for(x=0,y=0;x<50,y<50;x+=2*w/100,y+=2*h/100) {
		// if(x<2) {
		// 	glColor3f(0,1,0);
		// 	draw_rectangle(x+x_off,y+y_off,w,h,GL_POLYGON);
		// }
		// if(x>=1 && x<49) {
		// 	glColor3f(0,0,1);
		// 	draw_rectangle(x+x_off,y+y_off,w,h,GL_LINE_LOOP);
		// }
		// if(x==49) {
		// 	glColor3f(1,0,0);
		// 	draw_rectangle(x+x_off,y+y_off,w,h,GL_POLYGON);
		// }
		draw_rectangle(x+x_off,y+y_off,w,h,GL_LINE_LOOP);
	}

	glFlush();
}

void myInit() {
	gluOrtho2D(0,300,0,300);
	glMatrixMode(GL_PROJECTION);
	glClearColor(1,1,1,1);
}

int main(int argc, char* argv[]) {
	glutInit(&argc, argv);
	glutInitWindowSize(300,300);
	window1 = glutCreateWindow("Cylinder");
	glutInitDisplayMode(GLUT_SINGLE|GLUT_RGB);
	glutDisplayFunc(display_cylinder);
	myInit();

	glutInitWindowSize(300,300);
	window2 = glutCreateWindow("Parallelopiped");
	glutInitDisplayMode(GLUT_SINGLE|GLUT_RGB);
	glutDisplayFunc(display_parallelopiped);
	myInit();
	
	glutMainLoop();
	return 0;
}
