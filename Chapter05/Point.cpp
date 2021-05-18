#include<GL/glut.h>
#include<stdlib.h>
#include<stdio.h>
#include<iostream>
GLsizei winWidth = 800, winHeight = 600;

void init(void)
{
	glClearColor(1.0, 1.0, 1.0, 1.0);
	glMatrixMode(GL_PROJECTION);
	gluOrtho2D(0.0, winWidth, 0.0, winHeight);
}

void displayFunc()
{
	glClear(GL_COLOR_BUFFER_BIT);
	glColor3f(1.0, 0.0, 0.0);

	glBegin(GL_POINTS);
		glVertex2i(50, 100);
		glPointSize(2.0);//调整点像素的大小
		glColor3f(0.0, 1.0, 0.0);
		glVertex2i(75, 150);
		glPointSize(3.0);
		glColor3f(0.0, 0.0, 1.0);
		glVertex2i(100, 200);
	glEnd();

	glFlush();
}

void winReshapeFcn(GLint newWidth, GLint newHeight)
{
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluOrtho2D(0.0, GLdouble(newWidth), 0.0, GLdouble(newHeight));

	glClear(GL_COLOR_BUFFER_BIT);

	winWidth = newWidth;
	winHeight = newHeight;
}

int main(int argc, char** argv)
{
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
	glutInitWindowPosition(10, 10);
	glutInitWindowSize(winWidth, winHeight);
	glutCreateWindow("Point");
	init();

	glutDisplayFunc(displayFunc);
	glutReshapeFunc(winReshapeFcn);

	glutMainLoop();
}