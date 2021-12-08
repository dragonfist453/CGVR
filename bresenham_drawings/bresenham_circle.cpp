#include <iostream>
#include <GL/glut.h>
#include <math.h>
#define WINDOW_WIDTH 500
#define WINDOW_HEIGHT 500
using namespace std;
int xc,yc,xr,yr,flag=0;

void drawCircle(int xc, int yc, int x, int y) {
	glColor3f(0,0,1);
	glPointSize(3);
	glBegin(GL_POINTS);
	glVertex2i(xc+x,yc+y);
	glVertex2i(xc-x,yc+y);
	glVertex2i(xc+x,yc-y);
	glVertex2i(xc-x,yc-y);
	glVertex2i(xc+y,yc+x);
	glVertex2i(xc-y,yc+x);
	glVertex2i(xc+y,yc-x);
	glVertex2i(xc-y,yc-x);
	glEnd();
	glFlush();
}

void bresCircle(int xc, int yc, int r) {
	int x=0,y=r;
	int d=3-2*r;
	while(x<y) {
		drawCircle(xc,yc,x,y);
		x++;
		if(d<0)
			d=d+4*x+6;
		else {
			y--;
			d=d+4*(x-y)+10;
		}
		drawCircle(xc,yc,x,y);
	}
	glFlush();
}

void myInit() {
	glClearColor(1,1,1,1);
	gluOrtho2D(-WINDOW_WIDTH/2,WINDOW_WIDTH/2,-WINDOW_HEIGHT/2,WINDOW_HEIGHT/2);
}

void mouse(int button, int state, int x, int y) {
	if(button==GLUT_LEFT_BUTTON && state==GLUT_DOWN) {
		cout<<"xc,yc: ";
		xc=x-WINDOW_WIDTH/2;
		yc=WINDOW_HEIGHT/2-y;
		flag++;
		cout<<xc<<" "<<yc<<"\n";
	}
	if(button==GLUT_LEFT_BUTTON && state==GLUT_UP) {
		cout<<"xr,yr: ";
		xr=x-WINDOW_WIDTH/2;
		yr=WINDOW_HEIGHT/2-y;
		flag=0;
		cout<<xr<<" "<<yr<<"\n";
		int r=sqrt((float)((xr-xc)*(xr-xc) + (yr-yc)*(yr-yc)));
		bresCircle(xc,yc,r);
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
		cout<<"Enter xc: ";
		cin>>xc;
		cout<<"Enter yc: ";
		cin>>yc;
		cout<<"Enter xr: ";
		cin>>xr;
		cout<<"Enter yr: ";
		cin>>yr;
	}
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
	glutInitWindowSize(WINDOW_WIDTH, WINDOW_HEIGHT);
	glutInitWindowPosition(0,0);
	glutCreateWindow("Bresenham's circle drawing");
	glutDisplayFunc(display);
	myInit();
	if(choice==2)
		glutMouseFunc(mouse);
	else {
		int r=sqrt((float)((xr-xc)*(xr-xc) + (yr-yc)*(yr-yc)));
		bresCircle(xc,yc,r);
	}
	glutMainLoop();
	return 0;
}
