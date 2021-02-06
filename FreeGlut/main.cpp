//-----方法1：-----
//#include<stdio.h>
//#include<Windows.h>
//#include<GL/glut.h>
//
//int main(int argc, char** argv)
//{
//	glutInit(&argc, argv);
//	//显示模式初始化
//	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB | GLUT_DEPTH);
//	//定义窗口大小
//	glutInitWindowSize(300, 300);
//	//定义窗口位置
//	glutInitWindowPosition(100, 100);
//	//创建窗口
//	glutCreateWindow("TestGL");
//	const char* version = (const char*)glGetString(GL_VERSION);
//	printf("OpernGL版本:%s\n", version);
//	glutMainLoop();//进入GLUT事件处理循环，无限循环
//	return 0;
//}

//-----方法2：-----
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
	printf("OpenGL实现厂商的名字：%s\n", name);
	printf("渲染器标识符：%s\n", biaoshifu);
	printf("OOpenGL实现的版本号：%s\n", OpenGLVersion);
	printf("OGLU工具库版本：%s\n", gluVersion);

	system("pause");

	return 0;
}*/

#include<Windows.h>
#include<stdio.h>
#include<GL/freeglut.h>
#include "main.h"

struct Width
{
	int min = 0.0;
	int max = 160;
};
struct Height
{
	int min = 0.0;
	int max = 240.0;
};

void init()
{
	Width x;
	Height y;
	
	glClearColor(1.0, 1.0, 1.0, 1.0);
	glMatrixMode(GL_PROJECTION);
	gluOrtho2D(x.min, x.max, y.min, y.max);
}

void lineSegment()
{
	glClear(GL_COLOR_BUFFER_BIT);
	glColor3f(0.0, 0.0, 0.0);

	/*glBegin(GL_LINES);
		glVertex2i(180, 15);
		glVertex2i(10, 145);
	glEnd();*/

	int point1[] = { 50,100 };
	int point2[] = { 75,100 };
	int point3[] = { 100,200 };

	glBegin(GL_LINE_LOOP);//GL_LINES:连起来1-2；GL_LINE_STRIP:连起来1-2-3；GL_LINE_LOOP:连起来了1-2-3-1
		glVertex2iv(point1);
		glVertex2iv(point2);
		glVertex2iv(point3);
	glEnd();

	glFlush();
}

GLenum errorCheck()
{
	GLenum code;
	const GLubyte* string;
	code = glGetError();
	if (code != GL_NO_ERROR)
	{
		string = gluErrorString(code);
		fprintf(stderr, "OpenGL error:%s\n", string);
	}
	return code;
}

int main(int argc, char** argv)
{
	glutInit(&argc, argv);
	glutInitWindowPosition(300, 20);
	glutInitWindowSize(640, 960);
	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
	glutCreateWindow("OpenGL");

	init();
	glutDisplayFunc(lineSegment);
	glutMainLoop();
	errorCheck();

	return 0;
}