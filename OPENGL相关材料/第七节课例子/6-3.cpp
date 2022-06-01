#include <glut.h> 
#include <Windows.h>
 
GLfloat angle = 0.0f; 
 
void CreateDisplayLists()
{
	//List 1 定义模型视图矩阵
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
 
	//List 2 定义实体矩形
	if(!glIsList((GLuint)2))
	{
		glNewList(2,GL_COMPILE);
		glBegin(GL_QUADS);
 
		//底面
		glColor3f(1,0,0);
		glVertex3f(-5,-5,-5);
		glVertex3f(5,-5,-5);
		glColor3f(0,0,1);
		glVertex3f(5,5,-5);
		glVertex3f(-5,5,-5);
		//侧面A
		glColor3f(0,0,1);
		glVertex3f(-5,-5,-5);
		glVertex3f(5,-5,-5);
		glColor3f(0,1,0);
		glVertex3f(5,-5,5);
		glVertex3f(-5,-5,5);
		//侧面B
		glColor3f(0,1,0);
		glVertex3f(5,-5,-5);
		glVertex3f(5,5,-5);
		glColor3f(0,1,1);
		glVertex3f(5,5,5);
		glVertex3f(5,-5,5);
		//侧面C
		glColor3f(1,1,0);
		glVertex3f(5,5,-5);
		glVertex3f(-5,5,-5);
		glColor3f(1,0,1);
		glVertex3f(-5,5,5);
		glVertex3f(5,5,5);
		//侧面D
		glColor3f(1,0,1);
		glVertex3f(-5,5,-5);
		glVertex3f(-5,-5,-5);
		glColor3f(0,1,0);
		glVertex3f(-5,-5,5);
		glVertex3f(-5,5,5);
		//顶面
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
	glEnable(GL_DEPTH_TEST);   //深度缓存
	glClearColor(0.1,0.1,0.3,0);
	glClear(GL_COLOR_BUFFER_BIT|GL_DEPTH_BUFFER_BIT);
	glCallList(1);
	glRotatef(angle,1,0,0);
	glRotatef(angle,0,1,0);
	glRotatef(angle,1,0,1);
	glCallList(2);  //绘制模型
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
	CreateDisplayLists();  //创建显示列表
	glutDisplayFunc(&myDisplay);   
	glutIdleFunc(&myIdle);    //使另一个函数在程序空闲的时候就会被调用 
	glutMainLoop();   
	return 0; 
}
