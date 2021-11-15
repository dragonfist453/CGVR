#include <iostream>
#include <GL/glut.h>
#include <GL/gl.h>
using namespace std;

int choice = 0;

void idle() {
  glutPostRedisplay();
}

void display() {
  glClear(GL_COLOR_BUFFER_BIT);
  if(choice == 1) {
    glBegin(GL_POLYGON);
    glVertex2f(100,100);
    glVertex2f(100,300);
    glVertex2f(200,300);
    glVertex2f(200,100);
    glEnd();
  }
  else if(choice == 2) {
    glBegin(GL_POLYGON);
    glVertex2f(100,100);
    glVertex2f(100,300);
    glVertex2f(300,300);
    glVertex2f(300,100);
    glEnd();
  }
  glFlush();
}

void top_menu(int id) {
  switch(id) {
    case 1:
      choice = 1;
      break;
    case 2:
      choice = 2;
      break;
    case 3:
      exit(0);
      break;
  }
  glutPostRedisplay();
}

void colors_menu(int id) {
  switch(id) {
    case 1:
      glColor3f(0,0,0);
      break;
    case 2:
      glColor3f(1,0,0);
      break;
    case 3:
      glColor3f(0,1,0);
      break;
    case 4:
      glColor3f(0,0,1);
      break;
    case 5:
      glColor3f(1,1,1);
      break;
  }
  glutPostRedisplay();
}

void myInit() {
  glClearColor(1,1,1,1);
  gluOrtho2D(0,500,0,500);
}

int main(int argc, char* argv[]) {
  glutInit(&argc, argv);
  glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
  glutInitWindowSize(500, 500);
  glutInitWindowPosition(0,0);
  glutCreateWindow("Submenus!");
  glutIdleFunc(idle);
  glutDisplayFunc(display);

  int color_menu = glutCreateMenu(colors_menu);
  glutAddMenuEntry("Black", 1);
  glutAddMenuEntry("Red", 2);
  glutAddMenuEntry("Green", 3);
  glutAddMenuEntry("Blue", 4);
  glutAddMenuEntry("White", 5);
  glutCreateMenu(top_menu);
  glutAddSubMenu("Colors", color_menu);
  glutAddMenuEntry("Rectangle", 1);
  glutAddMenuEntry("Square", 2);
  glutAddMenuEntry("Quit", 3);
  glutAttachMenu(GLUT_RIGHT_BUTTON);

  myInit();
  glutMainLoop();
  return 0;
}