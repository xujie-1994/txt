#include <gl\glut.h>

void draw()
{
    glClearColor(0.0, 0.0, 0.0, 0.0);//���������ɫΪ��ɫ
    glClear(GL_COLOR_BUFFER_BIT);

    //����


    //��ɫ����
    glColor3f(1.0, 0.0, 0.0); 
    glBegin(GL_POINTS);
    glVertex2f(0.0, 0.0);
    glVertex2f(0.1, 0.1);
    glVertex2f(0.1, 0.2);
    glVertex2f(0.1, 0.3);
    glVertex2f(0.1, 0.4);
    glEnd();

    //��ɫ����
    glColor3f(0.0, 1.0, 0.0); 
    glBegin(GL_LINES);
    glVertex2f(0.0, 0.0);
    glVertex2f(0.0, -0.1);
    glVertex2f(-0.1, 0.0);
    glVertex2f(-0.1, -0.1);
    glEnd();

    //��ɫ�����ڵ���������β��������
    glColor3f(0.0, 0.0, 1.0); 
    glBegin(GL_LINE_STRIP);
    glVertex2f(-0.2, 0.0);
    glVertex2f(-0.2, -0.1);
    glVertex2f(-0.3, 0.0);
    glVertex2f(-0.3, -0.1);
    glEnd();

    //��ɫ�����ڵ���������β������
    glColor3f(1.0, 0.5, 0.5); 
    glBegin(GL_LINE_LOOP);
    glVertex2f(-0.4, 0.0);
    glVertex2f(-0.4, -0.1);
    glVertex2f(-0.5, 0.0);
    glVertex2f(-0.5, -0.1);
    glEnd();

    //�ٻ�ɫ�������
    glColor3f(1.0, 0.5, 0.25); 
    glBegin(GL_POLYGON);
    glVertex2f(-0.1, 0.1);
    glVertex2f(-0.2, 0.1);
    glVertex2f(-0.3, 0.3);
    glVertex2f(-0.2, 0.5);
    glVertex2f(-0.1, 0.3);
    glEnd();

    //����ɫ������棬ÿ�ĸ��㻭һ���ı��Σ����ڲ�����
    glColor3f(0.0, 1.0, 1.0); 
    glBegin(GL_QUADS);
    glVertex2f(-0.3, 0.1);
    glVertex2f(-0.4, 0.1);
    glVertex2f(-0.5, 0.3);
    glVertex2f(-0.4, 0.5);
    glVertex2f(-0.5, 0.1);
    glVertex2f(-0.6, 0.1);
    glVertex2f(-0.7, 0.3);
    glVertex2f(-0.6, 0.5);
    glEnd();

    //��ɫ������棬ÿ�����㹹��һ���ߣ�ÿ�����߹���һ���ı���
    glBegin(GL_QUAD_STRIP);
    //��1
    glColor3f(1.0, 0.0, 0.0);
    glVertex2f(-0.3, 0.6);
    glVertex2f(-0.2, 0.8);
    //��2
    glColor3f(0.0, 1.0, 0.0);
    glVertex2f(-0.4, 0.6);
    glVertex2f(-0.5, 0.9);
    //��3
    glColor3f(0.0, 0.0, 1.0);
    glVertex2f(-0.5, 0.5);
    glVertex2f(-0.7, 0.7);
    glEnd();

    //��ɫ���������(��ÿ������Χ�ɵ������ν�����䣬���ڵĵ�֮�䲻���)
    glColor3f(0.5, 0.25, 0.0); 
    glBegin(GL_TRIANGLES);
    glVertex2f(0.2, 0.1);
    glVertex2f(0.3, 0.2);
    glVertex2f(0.4, 0.1);
    glVertex2f(0.5, 0.1);
    glVertex2f(0.6, 0.3);
    glVertex2f(0.7, 0.1);
    glEnd();

    //��ɫ���������(��ÿ������Χ�ɵ������ν�����䣬���ڵĵ�֮�����)
    glColor3f(1.0, 1.0, 1.0);
    glBegin(GL_TRIANGLE_STRIP);
    glVertex2f(0.2, 0.4);
    glVertex2f(0.3, 0.7);
    glVertex2f(0.4, 0.4);
    glVertex2f(0.5, 0.8);
    glVertex2f(0.6, 0.4);
    glEnd();

    //����ɫ���������(��ÿ������Χ�ɵ������ν�����䣬���ڵĵ�֮�����)
    glColor3f(0.5, 0.5, 1.0);
    glBegin(GL_TRIANGLE_FAN);
    glVertex2f(0.2, -0.2);
    glVertex2f(0.2, -0.5);
    glVertex2f(0.3, -0.4);
    glVertex2f(0.4, -0.3);
    glVertex2f(0.3, -0.1);
    glEnd();

    glFlush();
}

void reshape(int x, int y)
{
    int dis = x > y ? y : x; //ȡС��
    glViewport(0, 0, dis, dis);
}

void main()
{
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGBA);
    glutInitWindowPosition(0, 0);
    glutInitWindowSize(500, 500);
    glutCreateWindow("���Ƶ㡢�ߡ���");
    glutDisplayFunc(draw);
    glutReshapeFunc(reshape);
    glutMainLoop();
}
