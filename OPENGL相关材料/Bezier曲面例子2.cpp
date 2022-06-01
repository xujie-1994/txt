#include <stdlib.h>
#include <time.h>
#include <GL/glut.h>
/* ���Ƶ������ */
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
	//����ɫ
	glClearColor(0.0, 0.0, 0.0, 1.0);
	glMap2f(GL_MAP2_VERTEX_3, 0, 1, 3, 4, 0, 1, 12, 4, &ctrlpoints[0][0][0]);
	//�����άӳ��
	glEnable(GL_MAP2_VERTEX_3);
	//��άӳ�䣺x��y����U��V�Ĳ���[0, 1]�����м��ֵ����Ϊ��20��
	glMapGrid2f(20, 0.0, 1.0, 20, 0.0, 1.0);
	//������Ȳ���
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
			glEvalCoord2f((GLfloat)i / 30.0, (GLfloat)j / 8.0);  //�̶�y����ʱx�������������
		glEnd();
 
		glBegin(GL_LINE_STRIP);
		for (i = 0; i <= 30; i++)
			glEvalCoord2f((GLfloat)j / 8.0, (GLfloat)i / 30.0);  //�̶�x����ʱy�������������     
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
	glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB | GLUT_DEPTH);//ʹ��˫����ģʽ����Ȼ���
	glutInitWindowSize(800, 800);
	glutInitWindowPosition(0, 0);
	glutCreateWindow("Bezier�����߿�ģ��");
	init();
	glutDisplayFunc(display);
	glutReshapeFunc(reshape);
	glutMainLoop();
	return 0;
}