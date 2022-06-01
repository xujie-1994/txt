#include <gl/glut.h>

#define FileName "Bliss.bmp"

static GLint    ImageWidth;
static GLint    ImageHeight;
static GLint    PixelLength;
static GLubyte* PixelData;

#include <stdio.h>
#include <stdlib.h>

void display(void)
{

    glClear(GL_COLOR_BUFFER_BIT);

// 绘制像素
    glDrawPixels(ImageWidth, ImageHeight,GL_BGR_EXT, GL_UNSIGNED_BYTE, PixelData);

// 完成绘制
    glutSwapBuffers();
}

int main(int argc, char* argv[])
{
    // 打开文件
    FILE* pFile = fopen("Bliss.bmp", "rb");
    if( pFile == 0 )
        exit(0);

// 读取图象的大小信息
    fseek(pFile, 0x0012, SEEK_SET);
    fread(&ImageWidth, sizeof(ImageWidth), 1, pFile);
    fread(&ImageHeight, sizeof(ImageHeight), 1, pFile);

// 计算像素数据长度
    PixelLength = ImageWidth * 3;
    while( PixelLength % 4 != 0 )
        ++PixelLength;
    PixelLength *= ImageHeight;

// 读取像素数据
    PixelData = (GLubyte*)malloc(PixelLength);
    if( PixelData == 0 )
        exit(0);

fseek(pFile, 54, SEEK_SET);
    fread(PixelData, PixelLength, 1, pFile);

// 关闭文件
    fclose(pFile);

// 初始化GLUT并运行
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGBA);
    glutInitWindowPosition(100, 100);
    glutInitWindowSize(ImageWidth, ImageHeight);
    glutCreateWindow(FileName);
    glutDisplayFunc(&display);
    glutMainLoop();


return 0;
}