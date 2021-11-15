#include <iostream>
#include <GL/glut.h>
#include <GL/gl.h>
using namespace std;

typedef float point[2];
point points[3];
int count = 0;
GLint windowHeight = 500, windowWidth = 500;

void display() {
  glClear(GL_COLOR_BUFFER_BIT);
  glBegin(GL_TRIANGLES);
  glVertex2fv(points[0]);
  glVertex2fv(points[1]);
  glVertex2fv(points[2]);
  glEnd();
  glFlush();
}

void mouse(int button, int state, int x, int y) {
  if(button == GLUT_RIGHT_BUTTON && state == GLUT_DOWN)
    exit(0);
  if(button == GLUT_LEFT_BUTTON && state == GLUT_DOWN) {
    points[count][0] = (float) x/(windowWidth/2)-1.0;
    points[count][1] = (float) (windowHeight-y)/(windowHeight/2) - 1.0;
    count++;
  }

  if(count == 3) {
    glutPostRedisplay();
    count = 0;
  }
}

void reshape(GLsizei w, GLsizei h) {
  windowWidth = w;
  windowHeight = h;
  glViewport(0,0,windowWidth, windowHeight);
}

void keyboard(unsigned char key, int x, int y) {
  if(key == 'q' || key == 'Q') exit(0);
}

void myInit() {
  glClearColor(1.0,1.0,1.0,1.0);
  glColor3f(0.0,0.0,0.0);
}

int main(int argc, char* argv[]) {
  glutInit(&argc, argv);
  glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
  glutInitWindowSize(windowHeight, windowWidth);
  glutInitWindowPosition(0,0);
  glutCreateWindow("Draw a triangle!");
  glutDisplayFunc(display);
  glutMouseFunc(mouse);
  glutReshapeFunc(reshape);
  glutKeyboardFunc(keyboard);
  myInit();
  glutMainLoop();
  return 0;
}