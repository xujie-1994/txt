#include <gl\glut.h>
#include <Windows.h>

void draw()
{
    glClearColor(0.0, 0.0, 0.0, 0.0); //���������ɫΪ��ɫ
    glClear(GL_COLOR_BUFFER_BIT); //�õ�ǰ���������ֵ�����������
    /*
    GL_COLOR_BUFFER_BIT:    ��ǰ��д����ɫ����
    GL_DEPTH_BUFFER_BIT:    ��Ȼ���
    GL_ACCUM_BUFFER_BIT:    �ۻ�����
����  GL_STENCIL_BUFFER_BIT:  ģ�建��
    */

    glRectf(-0.5, -0.5, 0.5, 0.5); //�õ�ǰ�Ļ�ͼ��ɫ����һ��������
    /*
    ��ǰ����ɫ�ǰ�ɫ������ͨ��glColor3f�޸���ɫֵ
    */

    glFlush(); //��GL��������е�����͸��Կ������������У���������������
}

int main()
{
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB); //����ͼ����ʾģʽ
    /*
    ֵ                   ��Ӧ�궨��       ����
    GLUT_RGB            0x0000      ָ��RGB��ɫģʽ�Ĵ���
    GLUT_RGBA           0x0000      ָ��RGBA ��ɫģʽ�Ĵ���
    GLUT_INDEX          0x0001      ָ����ɫ����ģʽ�Ĵ���
    GLUT_SINGLE         0x0000      ָ�������洰��
    GLUT_DOUBLE         0x0002      ָ��˫���洰��
    GLUT_ACCUM          0x0004      ����ʹ���ۼӻ���
    GLUT_ALPHA          0x0008      ���ڵ���ɫ�������� alpha ֵ
    GLUT_DEPTH          0x0010      ����ʹ����Ȼ���
    GLUT_STENCIL        0x0020      ����ʹ��ģ�建��
    GLUT_MULTISAMPLE    0x0080      ָ��֧�ֶ��������ܵĴ���
    GLUT_STEREO         0x0100      ָ�����崰��
    GLUT_LUMINANCE      0x0200      ����ʹ��������ɫģ��
    */

    glutInitWindowPosition(0, 0); //���ó�ʼ���ڵ�λ��(�������Ͻ��������������(x,y)
    glutInitWindowSize(500, 500); //���ó�ʼ���ڵĴ�С
    glutCreateWindow("OpenGL����"); //����һ�����㴰�ڣ�nameΪ���ڵı���
    glutDisplayFunc(draw); //ע�ᵱǰ���ڵ���ʾ�ص�����
    glutMainLoop(); //��glut��������¼�ѭ��.һ������, ��ֱ����������ŷ���
	return 0;
}
