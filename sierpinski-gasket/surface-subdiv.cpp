#include <iostream>
#include <GL/glut.h>
#include <GL/gl.h>
using namespace std;

typedef float point[3];
point tetra[4] = {
  {0, 250, -250},
  {0, 0, 250},
  {250, -250, 250},
  {-250, -250, -250}
};
int iterations;

void drawTriangle(point p1, point p2, point p3) {
  glBegin(GL_TRIANGLES);
  glVertex3fv(p1);
  glVertex3fv(p2);
  glVertex3fv(p3);
  glEnd();
}

void divideTriangle(point p1, point p2, point p3, int iter) {
  point mid[3];
  int j;

  if(iter > 0) {
    for(j=0;j<3;j++) mid[0][j] = (p1[j] + p2[j])/2;
    for(j=0;j<3;j++) mid[1][j] = (p2[j] + p3[j])/2;
    for(j=0;j<3;j++) mid[2][j] = (p1[j] + p3[j])/2;

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
  glColor3f(1.0,0.0,0.0);
  divideTriangle(tetra[0], tetra[1], tetra[2], iterations);
  glColor3f(0.0,0.0,0.0);
  divideTriangle(tetra[0], tetra[2], tetra[3], iterations);
  glColor3f(0.0,1.0,0.0);
  divideTriangle(tetra[1], tetra[2], tetra[3], iterations);
  glColor3f(0.0,0.0,1.0);
  divideTriangle(tetra[0], tetra[1], tetra[3], iterations);
  glFlush();
}

void myInit() {
  glClearColor(1.0,1.0,1.0,1.0);
  glOrtho(-250,250,-250,250,-250,250);
}

int main(int argc, char* argv[]) {
  cout<<"Enter number of iterations to create 3D gasket"<<endl;
  cin>>iterations;
  glutInit(&argc, argv);
  glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
  glutInitWindowSize(500,500);
  glutInitWindowPosition(0,0);
  glutCreateWindow("Sierpinski Gasket - Surface Subdivision");
  glutDisplayFunc(display);
  myInit();
  glutMainLoop();
  return 0;
}