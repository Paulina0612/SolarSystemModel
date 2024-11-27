#include <gl/glut.h>
#include <gl/GL.h>
#define _USE_MATH_DEFINES
#include <math.h>

#include "Sphere.h"

#define WIDTH 550
#define HEIGHT 550
#define POSITIONX 200
#define POSITIONY 100

using namespace std;

void Display()
{
	// Pixels clear
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

	glFlush();
	glutSwapBuffers();
}

void Init()
{
	// Black background
	glClearColor(0.0, 0.0, 0.0, 0.0);

	// Setting up the perspective
	glEnable(GL_DEPTH_TEST); 
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluPerspective(5.0, (double)WIDTH/HEIGHT, -10, 10.0); 
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
	gluLookAt(	0.0, 0.0, 0.0, 
				0.0, 0.0, 0.0, 
				0.0, 1.0, 0.0); 
}

void Mouse(int button, int state, int x, int y)
{

}

void Keyboard(unsigned char key, int x, int y) 
{
	
}

int main(int argc, char* argv[])
{
	// Init
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB);
	glutInitWindowSize(WIDTH, HEIGHT);
	glutInitWindowPosition(POSITIONX, POSITIONY);
	glutCreateWindow("Solar system model");
	Init();

	// Display function
	glutDisplayFunc(Display);

	// Enabling interaction with user
	glutKeyboardFunc(Keyboard);
	glutMouseFunc(Mouse);

	// Main program loop
	glutMainLoop();

	return 0;
}
