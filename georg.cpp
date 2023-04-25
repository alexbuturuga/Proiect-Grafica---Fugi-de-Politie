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

void drawRock(GLdouble x, GLdouble y)
{
    // Draw the rock
    glColor3f(0.5, 0.5, 0.5); // Set the color to gray
    glBegin(GL_POLYGON);
    glVertex2d(x, y);
    glVertex2d(x + 30, y);
    glVertex2d(x + 20, y + 20);
    glVertex2d(x + 30, y + 30);
    glVertex2d(x + 10, y + 50);
    glVertex2d(x - 10, y + 30);
    glVertex2d(x, y + 20);
    glEnd();
}

void drawBush(GLdouble x, GLdouble y)
{
    // Draw the bush
    glColor3f(0.0, 0.5, 0.0); // Set the color to green
    glBegin(GL_POLYGON);
    glVertex2d(x, y);
    glVertex2d(x + 20, y);
    glVertex2d(x + 30, y + 10);
    glVertex2d(x + 40, y + 10);
    glVertex2d(x + 50, y);
    glVertex2d(x + 70, y);
    glVertex2d(x + 70, y + 20);
    glVertex2d(x + 60, y + 30);
    glVertex2d(x + 50, y + 40);
    glVertex2d(x + 40, y + 50);
    glVertex2d(x + 30, y + 50);
    glVertex2d(x + 20, y + 40);
    glVertex2d(x + 10, y + 30);
    glVertex2d(x, y + 20);
    glEnd();
}

void drawHouse(GLdouble x, GLdouble y)
{
    // Draw the walls
    glColor3f(0.7, 0.7, 0.7); // Set the color to light gray
    glBegin(GL_POLYGON);
    glVertex2d(x, y);
    glVertex2d(x + 80, y);
    glVertex2d(x + 80, y + 60);
    glVertex2d(x, y + 60);
    glEnd();

    // Draw the roof
    glColor3f(0.8, 0.2, 0.2); // Set the color to red
    glBegin(GL_TRIANGLES);
    glVertex2d(x, y + 60);
    glVertex2d(x + 40, y + 90);
    glVertex2d(x + 80, y + 60);
    glEnd();

    // Draw the door
    glColor3f(0.5, 0.3, 0.0); // Set the color to brown
    glBegin(GL_POLYGON);
    glVertex2d(x + 30, y);
    glVertex2d(x + 50, y);
    glVertex2d(x + 50, y + 40);
    glVertex2d(x + 30, y + 40);
    glEnd();

    // Draw the window
    glColor3f(0.5, 0.5, 1.0); // Set the color to light blue
    glBegin(GL_POLYGON);
    glVertex2d(x + 60, y + 20);
    glVertex2d(x + 70, y + 20);
    glVertex2d(x + 70, y + 30);
    glVertex2d(x + 60, y + 30);
    glEnd();
}