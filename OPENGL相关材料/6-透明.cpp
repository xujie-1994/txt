#include <gl/glut.h>

void Initialization()
{
    glClearColor(1.0f, 1.0f, 1.0f, 1.0f);

    GLfloat lightSpecular[] = { 1.0, 1.0, 1.0, 1.0 };
    GLfloat lightPosition[] = { 0.5, 0.5, 4.0, 0.0 };

    glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA); //ָ����Ϻ���
    glShadeModel(GL_SMOOTH);

    glMaterialfv(GL_FRONT, GL_SPECULAR, lightSpecular);
    glMaterialf(GL_FRONT, GL_SHININESS, 100.0);
    glLightfv(GL_LIGHT0, GL_POSITION, lightPosition);

    glEnable(GL_BLEND);        //���û��״̬
    glEnable(GL_LIGHTING);        //���ù���
    glEnable(GL_LIGHT0);        //�򿪹�Դ0
    glEnable(GL_DEPTH_TEST);    //������ȼ��
    glEnable(GL_COLOR_MATERIAL);//���ʸ��ٵ�ǰ��ͼɫ
}

void OnDisplay(void)
{
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);  //˫������� 

    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity(); 

    glPushMatrix();   //װ��
    {
        glTranslatef(0.0f, 0.0f, -3.0f);
        glColor4f(1.0f, 0.0f, 0.0f, 1.0f);
        glutSolidTorus(1.0f, 2.0f, 30.0f, 30.0f);//����Բ��
    }
    glPopMatrix();  //װ��


    glPushMatrix();
    {
        glTranslatef(1.0f, 1.0f, 3.0f);
        glColor4f(0.0f, 1.0f, 0.0f, 0.5);
        glutSolidSphere(2.0f, 30.0f, 30.0f);//��������
    }
    glPopMatrix();

    glPushMatrix();
    glTranslatef(-1, -1, 4);
    glColor4f(0.0f, 0.0f, 1.0f, 0.5);
    glBegin(GL_QUADS);  //�����ı���
    glVertex3f(0, 0, 0);
    glVertex3f(5, 0, 0);
    glVertex3f(5, 5, 0);
    glVertex3f(0, 5, 0);
    glEnd();
    glPopMatrix();

    glPushMatrix();
    glColor4f(0.0f, 1.0f, 1.0f, 0.5);
    glTranslatef(-1, -1, 5);
    glRotatef(60, 0, 0, 1);
    glBegin(GL_QUADS);
    glVertex3f(0, 0, 0);
    glVertex3f(5, 0, 0);
    glVertex3f(5, 5, 0);
    glVertex3f(0, 5, 0);
    glEnd();
    glPopMatrix();

    glutSwapBuffers();
}

void OnReShape(int w, int h)
{
    glViewport(0, 0, w, h);

    glMatrixMode(GL_PROJECTION); //����ǰ����ָ��ΪͶӰģʽ
    glLoadIdentity();

    if (h != 0)
    {
        GLfloat aspect = GLfloat(w) / GLfloat(h);

        if (w < h)
        {
            glOrtho(-6.0f, 6.0f, -6.0f * aspect, 6.0f * aspect, -6.0f, 6.0f);//��ά����ͶӰ
        }
        else
        {
            glOrtho(-6.0f / aspect, 6.0f / aspect, -6.0f, 6.0f, -6.0f, 6.0f);
        }
    }
    glMatrixMode(GL_MODELVIEW);
}


void main(int argc, char* argv[])
{
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB | GLUT_DEPTH);
    glutInitWindowSize(600, 480);
    glutCreateWindow("OpenGL͸��");

    glutReshapeFunc(OnReShape);
    glutDisplayFunc(OnDisplay);

    Initialization();
    glutMainLoop();  //������ѭ��
}