#include <iostream>
#include <GL/gl.h>
#include <GL/glut.h>
using namespace std;

typedef float point2[2];

void display() {
  point2 rectangle[4] = {
    {100.0, 100.0},
    {100.0, 400.0},
    {400.0, 400.0},
    {400.0, 100.0}
  };
  glClear(GL_COLOR_BUFFER_BIT);
  glBegin(GL_POLYGON);
  glVertex2fv(rectangle[0]);
  glVertex2fv(rectangle[1]);
  glVertex2fv(rectangle[2]);
  glVertex2fv(rectangle[3]);
  glEnd();
  glFlush();
}

void keyboard(unsigned char key, int x, int y) {
  if(key == 'r' || key == 'R') {
    glColor3f(0,0,0);
    glutPostRedisplay();
  }
}

void mouse(int button, int state, int x, int y) {
  if(button == GLUT_LEFT_BUTTON && state == GLUT_DOWN) {
    glColor3f(0,0,0);
    glutPostRedisplay();
  }
}

void myInit() {
  glClearColor(1.0,1.0,1.0,1.0);
  gluOrtho2D(0,500,0,500);
  glColor3f(1,1,1);
}

int main(int argc, char* argv[]) {
  glutInit(&argc, argv);
  glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
  glutInitWindowSize(500,500);
  glutInitWindowPosition(0,0);
  glutCreateWindow("Press R or click on me");
  glutDisplayFunc(display);
  glutKeyboardFunc(keyboard);
  glutMouseFunc(mouse);
  myInit();
  glutMainLoop();
  return 0;
}