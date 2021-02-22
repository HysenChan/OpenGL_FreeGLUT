//#include<gl/glut.h>
//#include<math.h>
//#include<stdlib.h>
//
//const double TWO_PI = 6.2831853;
//
//GLsizei winWidth = 400, winHeight = 400;
//GLuint regHex;
//
//class screenPt
//{
//public:
//	screenPt()
//	{
//		x = y = 0;
//	}
//
//	void setCoords(GLint xCoord, GLint yCoord)
//	{
//		x = xCoord;
//		y = yCoord;
//	}
//
//	GLint getx()const
//	{
//		return x;
//	}
//
//	GLint gety()const
//	{
//		return y;
//	}
//
//private:
//	GLint x, y;
//};
//
//static void init(void)
//{
//	screenPt hexVertex, circCtr;
//	GLdouble theta;
//	GLint k;
//
//	circCtr.setCoords(winWidth / 2, winHeight / 2);
//
//	glClearColor(1.0, 1.0, 1.0, 0.0);
//
//	regHex = glGenLists(1);
//	glNewList(regHex, GL_COMPILE);
//		glColor3f(1.0, 0.0, 0.0);
//		glBegin(GL_POLYGON);
//			for (k = 0; k < 6; k++)
//			{
//				theta = TWO_PI * k / 6.0;
//				hexVertex.setCoords((int)(circCtr.getx() + 150 * cos(theta)),
//					(int)(circCtr.gety() + 150 * sin(theta)));
//				glVertex2i(hexVertex.getx(), hexVertex.gety());
//			}
//		glEnd();
//	glEndList();
//}
//
//void regHexagon(void)
//{
//	glClear(GL_COLOR_BUFFER_BIT);
//	glCallList(regHex);
//	glFlush();
//}
//
//void winReshapeFcn(int newWidth, int newHeight)
//{
//	glMatrixMode(GL_PROJECTION);
//	glLoadIdentity();
//	gluOrtho2D(0.0, (GLdouble)newWidth, 0.0, (GLdouble)newHeight);
//
//	glClear(GL_COLOR_BUFFER_BIT);
//}
//
//int main_04_16(int argc, char** argv)
//{
//	glutInit(&argc, argv);
//	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
//	glutInitWindowPosition(100, 100);
//	glutInitWindowSize(winWidth, winHeight);
//	glutCreateWindow("Reshape-Function & Display-List Example");
//
//	init();
//	glutDisplayFunc(regHexagon);
//	glutReshapeFunc(winReshapeFcn);
//
//	glutMainLoop();
//}