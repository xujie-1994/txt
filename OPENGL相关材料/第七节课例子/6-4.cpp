#include"gl/glut.h"
#include"stdio.h"
#include"iostream"
int DefaultWindowWidth = 500, DefaultWindowHeight = 500;//Ĭ�ϵĴ��ڳ���
int NowWindowWidth = DefaultWindowWidth, NowWindowHeight = DefaultWindowHeight;//��ǰ�Ĵ��ڳ���
 
bool DrawingLine = true;//���ڻ���ֱ��
 
enum DrawingState { NonePoint, FirstPoint };//ö�ٻ��Ƶ����н׶� SecondPointҪ��Ҫ�����ٿ���
static DrawingState NowDrawingState = NonePoint;//NowDrawingState ��ǰ���ƽ׶�
int MouseX, MouseY;//�任֮����������
 
int DrawPointVertices[4];//���������������
 
void init()
{
	glClearColor(1.0, 1.0, 1.0, 1.0);       //���ñ���ɫ (R,G,B,alpha)
	glMatrixMode(GL_PROJECTION);            //ͶӰ
	gluOrtho2D(0.0, 200.0, 0.0, 150.0);		//(left right bottom top)
}
 
void StartDraw()
{
	glClear(GL_COLOR_BUFFER_BIT);           // ���ԭ��ɫ
	glColor3f(1.0, 0.0, 0.0);
	//ʵʱ���������ʵ����Ƥ��Ч��
	if (NowDrawingState == FirstPoint) {
		if (DrawingLine) {
			glBegin(GL_LINES);
			glVertex2i(DrawPointVertices[0], DrawPointVertices[1]);
			glVertex2i(MouseX, MouseY);
			glEnd();
		}
	}
 
	glFlush();
}
 
//����ƶ�
void onMouseMovePassive(int x, int y) {//����ת��
	MouseX = x;
	MouseY = NowWindowHeight - y;
	//cout << "MouseX:" << MouseX << ",MouseY:" << MouseY<<endl;
	//���ڻ�ͼ ʵ����Ƥ��Ч��
	if (NowDrawingState == FirstPoint) {
		glutPostRedisplay();
	}
}
 
 
//��갴��
void onMouseDown(int button, int state, int x, int y) {
 
	if (state == GLUT_DOWN) {//��갴��
		//���ڻ���
		if (DrawingLine) {
			if (NowDrawingState == NonePoint) {//һ���㶼û�л�
				DrawPointVertices[0] = MouseX;
				DrawPointVertices[1] = MouseY;
				NowDrawingState = FirstPoint;
				return;
			}
			else if (NowDrawingState == FirstPoint) {//�Ѿ�����һ����
				DrawPointVertices[2] = MouseX;
				DrawPointVertices[3] = MouseY;
 
				NowDrawingState = NonePoint;//���߽���
				return;
			}
			else {
				return;
			}
		}
	}
}
//���ڴ�С�ı�ʱ����
void changeSize(GLsizei w, GLsizei h) {
	//���浱ǰ���ڵĴ�С
	NowWindowWidth = w;
	NowWindowHeight = h;
	glViewport(0, 0, w, h);
 
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluOrtho2D(0.0, NowWindowWidth, 0.0, NowWindowHeight); 
}
 
int main(int argc, char ** argv)
{
 
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);  
	glutInitWindowPosition(400, 400);       
 
	glutInitWindowSize(DefaultWindowWidth, DefaultWindowHeight);
	glViewport(0,0,DefaultWindowWidth,DefaultWindowHeight);
	gluOrtho2D(1,1,1,1);
	glutCreateWindow("Draw"); 
	init();                                 
	glutDisplayFunc(StartDraw);
	glutReshapeFunc(changeSize);//���ڱ仯ʱʹͼ�β��ᷢ������
	glutPassiveMotionFunc(onMouseMovePassive);//ע������ƶ�
	glutMouseFunc(onMouseDown);//�����
	glutMainLoop(); 
}
