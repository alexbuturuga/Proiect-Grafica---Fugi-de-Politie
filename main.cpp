#include <iostream>
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
double ok = 1;
double j = 0.0;
double i = 0.0;
double z = 0.0;
double PozitieCopac = 175;
double PozitieRock = 400;
double PozitieCasa = 660;
double PozitieBoschet = 900;
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

const int font1 = (int)GLUT_BITMAP_TIMES_ROMAN_24;
const int font2 = (int)GLUT_BITMAP_HELVETICA_18;
const int font3 = (int)GLUT_BITMAP_8_BY_13;


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
	
	//Road Backgound
	glColor3f(0.000, 0.392, 0.000);
	glBegin(GL_POLYGON);
	glVertex2f(0, 55);
	glVertex2f(100, 55);
	glColor3f(0.604, 0.804, 0.196);
	glVertex2f(100, 50 - 50);
	glVertex2f(0, 50 - 50);
	glEnd();
	//Road Design In Front Page
	glColor3f(00, 0, 0);
	glBegin(GL_TRIANGLES);
	glVertex2f(32 - 2 + 21, 55);
	glVertex2f(32 + 58, 50 - 50);
	glVertex2f(32 - 22, 50 - 50);
	glEnd();
	//Road Midle
	glColor3f(1, 1, 1);
	glBegin(GL_TRIANGLES);
	glVertex2f(32 - 2 + 21, 55);
	glVertex2f(50 + 2, 50 - 50);
	glVertex2f(50 - 2, 50 - 50);
	glEnd();
	//Road Sky
	glColor3f(0.000, 0.749, 1.000);
	glBegin(GL_POLYGON);
	glVertex2f(100, 100);
	glVertex2f(0, 100);
	glColor3f(0.686, 0.933, 0.933);
	glVertex2f(0, 55);
	glVertex2f(100, 55);
	glEnd();
	//Hill 1
	glColor3f(0.235, 0.702, 0.443);
	glBegin(GL_TRIANGLES);
	glVertex2f(20, 55 + 10);
	glVertex2f(20 + 7, 55);
	glVertex2f(0, 55);
	glEnd();
	//Hill 2
	glColor3f(0.000, 0.502, 0.000);
	glBegin(GL_TRIANGLES);
	glVertex2f(20 + 15, 55 + 12);
	glVertex2f(20 + 20 + 10, 55);
	glVertex2f(0 + 10, 55);
	glEnd();
	//Hill 4
	glColor3f(0.235, 0.702, 0.443);
	glBegin(GL_TRIANGLES);
	glVertex2f(87, 55 + 10);
	glVertex2f(100, 55);
	glVertex2f(60, 55);
	glEnd();
	//Hill 3
	glColor3f(0.000, 0.502, 0.000);
	glBegin(GL_TRIANGLES);
	glVertex2f(70, 70);
	glVertex2f(90, 55);
	glVertex2f(50, 55);
	glEnd();
	//Tree Left
		//Bottom
	glColor3f(0.871, 0.722, 0.529);
	glBegin(GL_TRIANGLES);
	glVertex2f(11, 55);
	glVertex2f(12, 55 - 10);
	glVertex2f(10, 55 - 10);
	glEnd();
	//Up
	glColor3f(0.133, 0.545, 0.133);
	glBegin(GL_TRIANGLES);
	glVertex2f(11, 55 + 3);
	glVertex2f(12 + 3, 55 - 3);
	glVertex2f(10 - 3, 55 - 3);
	glEnd();
	drawTree(5, -15);
	drawTree(9, 5);
	drawTree(85, 9);
	drawTree(75, -5);
	

	
	
	//Text Information in Frist Page
	
	
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
	
	if (height != j || (loc_vert > 90 || loc_vert < -90))
	{
		if (pauza == 1)
		{
			if (PozitieCopac > -200)
			{
				PozitieCopac--;
			}
			else
			{
				PozitieCopac = 800;
			}
			if (PozitieCasa > -200)
			{
				PozitieCasa--;
			}
			else
			{
				PozitieCasa = 800;
			}
			if (PozitieBoschet > -200)
			{
				PozitieBoschet--;
			}
			else
			{
				PozitieBoschet = 800;
			}
			if (PozitieRock > -200)
			{
				PozitieRock--;
			}
			else
			{
				PozitieRock = 800;
			}

			if (i < -380)
			{
				i = 0;
			}
			i = i - 12 * timp;

			loc_vert -= 6 * timp;

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
	}
}
void renderPauseMenu() {
	glPushMatrix();
	glLoadIdentity();
	glColor3f(1.0f, 1.0f, 1.0f);
	glRasterPos2f(270.0f, 200.0f);
	glutBitmapString(GLUT_BITMAP_TIMES_ROMAN_24, (unsigned const char*)"Paused game");
	glRasterPos2f(240.0f, 170.0f);
	glutBitmapString(GLUT_BITMAP_HELVETICA_18, (unsigned const char*)"Press 'Right' to Resume");
	glPopMatrix();
}

void timer(int value) {
	isYellow1 = false;
	isYellow2 = false;

	glutPostRedisplay();
	glutTimerFunc(500, timer, 0); // call this function again after 1000 milliseconds
}

void drawScene(void)
{
	
	glClear(GL_COLOR_BUFFER_BIT);


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
		j = j + 1;
	else if (contor == -1 && (j != 160 && j != 0))
		j = j - 1;
	else {
		contor = 0;

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
	glRotated(z, 0, 0, 1);
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
			j += 1;
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
			j -= 1;


		}

		glutPostRedisplay();
	}
}
void display() {
	glClear(GL_COLOR_BUFFER_BIT);
	if (start == 1) {
		// glClearColor(0.627, 0.322, 0.176,1);

		//glClearColor(0.5, 0.5, 0.5, 0.0);
		glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
		
		drawScene();
	}
	if(start == 0) {
		firstDesign();
		
		glClearColor(0.5, 0.5, 0.5, 0.0);
	}
	//glFlush();
	glutSwapBuffers();
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
		paused = 1;
		pauza = 0;
		break;
	case GLUT_KEY_RIGHT:
		paused = 0;
		pauza = 1;
		timp = 0.15;
		break;
	case GLUT_KEY_F3:
		if (start == 0) {
			start = 1;
		}
		
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
	init();
	glutDisplayFunc(display);
	glutReshapeFunc(reshape);
	glutSpecialFunc(keyboard);
	glutTimerFunc(1000, timer, 0);
	createMenu();
	glutMainLoop();

}