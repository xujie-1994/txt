#include <gl\glut.h>
#include <Windows.h>

void draw()
{
    glClearColor(0.0, 0.0, 0.0, 0.0); //设置清除颜色为黑色
    glClear(GL_COLOR_BUFFER_BIT); //用当前缓冲区清除值来清楚缓冲区
    /*
    GL_COLOR_BUFFER_BIT:    当前可写的颜色缓冲
    GL_DEPTH_BUFFER_BIT:    深度缓冲
    GL_ACCUM_BUFFER_BIT:    累积缓冲
　　  GL_STENCIL_BUFFER_BIT:  模板缓冲
    */

    glRectf(-0.5, -0.5, 0.5, 0.5); //用当前的绘图颜色绘制一个填充矩形
    /*
    当前的颜色是白色，可以通过glColor3f修改颜色值
    */

    glFlush(); //将GL命令队列中的命令发送给显卡并清空命令队列，发送完立即返回
}

int main()
{
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB); //设置图形显示模式
    /*
    值                   对应宏定义       意义
    GLUT_RGB            0x0000      指定RGB颜色模式的窗口
    GLUT_RGBA           0x0000      指定RGBA 颜色模式的窗口
    GLUT_INDEX          0x0001      指定颜色索引模式的窗口
    GLUT_SINGLE         0x0000      指定单缓存窗口
    GLUT_DOUBLE         0x0002      指定双缓存窗口
    GLUT_ACCUM          0x0004      窗口使用累加缓存
    GLUT_ALPHA          0x0008      窗口的颜色分量包含 alpha 值
    GLUT_DEPTH          0x0010      窗口使用深度缓存
    GLUT_STENCIL        0x0020      窗口使用模板缓存
    GLUT_MULTISAMPLE    0x0080      指定支持多样本功能的窗口
    GLUT_STEREO         0x0100      指定立体窗口
    GLUT_LUMINANCE      0x0200      窗口使用亮度颜色模型
    */

    glutInitWindowPosition(0, 0); //设置初始窗口的位置(窗口左上角相对于桌面坐标(x,y)
    glutInitWindowSize(500, 500); //设置初始窗口的大小
    glutCreateWindow("OpenGL窗口"); //产生一个顶层窗口，name为窗口的标题
    glutDisplayFunc(draw); //注册当前窗口的显示回调函数
    glutMainLoop(); //让glut程序进入事件循环.一旦调用, 会直到程序结束才返回
	return 0;
}
