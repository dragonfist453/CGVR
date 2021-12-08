#include <iostream>
#include <GL/glut.h>
#define WINDOW_WIDTH 500
#define WINDOW_HEIGHT 500
using namespace std;
int x1,x2,yc1,y2,flag=0;

void drawPixel(int x, int y) {
	glColor3f(0,0,1);
	glPointSize(5);
	glBegin(GL_POINTS);
	glVertex2i(x,y);
	glEnd();
	glFlush();
}

void drawLine() {
	int dx,dy,i,e;
	int incx=1,incy=1,inc1,inc2;
	int x,y;
	dx=x2-x1;
	dy=y2-yc1;
	if(dx==0) {
		for(i=0;i<=dy;i++)
			drawPixel(x1,yc1+i);
		return;
	}
	if(dy==0) {
		for(i=0;i<=dx;i++)
			drawPixel(x1+i,yc1);
		return;
	}
	if(dx<0) dx=-dx;
	if(dy<0) dy=-dy;
	if(x2<x1) incx=-1;
	if(y2<yc1) incy=-1;
	x=x1;
	y=yc1;
	if(dx>dy) {
		drawPixel(x,y);
		e=2*dy-dx;
		inc1=2*(dy-dx);
		inc2=2*dy;
		for(i=0;i<dx;i++) {
			if(e>0) {
				y+=incy;
				e+=inc1;
			}
			else {
				e+=inc2;
			}
			x+=incx;
			drawPixel(x,y);
		}
	}
	else {
		drawPixel(x,y);
		e=2*dx-dy;
		inc1=2*(dx-dy);
		inc2=2*dx;
		for(i=0;i<dy;i++) {
			if(e>0) {
				x+=incx;
				e+=inc1;
			}
			else
				e+=inc2;
			y+=incy;
			drawPixel(x,y);
		}
	}
	glFlush();
}

void myInit() {
	glClearColor(1,1,1,1);
	gluOrtho2D(-WINDOW_WIDTH/2,WINDOW_WIDTH/2,-WINDOW_HEIGHT/2,WINDOW_HEIGHT/2);
}

void mouse(int button, int state, int x, int y) {
	if(button==GLUT_LEFT_BUTTON && state==GLUT_DOWN) {
		cout<<"x1,y1: ";
		x1=x-WINDOW_WIDTH/2;
		yc1=WINDOW_HEIGHT/2-y;
		flag++;
		cout<<x1<<" "<<yc1<<"\n";
	}
	if(button==GLUT_LEFT_BUTTON && state==GLUT_UP) {
		cout<<"x2,y2: ";
		x2=x-WINDOW_WIDTH/2;
		y2=WINDOW_HEIGHT/2-y;
		flag=0;
		cout<<x2<<" "<<y2<<"\n";
		drawLine();
	}
}

void display() {
	glClear(GL_COLOR_BUFFER_BIT);
}

int main(int argc, char* argv[]) {
	int choice;
	cout<<"Enter 1 for keyboard and 2 for mouse"<<endl;
	cin>>choice;
	if(choice==1) {
		cout<<"Enter x1: ";
		cin>>x1;
		cout<<"Enter y1: ";
		cin>>yc1;
		cout<<"Enter x2: ";
		cin>>x2;
		cout<<"Enter y2: ";
		cin>>y2;
	}
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
	glutInitWindowSize(WINDOW_WIDTH, WINDOW_HEIGHT);
	glutInitWindowPosition(0,0);
	glutCreateWindow("Bresenham's line drawing");
	glutDisplayFunc(display);
	myInit();
	if(choice==2)
		glutMouseFunc(mouse);
	else
		drawLine();
	glutMainLoop();
	return 0;
}
