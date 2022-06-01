#include <stdlib.h>
#include <time.h>
#include <GL/glut.h>
/* 控制点的坐标 */
GLfloat ctrlpoints[4][4][3] = {
		{ { -1.5, -1.5, 2.0 },
		{ -0.5, -1.5, 2.0 },
		{ 0.5, -1.5, -1.0 },
		{ 1.5, -1.5, 2.0 }
		},
 
		{ { -1.5, -0.5, 1.0 },
		{ -0.5, 1.5, 2.0 },
		{ 0.5, 0.5, 1.0 },
		{ 1.5, -0.5, -1.0 } },
 
		{ { -1.5, 0.5, 2.0 },
		{ -0.5, 0.5, 1.0 },
		{ 0.5, 0.5, 3.0 },
		{ 1.5, -1.5, 1.5 } },
 
		{ { -1.5, 1.5, -2.0 },
		{ -0.5, 1.5, -2.0 },
		{ 0.5, 0.5, 1.0 },
		{ 1.5, 1.5, -1.0 } } };
 
void init(void)
{
	//背景色
	glClearColor(0.0, 0.0, 0.0, 1.0);
	glMap2f(GL_MAP2_VERTEX_3, 0, 1, 3, 4, 0, 1, 12, 4, &ctrlpoints[0][0][0]);
	//允许二维映射
	glEnable(GL_MAP2_VERTEX_3);
	//二维映射：x、y方向U和V的参数[0, 1]，且中间插值数量为各20个
	glMapGrid2f(20, 0.0, 1.0, 20, 0.0, 1.0);
	//允许深度测试
	glEnable(GL_DEPTH_TEST);
	glEnable(GL_BLEND);
	glEnable(GL_LINE_SMOOTH);
	glHint(GL_LINE_SMOOTH_HINT, GL_FASTEST);  // Antialias the lines
	glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
}
void display(void)
{
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	glColor3f(0.0, 1.0, 0.0);
	glPushMatrix();
	glRotatef(0.1, 1.0, 1.0, 1.0);
	int i, j;
	for (j = 0; j <= 8; j++)     {
		glBegin(GL_LINE_STRIP);
		for (i = 0; i <= 30; i++)
			glEvalCoord2f((GLfloat)i / 30.0, (GLfloat)j / 8.0);  //固定y坐标时x方向的网格坐标
		glEnd();
 
		glBegin(GL_LINE_STRIP);
		for (i = 0; i <= 30; i++)
			glEvalCoord2f((GLfloat)j / 8.0, (GLfloat)i / 30.0);  //固定x坐标时y方向的网格坐标     
		glEnd();
	}
	glPopMatrix();
	glutSwapBuffers();
}
void reshape(GLsizei w, GLsizei h)
{
	glViewport(0, 0, w, h);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	if (w <= h)
		glOrtho(-5.0, 5.0, -5.0*(GLfloat)h / (GLfloat)w, 5.0*(GLfloat)h / (GLfloat)w, -5.0, 5.0);
	else
		glOrtho(-5.0*(GLfloat)w / (GLfloat)h, 5.0*(GLfloat)w / (GLfloat)h, -5.0, 5.0, -5.0, 5.0);
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
}
int main(int argc, char** argv)
{
	srand((unsigned int)time(0));
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB | GLUT_DEPTH);//使用双缓存模式和深度缓存
	glutInitWindowSize(800, 800);
	glutInitWindowPosition(0, 0);
	glutCreateWindow("Bezier曲面线框模型");
	init();
	glutDisplayFunc(display);
	glutReshapeFunc(reshape);
	glutMainLoop();
	return 0;
}