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
#include <windows.h>
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
}