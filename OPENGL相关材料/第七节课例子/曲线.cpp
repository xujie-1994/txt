#include "gl/glut.h"    
    
int Line_Count = 80;     
// ������Խ�� ����Խƽ��     
// ������ԽС ����Խ�ֲ�     
// ���Դ� ���� ���� �������ߵõ��Ա�    
    
// �������߿��Ƶ�    
GLfloat ControlPoints0[4][3] =     
{    
    { -4.0 ,  1.0 , 0.0 } , // ���Ƶ��������е�˳�����������ʽ    
    { -1.0 ,  1.0 , 0.0 } ,    
    { -1.0 ,  4.0 , 0.0 } ,     
    { -4.0 ,  4.0 , 0.0 }       
};    
    
// �������߿��Ƶ�    
GLfloat ControlPoints1[4][3] =     
{    
    {  4.0 ,  1.0 , 0.0 } ,     
    {  1.0 ,  4.0 , 0.0 } ,     
    {  1.0 ,  1.0 , 0.0 } ,     
    {  4.0 ,  4.0 , 0.0 }       
};    
    
// �������߿��Ƶ�    
GLfloat ControlPoints2[4][3] =     
{    
    {  1.0 , -4.0 , 0.0 } ,    
    {  4.0 , -4.0 , 0.0 } ,     
    {  1.0 , -1.0 , 0.0 } ,    
    {  4.0 , -1.0 , 0.0 }    
};    
    
// �������߿��Ƶ�    
GLfloat ControlPoints3[4][3] =     
{    
    { -4.0 , -4.0 , 0.0 } ,    
    { -1.0 , -4.0 , 0.0 } ,     
    { -4.0 , -1.0 , 0.0 } ,    
    { -1.0 , -1.0 , 0.0 }    
};    
    
void Display( void )    
{    
    int i;    
    
    glClear( GL_COLOR_BUFFER_BIT );    
    glLoadIdentity();    
    
    // �Ȼ��ƿ��Ƶ� �ٻ�������    
    // ��������    
    glMap1f(GL_MAP1_VERTEX_3, 0.0, 1.0, 3, 4, &ControlPoints0[0][0]);     
    glColor3f( 0 , 0 , 1.0 );    
    glBegin( GL_POINTS );    
        for( i = 0 ; i < 4 ; i++ )     
        {    
            glVertex3fv( ControlPoints0[i] );    
        }    
    glEnd();    
    
    glColor3f(0.0, 1.0, 0.0);    
    glBegin( GL_LINE_STRIP );    
        for( i = 0 ; i <= Line_Count ; i++ )     
        {    
            glEvalCoord1f( (GLfloat)i/Line_Count );    
        }      
    glEnd();    
    
    // ��������    
    glMap1f(GL_MAP1_VERTEX_3, 0.0, 1.0, 3, 4, &ControlPoints1[0][0]);    
    glColor3f( 1.0 , 0.0 , 0.0 );    
    glBegin( GL_POINTS );    
        for( i = 0 ; i < 4 ; i++ )     
        {    
            glVertex3fv( ControlPoints1[i] );    
        }    
    glEnd();    
    
    glColor3f(0.0, 1.0, 0.0);    
    glBegin( GL_LINE_STRIP );    
        for( i = 0 ; i <= Line_Count ; i++ )     
        {    
            glEvalCoord1f( (GLfloat)i/Line_Count );    
        }      
    glEnd();    
    
    // ��������    
    glMap1f(GL_MAP1_VERTEX_3, 0.0, 1.0, 3, 4, &ControlPoints2[0][0]);    
    glColor3f( 0.0 , 0.0 , 1.0 );    
    glBegin( GL_POINTS );    
        for( i = 0 ; i < 4 ; i++ )     
        {    
            glVertex3fv( ControlPoints2[i] );    
        }    
    glEnd();    
    
    glColor3f(0.0, 1.0, 0.0);    
    glBegin( GL_LINE_STRIP );    
        for( i = 0 ; i <= Line_Count ; i++ )     
        {    
            glEvalCoord1f( (GLfloat)i/Line_Count );    
        }      
    glEnd();    
    
    // ��������    
    Line_Count = 8; // ���������� ���߱�ֲ�    
    glMap1f(GL_MAP1_VERTEX_3, 0.0, 1.0, 3, 4, &ControlPoints3[0][0]);    
    glColor3f( 1.0 , 1.0 , 0.0 );    
    glBegin( GL_POINTS );    
        for( i = 0 ; i < 4 ; i++ )     
        {    
            glVertex3fv( ControlPoints3[i] );    
        }    
    glEnd();    
    
    glColor3f(0.0, 1.0, 0.0);    
    glBegin( GL_LINE_STRIP );    
        for( i = 0 ; i <= Line_Count ; i++ )     
        {    
            glEvalCoord1f( (GLfloat)i/Line_Count );    
        }      
    glEnd();    
    
    glFlush();    
}    
    
void Initialize()    
{    
    glClearColor( 0.0 , 0.0 , 0.0 , 0.0 );    
   
    glEnable(GL_MAP1_VERTEX_3); //   
    glEnable( GL_LINE_SMOOTH ); // ƽ������    
    glPointSize( 6.0 ); // �ѵ���һ�� �������    
}    
    
void Reshape( int Width , int Height )    
{    
    glViewport( 0 , 0 , (GLsizei)Width , (GLsizei)Height );    
    
    glMatrixMode( GL_PROJECTION );    
    glLoadIdentity();    
    
    if( Width <= Height )    
    {    
        glOrtho( -5.0 , 5.0 , -5.0 * (GLfloat)Height / (GLfloat)Width , 5.0 * (GLfloat)Height / (GLfloat)Width , -5.0 , 5.0 );    
    }    
    
    else    
    {    
        glOrtho( -5.0 * (GLfloat)Width / (GLfloat)Height , 5.0 * (GLfloat)Width / (GLfloat)Height , -5.0 , 5.0 , -5.0 , 5.0 );    
    }    
    
    glMatrixMode( GL_MODELVIEW );    
    glLoadIdentity();    
}    
    
void main()    
{    
    glutInitDisplayMode( GLUT_SINGLE | GLUT_RGB );    
    glutInitWindowSize( 700 , 700 );    
    glutInitWindowPosition( 162 , 34 );    
    glutCreateWindow( "Bezier Curve" );    
    Initialize();    
    glutDisplayFunc( Display );    
    glutReshapeFunc( Reshape );    
    glutMainLoop();    
} 