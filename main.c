//
//  main.c
//  HellOpenGL
//
//  Created by civilization on 16/10/10.
//  Copyright © 2016年 civilization. All rights reserved.
//
#include <GLUT/glut.h>
#include <stdio.h>

static GLfloat spin = 0.0;

void init()
{
    glClearColor(0.0, 0.5, 0.0, 0.0); //定义刷子的颜色，注意是重0-1取值，而不是0-255
    //GL_SMOOTH（光滑着色-默认值)—独立的处理图元中各个顶点的颜色
    //GL_FLAT(恒定着色)-使用图元中某个顶点的颜色来渲染整个图元。
    glShadeModel(GL_FLAT);
}

void display()
{
    glClear(GL_COLOR_BUFFER_BIT); //清理颜色缓冲区
    glPushMatrix();
    
    glRotatef(spin, 0.0, 0.0, 1.0);
    glColor3f(1.0, 1.0, 1.0);
    glRectf(25.0, 25.0, 50.0, 50.0);
    
    glPopMatrix();
    glutSwapBuffers();
}

void spinDisplay(void)
{
    spin = spin + 1.0;
    if (spin > 360.0)
        spin = spin -360.0;
    glutPostRedisplay(); //当前窗口需要重新绘制
}

void reShape(int w, int h)
{
    glViewport(0, 0, (GLsizei)w, (GLsizei)h); //让窗口系统打开窗口
    
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluOrtho2D(0.0, (GLdouble)w, 0.0, (GLdouble)h); //以左下角为原点
    //glOrtho(-50.0, 50.0, -50.0, 50.0, -1.0, 1.0);
    
    //glMatrixMode(GL_MODELVIEW);
    //glLoadIdentity();
}

void OnMouse(int button, int state, int x, int y)
{
    switch(button)
    {
        case GLUT_LEFT_BUTTON:
        {
            if (state == GLUT_DOWN)
                glutIdleFunc(spinDisplay); //在双缓冲空闲时执行
        }break;
        case GLUT_RIGHT_BUTTON:
        {
            if (state == GLUT_DOWN)
                glutIdleFunc(NULL);
        }break;
            default:
            break;
    }
}

int main(int argc, const char * argv[])
{

    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB); //显示模式:GLUT_DOUBLE-双缓冲
    glutInitWindowPosition(1450, 370);
    glutCreateWindow("Hello OpenGL");
    
    init();
    glutDisplayFunc(display);
    glutReshapeFunc(reShape);
    glutMouseFunc(OnMouse);
    glutMainLoop();
    
    
    return 0;
}
