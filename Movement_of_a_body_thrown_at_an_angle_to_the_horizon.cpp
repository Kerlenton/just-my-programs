#define _USE_MATH_DEFINES 
#include <iostream>
#include <cmath>
#include <glut.h>

using namespace std;


float v;
float a;
float a1;
double view = 220.0;

float t(float v, float a)
{
	return (v * sin(a * M_PI / 180) * 2) / 10;
}

float h(float v, float a)
{
	return (v * v * sin(a * M_PI / 180) * sin(a * M_PI / 180)) / 10;
}

float L(float v, float a)
{
	return (v * v * sin(2 * a * M_PI / 180)) / 10;
}

float x(float v, float a, float t)
{
	return v * cos(a * M_PI / 180) * t;
}

float y(float v, float a, float t)
{
	return v * sin(a * M_PI / 180) * t - (10 * t * t / 2);
}

void display()
{
	glClear(GL_COLOR_BUFFER_BIT);
	glPointSize(2);
	glBegin(GL_POINTS);
	glColor3f(1.0, 0.0, 0.0);
	for (float i = 0; i <= t(v, a); i += 0.1)
		glVertex2f(x(v, a, i), y(v, a, i));
	glColor3f(0.0, 0.0, 0.0);
	for (float j = 0; j <= t(v, a1); j += 0.2)
		glVertex2f(x(v, a1, j), y(v, a1, j));
	glEnd();
	glFlush();
}

int main(int argc, char** argv) 
{
	cout << "Velocity: ";
	cin >> v;
	cout << "Angle: ";
	cin >> a;

	cout << "Angle: ";
	cin >> a1;

	cout << "------------------" << endl;
	cout << "t = " << t(v, a) << endl;
	cout << "L = " << L(v, a) << endl;
	cout << "h = " << h(v, a) << endl;
	cout << "------------------" << endl;

	glutInit(&argc, argv);

	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);

	glutInitWindowSize(500, 500);

	glutInitWindowPosition(400, 150);

	glutCreateWindow("WebWindow");
	
	glClearColor(1.0, 1.0, 1.0, 1.0);

	glMatrixMode(GL_PROJECTION);

	glLoadIdentity();

	glOrtho(0.0, view, 0.0, view, -1.0, 1.0);

	glutDisplayFunc(display);

	glutMainLoop();

	return 0;
}