#include "disparoespecial.h"
#include "freeglut.h"


disparoespecial::disparoespecial()
{

}
disparoespecial::~disparoespecial()
{}

void disparoespecial::dibuja()
{
	glColor3f(255.0f, 1.0f, 1.0f);
	glPushMatrix();
	glTranslatef(posicion.x, posicion.y, 0);
	glutSolidSphere(0.5, 20, 20);
	glPopMatrix();

	glColor3f(255.0f, 0.0f, 0.0f);
	glBegin(GL_LINES);
	glVertex2f(origen.x-0.25f, origen.y);
	glVertex2f(posicion.x-0.25, posicion.y);
	glColor3f(255.0f, 0.0f, 0.0f);
	glBegin(GL_LINES);
	glVertex2f(origen.x+0.25f, origen.y);
	glVertex2f(posicion.x+0.25f, posicion.y);
	glEnd();
	glFlush();
}