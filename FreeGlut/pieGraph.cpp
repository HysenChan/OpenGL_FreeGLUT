#include<gl/glut.h>
#include<stdlib.h>
#include<math.h>
#include<stdio.h>

const GLdouble twoPi = 6.283185;

class screenPt
{
public:
	GLint x, y;
	screenPt()
	{
		x = y = 0;
	}
	void setCoords(GLint xCoordValue, GLint yCoordValue)
	{
		x = xCoordValue;
		y = yCoordValue;
	}
	GLint getx() const
	{
		return x;
	}
	GLint gety() const
	{
		return y;
	}
	void incrementx()
	{
		x++;

	}
	void decrementy()
	{
		y--;
	}
};

void line(GLint x1, GLint y1, GLint x2, GLint y2) {
	glClearColor(1.0, 1.0, 1.0, 0.0);
	glClear(GL_COLOR_BUFFER_BIT);
	glColor3f(1.0, 0.0, 0.0);
	glLineWidth(1.0f);
	glBegin(GL_LINES);
	glVertex2f(x1 / 200.0f, y1 / 200.0f);
	glVertex2f(x2 / 200.0f, y2 / 200.0f);
	//glEnd();  
	glFlush();
}

GLsizei winWidth = 400, winHeight = 300;

void init(void)
{
	glClearColor(1.0, 1.0, 1.0, 1.0);

	glMatrixMode(GL_PROJECTION);
	gluOrtho2D(0.0, 200.0, 0.0, 150.0);
}

void circleMidpoint(GLint xc, GLint yc, GLint radius)
{

	screenPt circPt;

	GLint p = 1 - radius;

	circPt.setCoords(0, radius);

	void circlePlotPoints(GLint, GLint, screenPt);
	circlePlotPoints(xc, yc, circPt);

	while (circPt.getx() < circPt.gety())
	{
		circPt.incrementx();
		if (p < 0)
			p += 2 * circPt.getx() + 1;
		else
		{
			circPt.decrementy();
			p += 2 * (circPt.getx() - circPt.gety()) + 1;
		}

		circlePlotPoints(xc, yc, circPt);

	}
}

void circlePlotPoints(GLint xc, GLint yc, screenPt circPt)
{

	line(xc, yc, xc + circPt.getx(), yc + circPt.gety());

	line(xc, yc, xc - circPt.getx(), yc + circPt.gety());

	line(xc, yc, xc + circPt.getx(), yc - circPt.gety());

	line(xc, yc, xc - circPt.getx(), yc - circPt.gety());

	line(xc, yc, xc + circPt.gety(), yc + circPt.getx());

	line(xc, yc, xc - circPt.gety(), yc + circPt.getx());

	line(xc, yc, xc + circPt.gety(), yc - circPt.getx());

	line(xc, yc, xc - circPt.gety(), yc - circPt.getx());

}

void pieChart(void)
{
	screenPt circCtr, piePt;
	GLint radius = winWidth / 4;

	GLdouble sliceAngle, previousSliceAngle = 0.0;

	GLint k, nSlices = 12;
	GLfloat dataValues[12] = { 10.0,7.0,13.0,5.0,13.0,14.0,3.0,16.0,5.0,3.0,17.0,8.0 };
	GLfloat dataSum = 0.0;

	circCtr.x = winWidth / 2;
	circCtr.y = winHeight / 2;
	circleMidpoint(circCtr.x,circCtr.y, radius);

	for (k = 0; k < nSlices; k++)
	{
		dataSum += dataValues[k];
	}

	for (k = 0; k < nSlices; k++)
	{
		sliceAngle = twoPi * dataValues[k] / dataSum + previousSliceAngle;
		piePt.x = circCtr.x + radius * cos(sliceAngle);
		piePt.y = circCtr.y + radius * sin(sliceAngle);
		glBegin(GL_LINES);
			glVertex2i(circCtr.x, circCtr.y);
			glVertex2i(piePt.x, piePt.y);
		glEnd();
		previousSliceAngle = sliceAngle;
	}
}

void displayFcn(void)
{
	glClear(GL_COLOR_BUFFER_BIT);
	glColor3f(0.0, 0.0, 1.0);

	pieChart();
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
	glutInitWindowPosition(100, 100);
	glutInitWindowSize(winWidth, winHeight);
	glutCreateWindow("Pie Chart");

	init();
	glutDisplayFunc(displayFcn);
	glutReshapeFunc(winReshapeFcn);

	glutMainLoop();
}