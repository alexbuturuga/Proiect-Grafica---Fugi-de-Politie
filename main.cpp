﻿#include <iostream>
#include <windows.h>
#include <GL/glut.h>
#include <GL/freeglut.h>
#include <Windows.h>
#include <filesystem>
#include "georg.cpp"
#include <string>
#include "maur.cpp"
#include "darius.cpp"
#include "start.cpp"

using namespace std;

double xFinal = 20;

std::wstring directory;
GLdouble left_m = -100.0;
GLdouble right_m = 700.0;
GLdouble bottom_m = -140.0;
GLdouble top_m = 460.0;
int exponent = 0;
int acceleratie = pow(2,exponent);
double ok = 1;
int misca = 0;
double j = 0.0;
double i = 0.0;
double z = 0.0;
double PozitieCopac = 175;
double PozitieRock = 400;
double PozitieCasa = 660;
double PozitieBoschet = 900;
int PozitieBariera = 800;
bool isYellow1 = false;
bool isYellow2 = false;
double contor = 0;
double loc_vert = 800;
int vector[3] = { 0, 160, 320 };
double height = vector[rand() % 3];
int score = 0;
double timp = 0.15;
int pct = 1000;
int ok2 = 0;
double rsj, rdj, rss, rds = 0;
double paused = 0;
bool gameStarted = false;
int pauza = 1;
int menu_id;
int start = 0;
int control = 0;
int r = 10;


const int font1 = (int)GLUT_BITMAP_TIMES_ROMAN_24;
const int font2 = (int)GLUT_BITMAP_HELVETICA_18;
const int font3 = (int)GLUT_BITMAP_8_BY_13;

int randomNumber(int min, int max) {
	return rand() % (max - min + 1) + min;
}

void RenderString(float x, float y, void* font, const unsigned char* string)
{
	glColor3f(0.0f, 0.0f, 0.0f);
	glRasterPos2f(x, y);
	glutBitmapString(font, string);
}
void renderBitmapString(float x, float y, void* font, const char* string) {
	const char* c;
	glRasterPos2f(x, y);
	for (c = string; *c != '\0'; c++) {
		glutBitmapCharacter(font, *c);
	}
}
void init(void)
{

	glClearColor(0.5, 0.5, 0.5, 0.0);
	glMatrixMode(GL_PROJECTION);
	glOrtho(left_m, right_m, bottom_m, top_m, -1.0, 1.0);

}

void firstDesign() {
	glColor3f(0.55, 0.788, 0.451);

	// Iarba de jos
	glBegin(GL_POLYGON);
	glVertex2i(-100, -140);// Stanga jos
	glVertex2i(700, -140); // Dreapta jos
	glVertex2i(700, -80);  // Dreapta sus
	glVertex2i(-100, -80); // Stanga sus
	glEnd();

	// Iarba de sus
	glBegin(GL_POLYGON);
	glVertex2i(-100, 400);// Stanga jos
	glVertex2i(700, 400); // Dreapta jos
	glVertex2i(700, 460); // Dreapta sus
	glVertex2i(-100, 460);// Stanga sus
	glEnd();
}

void miscareGirofar(void) {
	// pentru girofar
	z += pauza*0.05;
	if (z > 360) {
		z = 0;
	}
	if (z < 0) {
		z = 360;
	}

	// pentru schimbarea benzii
	if (i > xFinal && i > -120) {
		i -= pauza*0.15;
	}
	if (i < xFinal && i < 20) {
		i += pauza*0.15;
	}


	glutPostRedisplay();
}

