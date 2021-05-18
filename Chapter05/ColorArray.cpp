#include<GL/glut.h>
#include<stdlib.h>
#include<stdio.h>
#include<iostream>

GLsizei winWidth = 800, winHeight = 600;
typedef GLint vertex3 [3];
vertex3 pt [8]= { {0,0,0},{0,1,0},{1,0,0},{1,1,0},
						{0,0,1},{0,1,1},{1,0,1},{1,1,1} };

void init(void)
{
	glClearColor(1.0, 1.0, 1.0, 1.0);

	glMatrixMode(GL_PROJECTION);
	gluOrtho2D(0.0, winWidth, 0.0, winHeight);
}

void quad(GLint n1, GLint n2, GLint n3, GLint n4)
{
	glColor3f(1.0, 1.0, 0.0);

	glEnableClientState(GL_VERTEX_ARRAY);
	glVertexPointer(3, GL_INT, 0, pt);
	GLubyte vertIndex[] = { 6,2,4,7,5,1,0,4,7,3,1,5,
										4,0,2,6,2,0,1,3,7,5,4,6 };
	glDrawElements(GL_QUADS, 24, GL_UNSIGNED_BYTE, vertIndex);

	/*glBegin(GL_QUADS);
		glVertex3iv(pt [n1]);
		glVertex3iv(pt [n2]);
		glVertex3iv(pt [n3]);
		glVertex3iv(pt [n4]);
	glEnd();*/

	/*glBegin(GL_LINES);
		glVertex2i(180, 15);
		glVertex2i(10, 145);
	glEnd();*/
	glFlush();
}

void cube()
{
	quad(6, 2, 3, 7);
	quad(5, 1, 0, 4);
	quad(7, 3, 1, 5);
	quad(4, 0, 2, 6);
	quad(2, 0, 1, 3);
	quad(7, 5, 4, 6);
}

void displayFunc()
{
	glClear(GL_COLOR_BUFFER_BIT);
	cube();
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
	glutCreateWindow("ColorArray");
	init();

	glutDisplayFunc(displayFunc);
	glutReshapeFunc(winReshapeFcn);

	glutMainLoop();
}