#include<iostream>
#include <math.h>
#include<Windows.h>
#include <GL/glut.h>

using namespace std;

GLsizei winWidth = 500, winHeight = 500;

void init()
{
    glClearColor(1.0, 1.0, 1.0, 0.0);
}

void wireQuadSurfs()
{
    glClear(GL_COLOR_BUFFER_BIT);
    glColor3f(0.0, 0.0, 1.0);

    gluLookAt(2.0, 2.0, 2.0, 0.0, 0.0, 0.0, 0.0, 0.0, 1.0);

    glPushMatrix();
    glTranslatef(1.0, 1.0, 1.0);
    //球面，半径为0.5
    glutWireSphere(0.50, 8, 6);
    glPopMatrix();
    
    glPushMatrix();
    glTranslatef(1.0, -0.5, 0.5);
    //圆锥面，底面半径为0.5，高位1.5
    glutWireCone(0.5, 1.5, 7, 6);
    glPopMatrix();

    GLUquadricObj *cylinder;
    glPushMatrix();
    glTranslatef(0.0, 1.5, 0.8);
    //激活二次曲面绘制器
    cylinder = gluNewQuadric();
    //每对顶点之间用线连接，按线框图形式显示
    gluQuadricDrawStyle(cylinder, GLU_LINE);
    //生成圆柱面
    gluCylinder(cylinder, 0.5, 0.5, 1.5, 6, 4);
    glPopMatrix();

    glFlush();
}



void winReshapeFcn(GLint newWidth, GLint newHeight)
{
    glViewport(0, 0, (GLsizei)newWidth, (GLsizei)newHeight);

    glMatrixMode(GL_PROJECTION);
    glOrtho(-2.0, 2.0, -2.0, 2.0, 0.0, 5.0);

    glMatrixMode(GL_MODELVIEW);

    glClear(GL_COLOR_BUFFER_BIT);
}


int main(int argc, char* argv[])
{
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_RGB | GLUT_SINGLE);
    glutInitWindowPosition(100, 100);

    glutInitWindowSize(winWidth, winHeight);
    glutCreateWindow("球面-圆锥面-圆柱面");
    init();
    glutDisplayFunc(wireQuadSurfs);
    glutReshapeFunc(winReshapeFcn);
    glutMainLoop();

    system("pause");
    return 0;
}