void startgame(void)
{
	
	if ((height != j || (loc_vert > 10 || loc_vert < -100)) && (ok == 1))
	{
		
		if (160 * r == j && !(loc_vert > 40 || loc_vert < -40))
		{
			ok = 0;
			pauza = 0;
		}

		if (pauza == 1)
		{
			if (PozitieBariera > -200)
			{
				PozitieBariera = PozitieBariera - 1 * acceleratie;
			}
			else
			{
				PozitieBariera= 800;
			}
			if (PozitieCopac > -200)
			{
				PozitieCopac = PozitieCopac - 1 * acceleratie;
			}
			else
			{
				PozitieCopac = 800;
			}
			if (PozitieCasa > -200)
			{
				PozitieCasa = PozitieCasa - 1 * acceleratie;
			}
			else
			{
				PozitieCasa = 800;
			}
			if (PozitieBoschet > -200)
			{
				PozitieBoschet = PozitieBoschet - 1 * acceleratie;
			}
			else
			{
				PozitieBoschet = 800;
			}
			if (PozitieRock > -200)
			{
				PozitieRock = PozitieRock - 1 * acceleratie;
			}
			else
			{
				PozitieRock = 800;
			}

			if (i < -380)
			{
				i = 0;
			}
			i = i - 12 * timp + 1;

			loc_vert -= 6 * timp + 1 * acceleratie;

			if (loc_vert < -350)
			{
				score += 100;
				height = vector[rand() % 3];
				cout << "Score:  " << score << endl;
				loc_vert = 700;
			}

			if (score >= pct && pct <= 15000)
			{
				timp += 0.1;
				pct += 1000;
			}

			glutPostRedisplay();
		}
	}
	else {
		ok = 0;
		pauza = 0;
	}
}
void renderPauseMenu() {
	glPushMatrix();
	glLoadIdentity();
	glColor3f(1.0f, 1.0f, 1.0f);
	glRasterPos2f(240.0f, 200.0f);
	glutBitmapString(GLUT_BITMAP_TIMES_ROMAN_24, (unsigned const char*)"Paused game");
	glRasterPos2f(210.0f, 170.0f);
	glutBitmapString(GLUT_BITMAP_HELVETICA_18, (unsigned const char*)"Press 'Right' to Resume");
	glPopMatrix();
}

void timer(int value) {
	isYellow1 = false;
	isYellow2 = false;

	glutPostRedisplay();
	glutTimerFunc(500, timer, 0); // call this function again after 1000 milliseconds
}

void mouse(int button, int state, int x, int y) {
	if (start == 0)
	{
		//Controls
		if (button == GLUT_LEFT_BUTTON && state == GLUT_DOWN && x >= 450 && x <= 550 && y >= 300 && y <= 330) {
			if (control == 0)
			{
				control = 1;
			}
			else
			{
				control = 0;
			}
		}
		//Start
		if (button == GLUT_LEFT_BUTTON && state == GLUT_DOWN && x >= 250 && x <= 350 && y >= 300 && y <= 330) {
			start = 1;
		}
	}
	RenderString(177.0f, 140.0f, GLUT_BITMAP_TIMES_ROMAN_24, (const unsigned char*)"Start");
	
}

void ControlMenu()
{
	glColor3f(0.7, 0.7, 0.7);
	glEnable(GL_LINE_STIPPLE);
	glLineStipple(1, 0x00FF);
	glBegin(GL_POLYGON);
	glVertex2i(500, 250);
	glVertex2i(100, 250);
	glVertex2i(100, 410);
	glVertex2i(500, 410);
	glEnd();
	glDisable(GL_LINE_STIPPLE);
	RenderString(240.0f, 380.0f, GLUT_BITMAP_TIMES_ROMAN_24, (const unsigned char*)"Instructiuni :");
	RenderString(110.0f, 350.0f, GLUT_BITMAP_TIMES_ROMAN_24, (const unsigned char*)"Trebuie sa fii in totalitate pe alta");
	RenderString(110.0f, 320.0f, GLUT_BITMAP_TIMES_ROMAN_24, (const unsigned char*)"Banda pentru a nu fi prins de politie.");
	RenderString(110.0f, 290.0f, GLUT_BITMAP_TIMES_ROMAN_24, (const unsigned char*)"De la 1000 de puncte apar obstacole.");


	glColor3f(0.7, 0.7, 0.7);
	glEnable(GL_LINE_STIPPLE);
	glLineStipple(1, 0x00FF);
	glBegin(GL_POLYGON);
	glVertex2i(500, -100);
	glVertex2i(100, -100);
	glVertex2i(100, 90);
	glVertex2i(500, 90);
	glEnd();
	glDisable(GL_LINE_STIPPLE);
	RenderString(120.0f, -85.0f, GLUT_BITMAP_TIMES_ROMAN_24, (const unsigned char*)"Click dreapta - alege melodiia");
	RenderString(120.0f, -55.0f, GLUT_BITMAP_TIMES_ROMAN_24, (const unsigned char*)"F3 - Start/Stop");
	RenderString(120.0f, -25.0f, GLUT_BITMAP_TIMES_ROMAN_24, (const unsigned char*)"Sageata sus - Schimba banda in sus");
	RenderString(120.0f, 5.0f, GLUT_BITMAP_TIMES_ROMAN_24, (const unsigned char*)"Sageata jos - Schimba banda in sus");
	RenderString(120.0f, 35.0f, GLUT_BITMAP_TIMES_ROMAN_24, (const unsigned char*)"Sageata dreapta - Creste acceleratia");
	RenderString(120.0f, 65.0f, GLUT_BITMAP_TIMES_ROMAN_24, (const unsigned char*)"Sageata stanga - Scade acceleratia");
}

