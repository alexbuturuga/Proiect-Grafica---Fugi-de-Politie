#include <iostream>
#include <windows.h>
#include <GL/freeglut.h>
#include <Windows.h>
#include <filesystem>

//Maru ii beleste coaiele lui Biciclentiu
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

double contor = 0;
double loc_vert = 800;
int vector[3] = { 0, 160, 320 };
double height = vector[rand() % 3];
int score = 0;
double timp = 0.15;
int pct = 1000;
int ok2 = 0;
double rsj, rdj, rss, rds = 0;

void init(void)
{
	glClearColor(0.5, 0.5, 0.5, 0.0);
	glMatrixMode(GL_PROJECTION);
	glOrtho(left_m, right_m, bottom_m, top_m, -1.0, 1.0);
}

void RenderString(float x, float y, void* font, const unsigned char* string)
{

	glColor3f(0.0f, 0.0f, 0.0f);
	glRasterPos2f(x, y);

	glutBitmapString(font, string);
}
void miscareGirofar(void) {
	// pentru girofar
	z += 0.05;
	if (z > 360) {
		z = 0;
	}
	if (z < 0) {
		z = 360;
	}

	// pentru schimbarea benzii
	if (i > xFinal && i > -120) {
		i -= 0.15;
	}
	if (i < xFinal && i < 20) {
		i += 0.15;
	}


	glutPostRedisplay();
}
void startgame(void)
{

	if (height != j || (loc_vert > 90 || loc_vert < -90))
	{

		if (i < -380)
		{
			i = 0;
		}
		i = i - 2 * timp;

		loc_vert -= timp;

		if (loc_vert < -150)
		{
			score += 100;
			height = vector[rand() % 3];
			cout << "Score:  " << score << endl;
			loc_vert = 800;
		}

		if (score >= pct && pct <= 15000)
		{
			timp += 0.1;
			pct += 1000;
		}

		glutPostRedisplay();
	}
	else {
		ok = 0;
	}
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

	// Liniile intrerupte
	glPushMatrix();
	glTranslated(i, 0.0, 0.0);

	


	glEnable(GL_LINE_STIPPLE);
	glLineStipple(1, 0x00FF);
	glBegin(GL_LINES);
	glVertex2i(-100, 80);
	glVertex2i(1500, 80);
	glEnd();
	glDisable(GL_LINE_STIPPLE);

	
	glEnable(GL_LINE_STIPPLE);
	glLineStipple(1, 0x00FF);
	glBegin(GL_LINES);
	glVertex2i(-100, 240);
	glVertex2i(1500, 240);
	glEnd();
	glDisable(GL_LINE_STIPPLE);
	glPopMatrix();



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

	if (ok == 0)
	{
		rsj = 8;
		rss = -8;
		rdj = -8;
		rds = 8;
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
	glTranslated(loc_vert, height-48, 0.0);

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
	if (ok != 0)
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
	if (ok != 0)
	{
		if (j > 0)
		{
			contor = -1;
			j -= 1;


		}

		glutPostRedisplay();
	}
}

void keyboard(int key, int x, int y)
{


	switch (key) {
	case GLUT_KEY_UP:
		miscasus();
		break;
	case GLUT_KEY_DOWN:
		miscajos();
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
	init();
	glutDisplayFunc(drawScene);
	glutReshapeFunc(reshape);
	glutSpecialFunc(keyboard);

	glutMainLoop();
}