#include <iostream>
#include <windows.h>
#include <GL/freeglut.h>
#include <Windows.h>
#include <filesystem>
#include <string>


void drawBarrier(GLdouble x, GLdouble y)
{
    // Draw the white zone
    glColor3f(1.0, 1.0, 1.0);
    glBegin(GL_POLYGON);
    glVertex2d(x, y);
    glVertex2d(x + 20, y);
    glVertex2d(x + 20, y + 100);
    glVertex2d(x, y + 100);
    glEnd();
    //Draw the red bars
    glColor3f(1.0, 0.0, 0.0);
    glBegin(GL_POLYGON);
    glVertex2d(x, y);
    glVertex2d(x + 20, y);
    glVertex2d(x + 20, y + 20);
    glEnd();
    glBegin(GL_POLYGON);
    glVertex2d(x, y + 20);
    glVertex2d(x + 20, y + 40);
    glVertex2d(x + 20, y + 60);
    glVertex2d(x, y + 40);
    glEnd();
    glBegin(GL_POLYGON);
    glVertex2d(x, y + 60);
    glVertex2d(x + 20, y + 80);
    glVertex2d(x + 20, y + 100);
    glVertex2d(x, y + 80);
    glEnd();



    // Draw the barrier legs
    glColor3f(0.43, 0.16, 0.0);
    glBegin(GL_POLYGON);
    glVertex2d(x - 20, y + 10);
    glVertex2d(x - 5, y + 10);
    glVertex2d(x, y + 15);
    glVertex2d(x, y + 30);
    glEnd();
    glBegin(GL_POLYGON);
    glVertex2d(x + 40, y + 10);
    glVertex2d(x + 25, y + 10);
    glVertex2d(x + 20, y + 15);
    glVertex2d(x + 20, y + 30);
    glEnd();
    glBegin(GL_POLYGON);
    glVertex2d(x + 40, y + 90);
    glVertex2d(x + 25, y + 90);
    glVertex2d(x + 20, y + 85);
    glVertex2d(x + 20, y + 70);
    glEnd();
    glBegin(GL_POLYGON);
    glVertex2d(x - 20, y + 90);
    glVertex2d(x - 5, y + 90);
    glVertex2d(x, y + 85);
    glVertex2d(x, y + 70);
    glEnd();
}