void StartMenu(void)
{
	glColor3f(0.55, 0.788, 0.451);

	// Iarba de jos
	glBegin(GL_POLYGON);
	glVertex2i(-100, -140);// Stanga jos
	glVertex2i(700, -140); // Dreapta jos
	glVertex2i(700, -80);  // Dreapta sus
	glVertex2i(-100, -80); // Stanga sus
	glEnd();

	// Iarba de sus
	glBegin(GL_POLYGON);
	glVertex2i(-100, 400);// Stanga jos
	glVertex2i(700, 400); // Dreapta jos
	glVertex2i(700, 460); // Dreapta sus
	glVertex2i(-100, 460);// Stanga sus
	glEnd();



	RenderString(160.0f, 425.0f, GLUT_BITMAP_TIMES_ROMAN_24, (const unsigned char*)"Nu lasa politia sa te prinda!");
	

	glTranslated(i, 0.0, 0.0);
	glColor3f(0.7, 0.7, 0.7);
	glEnable(GL_LINE_STIPPLE);
	glLineStipple(1, 0x00FF);
	glBegin(GL_POLYGON);
	glVertex2i(500, 100);
	glVertex2i(100, 100);
	glVertex2i(100, 200);
	glVertex2i(500, 200);
	
	glEnd();
	glDisable(GL_LINE_STIPPLE);

	glTranslated(i, 0.0, 0.0);
	glColor3f(0.7, 0.7, 1);
	glEnable(GL_LINE_STIPPLE);
	glLineStipple(1, 0x00FF);
	glBegin(GL_POLYGON);
	glVertex2i(250, 130);
	glVertex2i(150, 130);
	glVertex2i(150, 170);
	glVertex2i(250, 170);
	glEnd();
	glDisable(GL_LINE_STIPPLE);

	
	glColor3f(0.7, 0.7, 1);
	glEnable(GL_LINE_STIPPLE);
	glLineStipple(1, 0x00FF);
	glBegin(GL_POLYGON);
	glVertex2i(470, 130);
	glVertex2i(350, 130);
	glVertex2i(350, 170);
	glVertex2i(470, 170);
	glEnd();
	glDisable(GL_LINE_STIPPLE);

	RenderString(177.0f, 140.0f, GLUT_BITMAP_TIMES_ROMAN_24, (const unsigned char*)"Start");
	RenderString(375.0f, 140.0f, GLUT_BITMAP_TIMES_ROMAN_24, (const unsigned char*)"Control");

	


	// Delimitare sosea
	glLineWidth(3);
	glColor3f(1, 1, 1);

	// Delimitam soseaua de iarba partea de jos
	glBegin(GL_LINES);
	glVertex2i(-100, -80);
	glVertex2i(1500, -80);
	glEnd();

	// Delimitam soseaua de iarba partea de sus
	glBegin(GL_LINES);
	glVertex2i(-100, 400);
	glVertex2i(1500, 400);
	glEnd();

   

	glPushMatrix();
	for (int i = 0; i <= 20; i++)
	{
		drawTree(-40 + 120*i, -120);
	}

	//control

	if (control == 1)
	{
		ControlMenu();
	}


	// Liniile intrerupte

	glTranslated(i, 0.0, 0.0);
	glColor3f(1, 1, 1);
	glEnable(GL_LINE_STIPPLE);
	glLineStipple(1, 0x00FF);
	glBegin(GL_LINES);
	glVertex2i(-100, 80);
	glVertex2i(1500, 80);
	glEnd();
	glDisable(GL_LINE_STIPPLE);

	glColor3f(1, 1, 1);
	glEnable(GL_LINE_STIPPLE);
	glLineStipple(1, 0x00FF);
	glBegin(GL_LINES);
	glTranslated(i, 0.0, 0.0);
	glVertex2i(-100, 240);
	glVertex2i(1500, 240);
	glEnd();
	glDisable(GL_LINE_STIPPLE);
	glPopMatrix();
	glPushMatrix();
	//Afisare scor
	//string scoreText = "Score: " + to_string(score); // convert the score to a string
	//const unsigned char* scoreStr = reinterpret_cast<const unsigned char*>(scoreText.c_str()); // convert the string to a char array
	//RenderString(580.0f, 425.0f, GLUT_BITMAP_HELVETICA_18, scoreStr); // display the score
	glPopMatrix();
	glutPostRedisplay();
	glutSwapBuffers();
	glFlush();

}

