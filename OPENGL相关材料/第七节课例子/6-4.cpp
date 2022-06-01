#include"gl/glut.h"
#include"stdio.h"
#include"iostream"
int DefaultWindowWidth = 500, DefaultWindowHeight = 500;//默认的窗口长宽
int NowWindowWidth = DefaultWindowWidth, NowWindowHeight = DefaultWindowHeight;//当前的窗口长宽
 
bool DrawingLine = true;//正在绘制直线
 
enum DrawingState { NonePoint, FirstPoint };//枚举绘制的所有阶段 SecondPoint要不要保留再考虑
static DrawingState NowDrawingState = NonePoint;//NowDrawingState 当前绘制阶段
int MouseX, MouseY;//变换之后的鼠标坐标
 
int DrawPointVertices[4];//存放两个顶点坐标
 
void init()
{
	glClearColor(1.0, 1.0, 1.0, 1.0);       //设置背景色 (R,G,B,alpha)
	glMatrixMode(GL_PROJECTION);            //投影
	gluOrtho2D(0.0, 200.0, 0.0, 150.0);		//(left right bottom top)
}
 
void StartDraw()
{
	glClear(GL_COLOR_BUFFER_BIT);           // 清空原颜色
	glColor3f(1.0, 0.0, 0.0);
	//实时跟随鼠标来实现橡皮筋效果
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
 
//鼠标移动
void onMouseMovePassive(int x, int y) {//坐标转换
	MouseX = x;
	MouseY = NowWindowHeight - y;
	//cout << "MouseX:" << MouseX << ",MouseY:" << MouseY<<endl;
	//正在绘图 实现橡皮筋效果
	if (NowDrawingState == FirstPoint) {
		glutPostRedisplay();
	}
}
 
 
//鼠标按下
void onMouseDown(int button, int state, int x, int y) {
 
	if (state == GLUT_DOWN) {//鼠标按下
		//正在画线
		if (DrawingLine) {
			if (NowDrawingState == NonePoint) {//一个点都没有画
				DrawPointVertices[0] = MouseX;
				DrawPointVertices[1] = MouseY;
				NowDrawingState = FirstPoint;
				return;
			}
			else if (NowDrawingState == FirstPoint) {//已经有了一个点
				DrawPointVertices[2] = MouseX;
				DrawPointVertices[3] = MouseY;
 
				NowDrawingState = NonePoint;//画线结束
				return;
			}
			else {
				return;
			}
		}
	}
}
//窗口大小改变时调用
void changeSize(GLsizei w, GLsizei h) {
	//保存当前窗口的大小
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
	glutReshapeFunc(changeSize);//窗口变化时使图形不会发生变形
	glutPassiveMotionFunc(onMouseMovePassive);//注册鼠标移动
	glutMouseFunc(onMouseDown);//鼠标点击
	glutMainLoop(); 
}
