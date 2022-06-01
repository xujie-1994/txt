#include <glut.h> 
#include <Windows.h>
 
GLfloat angle = 0.0f; 
 
void CreateDisplayLists()
{
	//List 1 ����ģ����ͼ����
	if(!glIsList((GLuint)1))
	{
		glNewList(1,GL_COMPILE);
		glMatrixMode(GL_PROJECTION);
		glLoadIdentity();
		gluPerspective(75,1,2,50);
 
		glMatrixMode(GL_MODELVIEW);
		glLoadIdentity();
		gluLookAt(0,25,25,0,0,0,0,1,0);
		glEndList();
	}
 
	//List 2 ����ʵ�����
	if(!glIsList((GLuint)2))
	{
		glNewList(2,GL_COMPILE);
		glBegin(GL_QUADS);
 
		//����
		glColor3f(1,0,0);
		glVertex3f(-5,-5,-5);
		glVertex3f(5,-5,-5);
		glColor3f(0,0,1);
		glVertex3f(5,5,-5);
		glVertex3f(-5,5,-5);
		//����A
		glColor3f(0,0,1);
		glVertex3f(-5,-5,-5);
		glVertex3f(5,-5,-5);
		glColor3f(0,1,0);
		glVertex3f(5,-5,5);
		glVertex3f(-5,-5,5);
		//����B
		glColor3f(0,1,0);
		glVertex3f(5,-5,-5);
		glVertex3f(5,5,-5);
		glColor3f(0,1,1);
		glVertex3f(5,5,5);
		glVertex3f(5,-5,5);
		//����C
		glColor3f(1,1,0);
		glVertex3f(5,5,-5);
		glVertex3f(-5,5,-5);
		glColor3f(1,0,1);
		glVertex3f(-5,5,5);
		glVertex3f(5,5,5);
		//����D
		glColor3f(1,0,1);
		glVertex3f(-5,5,-5);
		glVertex3f(-5,-5,-5);
		glColor3f(0,1,0);
		glVertex3f(-5,-5,5);
		glVertex3f(-5,5,5);
		//����
		glColor3f(1,1,0);
		glVertex3f(-5,-5,5);
		glVertex3f(5,-5,5);
		glColor3f(0,0,1);
		glVertex3f(5,5,5);
		glVertex3f(-5,5,5);
		glEnd();
		glEndList();
	}
}
 
void myDisplay(void) 
{
	glEnable(GL_DEPTH_TEST);   //��Ȼ���
	glClearColor(0.1,0.1,0.3,0);
	glClear(GL_COLOR_BUFFER_BIT|GL_DEPTH_BUFFER_BIT);
	glCallList(1);
	glRotatef(angle,1,0,0);
	glRotatef(angle,0,1,0);
	glRotatef(angle,1,0,1);
	glCallList(2);  //����ģ��
	glTranslatef(-10,0,-10);
	glCallList(2);
	glTranslatef(20,0,20);
	glCallList(2);
	glutSwapBuffers();
}  
 
void myIdle(void) 
{    
	angle+=0.05f; 
	if( angle >= 360.0f )    
		angle = 0.0f;    
	myDisplay();
} 
 
int main(int argc, char* argv[]) 
{   
	glutInit(&argc, argv); 
	glutInitDisplayMode(GLUT_RGBA | GLUT_DOUBLE);
	glutInitWindowPosition(200, 200);  
	glutInitWindowSize(400, 400);   
	glutCreateWindow("OpenGL"); 
	CreateDisplayLists();  //������ʾ�б�
	glutDisplayFunc(&myDisplay);   
	glutIdleFunc(&myIdle);    //ʹ��һ�������ڳ�����е�ʱ��ͻᱻ���� 
	glutMainLoop();   
	return 0; 
}
