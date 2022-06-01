#include <windows.h>
#include <GL/GLAUX.h>
#include <GL/glut.h>
#include <math.h> 
//GLfloat ctrlpoints[5][5][3] = {{{-2,0,0},{-1,1,0},{0,0,0},{1,-1,0},{2,0,0}},
//{{-2,0,-1},{-1,1,-1},{0,0,-1},{1,-1,-1},{2,0,-1}},
//{{-2,0,-2},{-1,1,-2},{0,0,-2},{1,-1,-2},{2,0,-2}},
//{{-2,0,-3},{-1,1,-3},{0,0,-3},{1,-1,-3},{2,0,-3}},
//{{-2,0,-4},{-1,1,-4},{0,0,-4},{1,-1,-4},{2,0,-4}}};

GLfloat ctrlpoints[5][5][3] = {{{-3,0,0},{-1,1,0},{0,0,0},{1,-1,0},{3,0,0}},
{{-3,0,-1},{-1,1,-1},{0,0,-1},{1,-1,-1},{3,0,-1}},
{{-3,0,-3},{-1,1,-3},{0,0,-3},{1,-1,-3},{3,0,-3}},
{{-3,0,-3},{-1,1,-3},{0,0,-3},{1,-1,-3},{3,0,-3}},
{{-3,0,-4},{-1,1,-4},{0,0,-4},{1,-1,-4},{3,0,-4}}};

GLfloat mat_ambient[] = {0.1,0.1,0.1,1.0};
GLfloat mat_diffuse[] = {1.0,0.6,0.0,1.0};
GLfloat mat_specular[] = {1.0,1.0,1.0,1.0};

GLfloat light_ambient[] = {0.1,0.1,0.1,1.0};
//GLfloat light_diffuse[] = {1.0,1.0,1.0,0.0};
GLfloat light_diffuse[] = {0.2,1.0,0.2,0.0};
GLfloat light_specular[] = {1.0,1.0,1.0,0.0};
GLfloat light_position[] = {2.0,23.0,-4.0,1.0};

void myInit(void)
{
 glClearColor(0.0,0.0,0.0,0.0);//���ñ���ɫ

 /*Ϊ����ģ��ָ�����ʲ���*/
 glMaterialfv(GL_FRONT,GL_AMBIENT,mat_ambient);
 glMaterialfv(GL_FRONT,GL_DIFFUSE,mat_diffuse);
 glMaterialfv(GL_FRONT,GL_SPECULAR,mat_specular);
 glMaterialf(GL_FRONT,GL_SHININESS,60.0);

 /*���ù�Դ����*/
 glLightfv(GL_LIGHT0,GL_AMBIENT,light_ambient);
 glLightfv(GL_LIGHT0,GL_DIFFUSE,light_diffuse);
 glLightfv(GL_LIGHT0,GL_SPECULAR,light_specular);
 glLightfv(GL_LIGHT0,GL_POSITION,light_position);

 glEnable(GL_LIGHTING);
 glEnable(GL_LIGHT0);

 /*enable depth comparisons and update the depth buffer*/
 glEnable(GL_DEPTH_TEST);
 /*��������Ч��*/
 glBlendFunc(GL_SRC_ALPHA,GL_ONE_MINUS_SRC_ALPHA);
 glHint(GL_LINE_SMOOTH_HINT,GL_DONT_CARE);
 glEnable(GL_BLEND);

 glEnable(GL_AUTO_NORMAL);
 glEnable(GL_NORMALIZE);
 glFrontFace(GL_CW);
 glShadeModel(GL_SMOOTH);
 glEnable(GL_LINE_SMOOTH);

}

void myDisplay(void)
{
 glClear(GL_COLOR_BUFFER_BIT|GL_DEPTH_BUFFER_BIT);
 glColor3f(0.4,0.4,0.4);
 glTranslatef(0.0,-1.0,0.0);
 glRotatef(50.0,1.0,0.0,0.0);
 glPushMatrix();
 /*��������*/
 glEnable(GL_MAP2_VERTEX_3);
 glMap2f(GL_MAP2_VERTEX_3,0,1,3,5,0,1,15,5,&ctrlpoints[0][0][0]);
 glMapGrid2f(10.0,0.0,1.0,10.0,0.0,1.0);
 glEvalMesh2(GL_FILL,0,10.0,0,10.0);
 glPopMatrix();
 glutSwapBuffers();
}

void myReshape(GLsizei w,GLsizei h)
{
 glViewport(0,0,w,h);
 glMatrixMode(GL_PROJECTION);
 glLoadIdentity();
 gluPerspective(60.0,(GLfloat)w/(GLfloat)h,1.0,100.0);
 glMatrixMode(GL_MODELVIEW);
 glLoadIdentity();
 glTranslatef(0.0,0.0,-5.0);
}

int main(int argc,char ** argv)
{
 /*��ʼ��*/
 glutInit(&argc,argv);
 glutInitDisplayMode(GLUT_DOUBLE|GLUT_RGB|GLUT_DEPTH);
 glutInitWindowSize(400,400);
 glutInitWindowPosition(200,200);

 /*��������*/
 glutCreateWindow("lighted Bezier surface");

 /*��������ʾ*/
 myInit();
 glutReshapeFunc(myReshape);
 glutDisplayFunc(myDisplay);

 /*����GLUT�¼�����ѭ��*/
 glutMainLoop();
 return(0);
}