void drawScene(void)
{
	if (start == 1)
	{
		glColor3f(0.55, 0.788, 0.451);

		// Iarba de jos
		glBegin(GL_POLYGON);
		glVertex2i(-100, -140);// Stanga jos
		glVertex2i(700, -140); // Dreapta jos
		glVertex2i(700, -80);  // Dreapta sus
		glVertex2i(-100, -80); // Stanga sus
		glEnd();

		// Iarba de sus
		glBegin(GL_POLYGON);
		glVertex2i(-100, 400);// Stanga jos
		glVertex2i(700, 400); // Dreapta jos
		glVertex2i(700, 460); // Dreapta sus
		glVertex2i(-100, 460);// Stanga sus
		glEnd();



		RenderString(160.0f, 425.0f, GLUT_BITMAP_TIMES_ROMAN_24, (const unsigned char*)"Nu lasa politia sa te prinda!");



		// Delimitare sosea
		glLineWidth(3);
		glColor3f(1, 1, 1);

		// Delimitam soseaua de iarba partea de jos
		glBegin(GL_LINES);
		glVertex2i(-100, -80);
		glVertex2i(1500, -80);
		glEnd();

		// Delimitam soseaua de iarba partea de sus
		glBegin(GL_LINES);
		glVertex2i(-100, 400);
		glVertex2i(1500, 400);
		glEnd();

		glPushMatrix();

		// Liniile intrerupte

		//Dresenam Obiecte
		drawTree(PozitieCopac, -130);
		drawBush(PozitieBoschet, -120);
		drawHouse(PozitieCasa, -130);
		drawRock(PozitieRock, -130);

		glTranslated(i*acceleratie, 0.0, 0.0);
		glColor3f(1, 1, 1);
		glEnable(GL_LINE_STIPPLE);
		glLineStipple(1, 0x00FF);
		glBegin(GL_LINES);
		glVertex2i(-100, 80);
		glVertex2i(3500, 80);
		glEnd();
		glDisable(GL_LINE_STIPPLE);

		glColor3f(1, 1, 1);
		glEnable(GL_LINE_STIPPLE);
		glLineStipple(1, 0x00FF);
		glBegin(GL_LINES);
		glTranslated(i * acceleratie, 0.0, 0.0);
		glVertex2i(-100, 240);
		glVertex2i(3500, 240);
		glEnd();
		glDisable(GL_LINE_STIPPLE);
		glPopMatrix();
		glPushMatrix();
		//Afisare scor
		string scoreText = "Score: " + to_string(score); // convert the score to a string
		const unsigned char* scoreStr = reinterpret_cast<const unsigned char*>(scoreText.c_str()); // convert the string to a char array
		RenderString(580.0f, 425.0f, GLUT_BITMAP_HELVETICA_18, scoreStr); // display the score


		//desenam masina
		glPushMatrix();

		glTranslated(0.0, j, 0.0);

		//masina lu' Hotzu
		glColor3f(0.996, 0.365, 0.149);
		glRecti(-45, -25, -20, 25);
		glColor3f(0, 0, 0);
		glRecti(-20, -25, 45, 25);
		glColor3f(0.996, 0.365, 0.149);
		glRecti(45, -25, 70, 25);
		//faruri
		glColor3f(0.8, 0.5, 0);
		glRecti(70, -25, 80, -10);
		glColor3f(0.8, 0.5, 0);
		glRecti(70, 10, 80, 25);
		//stopuri
		glColor3f(1, 0, 0);
		glRecti(-55, -25, -45, -10);
		glColor3f(1, 0, 0);
		glRecti(-55, 10, -45, 25);

		if (isYellow1) {
			glColor3f(1.0, 1.0, 0.0); // yellow color
		}
		else {
			glColor3f(0.8, 0.5, 0.0); // original color
		}
		glRecti(70, -25, 80, -10);
		if (isYellow2) {
			glColor3f(1.0, 1.0, 0.0); // yellow color
		}
		else {
			glColor3f(0.8, 0.5, 0.0); // original color
		}
		glRecti(70, 10, 80, 25);

		if (ok == 0)
		{
			rsj = 8;
			rss = -8;
			rdj = -8;
			rds = 8;
		}
		if (paused == 1) {
			timp = 0;

			renderPauseMenu();
		}

		if (control == 1)
		{
			glPopMatrix();
			glPushMatrix();
			ControlMenu();
		}

		if (ok == 0 && ok2 == 0)
		{
			std::wstring soundPath = directory + L"\\gameover.wav";
			if (PlaySound(soundPath.c_str(), NULL, SND_ASYNC))
				cout << "Muzica Joc Terminat!";
			ok2 = 1;
		}
		glPopMatrix();
		glPopMatrix();
		if (ok == 0) {

			RenderString(250.0f, 200.0f, GLUT_BITMAP_8_BY_13, (const unsigned char*)"GAME OVER, AI FOST PRINS!!");
		}

		if (contor == 1 && (j != 160 && j != 320))
		{
			j = j + 2 * pauza;
		}

		else if (contor == -1 && (j != 160 && j != 0))
		{
			j = j - 2 * pauza;
		}
		else {
			contor = 0;
			misca = 0;
		}
		//Girofar
		
		
		if (score >= 1000)
		{
			if (r == 10)
			{
				r = 1;
				PozitieBariera = 800;
			}
				
			//glTranslated(loc_vert, height - 48, 0.0);
			if(PozitieBariera == -199)
				r = randomNumber(0, 2);

			drawBarrier(PozitieBariera, r*150-40);
		}
		
		

		//MASINA DE POLITIE
		//desenam a doua masina (adversara)
		glPushMatrix();
		glTranslated(loc_vert, height - 48, 0.0);

		//glColor3f(0.471, 0.667, 0.949);

		//glRecti(-45, -15, 45, 15);
		//SASIU
		glRotated(90, 0, 0, 1);
		glColor3f(0, 0, 0);
		glRectf(20, -180, 80, -155);
		glColor3f(1, 1, 1);
		glRectf(20, -155, 80, -115);
		glColor3f(0, 0, 0);
		glRectf(20, -115, 80, -90);

		//STOPURI
		glColor3f(1, 0, 0);
		glRectf(25, -185, 35, -180);
		glColor3f(1, 0, 0);
		glRectf(65, -185, 75, -180);

		//FARURI
		glColor3f(0.8, 0.5, 0);
		glRectf(25, -90, 35, -85);
		glColor3f(0.8, 0.5, 0);
		glRectf(65, -90, 75, -85);


		glColor3f(1, 1, 0);
		glBegin(GL_TRIANGLES);
		glVertex2f(30, -85);
		glVertex2f(0, 0);
		glVertex2f(60, 0);

		glVertex2f(40, 0);
		glVertex2f(100, 0);
		glVertex2f(70, -85);

		glEnd();

		// GIROFAR


		glTranslated(50, -135, 0);
		glRotated(z*20, 0, 0, 1);
		glTranslated(-50, 135, 0);

		//girofar
		glColor4f(1, 0, 0, 0.5);
		glBegin(GL_TRIANGLES);
		glVertex2f(10, -115);
		glVertex2f(50, -135);
		glVertex2f(10, -155);
		glEnd();


		glColor4f(0, 0, 1, 0.5);
		glBegin(GL_TRIANGLES);
		glVertex2f(50, -135);
		glVertex2f(90, -115);
		glVertex2f(90, -155);
		glEnd();

		glPopMatrix();
		glPopMatrix();
		// incrementare pentru girofar si alte translatii
		glutIdleFunc(miscareGirofar);


		glPopMatrix();

		startgame();
		glutPostRedisplay();
		glutSwapBuffers();
		glFlush();
	}
}



