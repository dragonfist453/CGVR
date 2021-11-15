#include <iostream>
#include <GL/glut.h>
#include <GL/gl.h>
using namespace std;

typedef float point[2];
point triangle[3] = {
  {0.0, 0.0},
  {250.0, 500.0},
  {500.0, 0.0}
};
int iterations;

void drawTriangle(point p1, point p2, point p3) {
  glBegin(GL_TRIANGLES);
  glVertex2fv(p1);
  glVertex2fv(p2);
  glVertex2fv(p3);
  glEnd();
}

void divideTriangle(point p1, point p2, point p3, int iter) {
  point mid[3];
  int j;

  if(iter > 0) {
    for(j=0;j<2;j++) mid[0][j] = (p1[j] + p2[j])/2;
    for(j=0;j<2;j++) mid[1][j] = (p2[j] + p3[j])/2;
    for(j=0;j<2;j++) mid[2][j] = (p1[j] + p3[j])/2;

    divideTriangle(p1, mid[0], mid[2], iter-1);
    divideTriangle(mid[0], p2, mid[1], iter-1);
    divideTriangle(mid[2], mid[1], p3, iter-1);
  }
  else {
    drawTriangle(p1, p2, p3);
  }
}

void display() {
  glClear(GL_COLOR_BUFFER_BIT);
  divideTriangle(triangle[0], triangle[1], triangle[2], iterations);
  // drawTriangle(triangle[0], triangle[1], triangle[2]);
  glFlush();
}

void myInit() {
  glClearColor(1.0,1.0,1.0,1.0);
  gluOrtho2D(0.0,500.0,0.0,500.0);
  glColor3f(0.0,0.0,0.0);
}

int main(int argc, char* argv[]) {
  cout<<"Input number of iterations to create the 2D gasket"<<endl;
  cin>>iterations;
  glutInit(&argc, argv);
  glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
  glutInitWindowSize(500,500);
  glutInitWindowPosition(0,0);
  glutCreateWindow("2D Sierpinski Gasket");
  glutDisplayFunc(display);
  myInit();
  glutMainLoop();
  return 0;
}