//
//  main.c
//  HellOpenGL
//
//  Created by civilization on 16/10/10.
//  Copyright © 2016年 civilization. All rights reserved.
//
#include <GLUT/glut.h>
#include <stdio.h>


void init()
{
    glClearColor(0.0, 0.5, 0.0, 0.0);
    glShadeModel(GL_FLAT);
}

void display()
{
    glClear(GL_COLOR_BUFFER_BIT);
    glColor3f(1.0, 1.0, 1.0);
    //glLoadIdentity(); //初始化矩阵
    
    //gluLookAt(0.0, 0.0, 2.0, 0.0, 0.0, 0.0,0.0,1.0,0.0); //视图变换
    //glScalef(1.0, 1.0, 1.0); //模型变换
    glTranslatef(0.0, 0.0, -2.0);
    glutWireCube(1.0);
    glFlush();
}

void reshape(int w, int h)
{
    glViewport(0, 0, (GLsizei)w, (GLsizei)h);
    glMatrixMode(GL_PROJECTION); //投影矩阵-制定当前矩阵
    glLoadIdentity();
    gluPerspective(60.0, 1.0,1.5,20.0);
    //glFrustum(-1.0, 1.0, -1.0, 1.0, 1.5, 20.0); //将当前矩阵与一个透视矩阵相乘，把当前矩阵转变成透视矩阵-透视变换
    glMatrixMode(GL_MODELVIEW); //模型视图矩阵
    glLoadIdentity(); //初始化矩阵
    //glOrtho(0.0, w, 0.0, h, 5.0, 5.0);
}


int main(int argc, const char * argv[])
{

    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB); //显示模式:GLUT_DOUBLE-双缓冲
    glutInitWindowPosition(1450, 370);
    glutCreateWindow("Hello OpenGL");
    
    init();
    glutDisplayFunc(display);
    glutReshapeFunc(reshape);
    glutMainLoop();
    
    return 0;
}
