#define _USE_MATH_DEFINES 
#include <iostream>
#include <cmath>
#include <glut.h>

using namespace std;

float v;
float vx;
float vy;
float a;
float wx;
float i;

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

float x(float vx, float t)
{
	return vx * t;
}

float y(float vy, float t)
{
	return vy * t - (10 * t * t / 2);
}

void display()
{
	glClear(GL_COLOR_BUFFER_BIT);
	glPointSize(2);
	glBegin(GL_POINTS);
	glColor3f(0.0, 0.0, 1.0);
	
	for (i = 0; i <= t(v, a); i += 0.1)
	{
		glVertex2f(x(vx, i), y(vy, i));
		if (i != 0)
			vx -= wx / 10;
	
	}

	cout << "------------------" << endl;
	cout << "t = " << t(v, a) << endl;
	//cout << "L = " << L(v, a) << endl;
	cout << "L = " << x(vx + wx / 10 , i - 0.1) << endl;
	cout << "h = " << h(v, a) << endl;
	cout << "------------------" << endl;

	glEnd();
	glFlush();
}

int main(int argc, char** argv)
{
	cout << "Velocity: ";
	cin >> v;
	cout << "Angle: ";
	cin >> a;
	cout << "Wind: ";
	cin >> wx;

	vx = v * cos(a * M_PI / 180);
	vy = v * sin(a * M_PI / 180);


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