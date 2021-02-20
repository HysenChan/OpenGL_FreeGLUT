#include<Windows.h>
#include<stdio.h>
#include<GL/freeglut.h>
#include "main.h"
#include<math.h>

typedef GLint vertex3[3];
vertex3 pt[8] = { {0,0,0},{0,1,0},{1,0,0},{1,1,0},
							{0,0,1},{0,1,1},{1,0,1}, {1,1,1,} };

void cube()
{
	glClear(GL_COLOR_BUFFER_BIT);
	glColor3f(0.0, 0.0, 0.0);

	glEnableClientState(GL_VERTEX_ARRAY);
	glVertexPointer(3, GL_INT, 0, pt);

	GLubyte vertIndex[] = { 6, 2, 3, 7, 5, 1, 0, 4, 7, 3, 1, 5, 4, 0, 2, 6, 2, 0, 1, 3, 7, 5, 4, 6 };

	glDrawElements(GL_QUADS, 24, GL_UNSIGNED_BYTE, vertIndex);

	glFlush();
}

GLubyte bitshape[20] = {
	0x1c,0x00,0x1c,0x00,0x1c,0x00,0x1c,0x00,0x1c,0x00,
	0xff,0x80,0x7f,0x00,0x3e,0x00,0x1c,0x00,0x08,0x00
};

void shape()
{
	glClear(GL_COLOR_BUFFER_BIT);
	glColor3f(0.0, 0.0, 0.0);

	glPixelStorei(GL_UNPACK_ALIGNMENT, 1);

	glRasterPos2i(30, 40);
	glBitmap(9, 10, 0.0, 0.0, 20.0, 15.0, bitshape);

	glFlush();
}

const double TWO_PI = 6.2831853;

GLuint regHex;

GLdouble theta;
GLint x, y, k;

void displayTable()
{
	glClear(GL_COLOR_BUFFER_BIT);
	glColor3f(0.0, 0.0, 0.0);

	regHex = glGenLists(1);
	glNewList(regHex, GL_COMPILE);
		glBegin(GL_POLYGON);
		for (k = 0; k < 6; k++)
		{
			theta = TWO_PI * k / 6.0;
			x = 200 + 150 * cos(theta);
			y = 200 + 150 * sin(theta);
			glVertex2i(x, y);
		}
		glEnd();
	glEndList();
	glCallList(regHex);

	glFlush();
}

void init()							 
{										
	glClearColor(1.0, 1.0, 1.0, 1.0);
	glMatrixMode(GL_PROJECTION);
}

int main_04_09(int argc, char** argv)
{
	glutInit(&argc, argv);
	glutInitWindowPosition(20, 20);
	glutInitWindowSize(1280, 720);
	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
	glutCreateWindow("OpenGL");

	init();
	//glutDisplayFunc(cube);
	//glutDisplayFunc(shape);
	//glutDisplayFunc(displayTable);
	glutMainLoop();

	return 0;
}