void reshape(int w, int h)
{
	glViewport(0, 0, (GLsizei)w, (GLsizei)h);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	glOrtho(-100.0, 700.0, -140.0, 460.0, -1.0, 1.0);
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
}

void miscasus(void)
{
	if (ok != 0 && pauza)
	{
		
		if (j < 320)
		{
			contor = 1;
			j += 2;
			misca = 1;
		}
		

		glutPostRedisplay();
	}
}

void miscajos(void)
{
	if (ok != 0 && pauza)
	{
		if (j > 0)
		{
			contor = -1;
			j -= 2;
			misca = -1;
		}

		glutPostRedisplay();
	}
}
void display() {
	//glClear(GL_COLOR_BUFFER_BIT);
	if (start == 1) {
		glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
		drawScene();
	}
	if(start == 0) {
		glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
		StartMenu();
		
	}
	//glutSwapBuffers();
}
void menu(int choice) {
	wchar_t path[MAX_PATH];
	GetModuleFileNameW(NULL, path, MAX_PATH);
	directory = std::wstring(path);
	directory = directory.substr(0, directory.find_last_of(L"\\/"));
	std::wstring soundPath;
	soundPath = directory + L"\\muzica.wav";
	std::wcout << L"Project directory: " << soundPath << std::endl;
	switch (choice) {
	case 1:
		//Melodie 1
		soundPath = directory + L"\\muzica.wav";
		break;
	case 2:
		soundPath = directory + L"\\muzica2.wav";
		break;
	case 3:
		soundPath = directory + L"\\muzica3.wav";
		break;
	}

	if (PlaySound(soundPath.c_str(), NULL, SND_ASYNC))
		cout << "Muzica 1";
	glutPostRedisplay();
}

