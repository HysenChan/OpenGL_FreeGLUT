#include<Windows.h>
#include<stdio.h>
#include<GL/freeglut.h>
#include "main.h"

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

void init()							 
	{										
		glClearColor(1.0, 1.0, 1.0, 1.0);
	glMatrixMode(GL_PROJECTION);
}

int main(int argc, char** argv)
{
	glutInit(&argc, argv);
	glutInitWindowPosition(300, 20);
	glutInitWindowSize(640, 960);
	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
	glutCreateWindow("OpenGL");

	init();
	glutDisplayFunc(cube);
	glutMainLoop();

	return 0;
}