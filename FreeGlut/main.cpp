//-----����1��-----
//#include<stdio.h>
//#include<Windows.h>
//#include<GL/glut.h>
//
//int main(int argc, char** argv)
//{
//	glutInit(&argc, argv);
//	//��ʾģʽ��ʼ��
//	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB | GLUT_DEPTH);
//	//���崰�ڴ�С
//	glutInitWindowSize(300, 300);
//	//���崰��λ��
//	glutInitWindowPosition(100, 100);
//	//��������
//	glutCreateWindow("TestGL");
//	const char* version = (const char*)glGetString(GL_VERSION);
//	printf("OpernGL�汾:%s\n", version);
//	glutMainLoop();//����GLUT�¼�����ѭ��������ѭ��
//	return 0;
//}

//-----����2��-----
#/*include <windows.h>
#include <stdio.h>
#include <GL/freeglut.h>

int main(int argc, char** argv)
{
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB | GLUT_DEPTH);
	glutInitWindowSize(300, 300);
	glutInitWindowPosition(100, 100);
	glutCreateWindow("OpenGL Version");
	const GLubyte* name = glGetString(GL_VENDOR);
	const GLubyte* biaoshifu = glGetString(GL_RENDERER);
	const GLubyte* OpenGLVersion = glGetString(GL_VERSION);
	const GLubyte* gluVersion = gluGetString(GLU_VERSION);
	printf("OpenGLʵ�ֳ��̵����֣�%s\n", name);
	printf("��Ⱦ����ʶ����%s\n", biaoshifu);
	printf("OOpenGLʵ�ֵİ汾�ţ�%s\n", OpenGLVersion);
	printf("OGLU���߿�汾��%s\n", gluVersion);

	system("pause");

	return 0;
}*/

#include<Windows.h>
#include<stdio.h>
#include<GL/freeglut.h>
#include "main.h"

void init()
{
	glClearColor(1.0, 1.0, 1.0, 1.0);
	glMatrixMode(GL_PROJECTION);
	gluOrtho2D(0.0, 200.0, 0.0, 200.0);
}

void lineSegment()
{
	glClear(GL_COLOR_BUFFER_BIT);
	glColor3f(0.0, 0.4, 0.2);

	glBegin(GL_LINES);
		glVertex2i(180, 15);
		glVertex2i(10, 145);
	glEnd();

	glFlush();
}

int main(int argc, char** argv)
{
	glutInit(&argc, argv);
	glutInitWindowPosition(20, 20);
	glutInitWindowSize(640, 960);
	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
	glutCreateWindow("An Example OpenGL Program");

	init();
	glutDisplayFunc(lineSegment);
	glutMainLoop();

	return 0;
}