void createMenu() {
	menu_id = glutCreateMenu(menu);
	glutAddMenuEntry("Beat it", 1);
	glutAddMenuEntry("Bad", 2);
	glutAddMenuEntry("Billie Jean", 3);
	glutAttachMenu(GLUT_RIGHT_BUTTON);
}

void keyboard(int key, int x, int y)
{

	switch (key) {
	case GLUT_KEY_UP:
		isYellow2 = true;
		glutPostRedisplay();
		miscasus();
		break;
	case GLUT_KEY_DOWN:
		isYellow1 = true;
		glutPostRedisplay();
		miscajos();
		break;
		// other cases
	case GLUT_KEY_LEFT:
		if (acceleratie >= 1)
		acceleratie--;
		break;
	case GLUT_KEY_RIGHT:
		if(acceleratie <= 4)
		acceleratie++;
		break;
	case GLUT_KEY_F3:
		if (pauza == 0) {
			pauza = 1;
			paused = 0;
			timp = 0.15;
			control = 0;
			
		}
		else
		{
			pauza = 0;
			paused = 1;
			control = 1;

		}
		break;
	}
}




int main(int argc, char** argv)
{

	wchar_t path[MAX_PATH];
	GetModuleFileNameW(NULL, path, MAX_PATH);
	directory = std::wstring(path);
	directory = directory.substr(0, directory.find_last_of(L"\\/"));
	std::wstring soundPath = directory + L"\\muzica.wav";
	std::wcout << L"Project directory: " << soundPath << std::endl;
	if (PlaySound(soundPath.c_str(), NULL, SND_ASYNC))
		cout << "Muzica fundal";
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB);
	glutInitWindowSize(800, 600);
	glutInitWindowPosition(100, 100);
	glutCreateWindow("Depaseste masinile - mini game");
	glutMouseFunc(mouse);
	init();
	glutDisplayFunc(display);
	glutReshapeFunc(reshape);
	glutSpecialFunc(keyboard);
	glutTimerFunc(1000, timer, 0);
	createMenu();
	glutMainLoop();

}