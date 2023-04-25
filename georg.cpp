#include <iostream>
#include <windows.h>
#include <GL/freeglut.h>
#include <Windows.h>
#include <filesystem>
#include <string>



void drawTree(GLdouble x, GLdouble y)
{
    // Draw the trunk
    glColor3f(0.43, 0.16, 0.0);
    glBegin(GL_POLYGON);
    glVertex2d(x, y);
    glVertex2d(x + 10, y);
    glVertex2d(x + 10, y + 50);
    glVertex2d(x, y + 50);
    glEnd();

    // Draw the foliage
    glColor3f(0.0, 0.5, 0.0);
    glBegin(GL_POLYGON);
    glVertex2d(x - 20, y + 50);
    glVertex2d(x + 30, y + 50);
    glVertex2d(x + 5, y + 90);
    glEnd();
}