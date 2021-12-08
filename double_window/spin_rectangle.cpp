#include <iostream>
#include <stdlib.h>
#include <GLUT/glut.h>
using namespace std;

int window1, window2, t;
static GLfloat spin=0.0;

void spinDisplay() {
	spin+=0.2;
	glutPostRedisplay();
}

void display() {
	glutSetWindow(t);
	glClear(GL_COLOR_BUFFER_BIT);
	glPushMatrix();
	glLoadIdentity();
	glRotatef(spin,0,0,1);
	glBegin(GL_POLYGON);
	glColor3f(1.0,0.0,0.0);
	glVertex3f(-0.25,-0.25,0.25);
	glColor3f(0.0,1.0,0.0);
	glVertex3f(0.25,-0.25,0.25);
	glColor3f(0.0,0.0,1.0);
	glVertex3f(0.25,0.25,0.25);
	glColor3f(1.0,0.0,1.0);
	glVertex3f(-0.25,0.25,0.25);
	glEnd();
	glPopMatrix();
	if(t==window1) {
		glFlush();
		t=window2;
	}
	else{
		glutSwapBuffers();
		t=window1;
	}
}

void mouse(int button, int state, int x, int y) {
	switch(button) {
		case GLUT_LEFT_BUTTON: if(state==GLUT_DOWN)
								   glutIdleFunc(spinDisplay);
								break;
		case GLUT_RIGHT_BUTTON: if(state==GLUT_DOWN)
								   glutIdleFunc(NULL);
								break;
		default: break;
	}
}

void myInit() {
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
	glOrtho(-1,1,-1,1,-1,1);
	glClearColor(1,1,1,1);
	glColor3f(1,0,0);
}

int main(int argc, char* argv[]) {
	glutInit(&argc, argv);
	glutInitWindowSize(500,500);
	window1 = glutCreateWindow("Single");
	glutInitDisplayMode(GLUT_SINGLE|GLUT_RGB);
	glutDisplayFunc(display);
	glutMouseFunc(mouse);
	myInit();

	glutInitWindowSize(500,500);
	window2 = glutCreateWindow("Double");
	glutInitDisplayMode(GLUT_DOUBLE|GLUT_RGB);
	t = window1;
	glutDisplayFunc(display);
	glutMouseFunc(mouse);
	myInit();
	glutMainLoop();
	return 0;
}
