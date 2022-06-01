#include <GL/glut.h>


void myinit()
{
     /* ���ò��ʵĸ��ֹ����ɫ�ɷַ������*/
    GLfloat mat_ambient[]={0.8,0.8,0.8,1.0};
    GLfloat mat_diffuse[]={0.8,0.0,0.8,1.0};    /* ��ɫ */
    GLfloat mat_specular[] = { 1.0, 0.0, 1.0, 1.0 };  /* ����ɫ */
    GLfloat mat_shininess[] = { 50.0 };
	//û�����ù����ɫ����Ĭ��Ϊ�׹�
    GLfloat light_position[] = { 1.0, 1.0, 1.0, 0.0 };
	GLfloat ambient[] = { 0.3,0.3f,0.3,1.0 };
	GLfloat diffuse[] = { 0.7,0.7f,0.7,1.0 };
	GLfloat specular[] = { 0.5,0.5f,0.5,1.0 };

	glLightfv(GL_LIGHT0, GL_AMBIENT, ambient);
	glLightfv(GL_LIGHT0, GL_DIFFUSE, diffuse);
	glLightfv(GL_LIGHT0, GL_SPECULAR, specular);   
    glLightfv(GL_LIGHT0, GL_POSITION, light_position);
    
    glEnable(GL_LIGHTING);
    glEnable(GL_LIGHT0);
    glDepthFunc(GL_LESS);
    glEnable(GL_DEPTH_TEST);
	    
    glMaterialfv(GL_FRONT, GL_AMBIENT, mat_ambient);
    glMaterialfv(GL_FRONT, GL_DIFFUSE, mat_diffuse);
    glMaterialfv(GL_FRONT, GL_SPECULAR, mat_specular);
    glMaterialfv(GL_FRONT, GL_SHININESS, mat_shininess);

}

void display()
{
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glutSolidSphere( 1.0, 20.0, 20.0);
    //SolidSphere(1.0);
    glFlush();
}

void myReshape(GLsizei w, GLsizei h)
{
    glViewport(0, 0, w, h);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    if (w <= h)
        glOrtho (-1.5, 1.5, -1.5*(GLfloat)h/(GLfloat)w,
                 1.5*(GLfloat)h/(GLfloat)w, -10.0, 10.0);
    else
        glOrtho (-1.5*(GLfloat)w/(GLfloat)h,
                 1.5*(GLfloat)w/(GLfloat)h, -1.5, 1.5, -10.0, 10.0);
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
}

int main(int argc, char** argv)
{
    glutInit(&argc, argv);
    glutInitDisplayMode (GLUT_SINGLE | GLUT_RGB | GLUT_DEPTH);
    glutInitWindowSize (500, 500);
    glutInitWindowPosition (100, 100);
    glutCreateWindow ("���ʵ�ʹ��");
    myinit();
    glutDisplayFunc(display);
    glutReshapeFunc (myReshape);
    
    glutMainLoop();
	return 0;
}
