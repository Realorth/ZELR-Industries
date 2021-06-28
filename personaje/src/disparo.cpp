#include "disparo.h"
#include "freeglut.h"
#include <math.h>
#include "hombre.h"

disparo::disparo() :sprite("imagenes/disparo.png")
{
	aceleracion.x = 9.8;
	aceleracion.y = 0;
	sprite.setCenter(0.3f, 0.5f);
	sprite.setSize(1.5f, 1.5f);

}

disparo::~disparo()
{}

void disparo::dibuja()
{
	// TODO: Agregar aquí el código de implementación.
	/*glColor3f(0.0f, 1.0f, 1.0f);*/
	glPushMatrix();
	glTranslatef(posicion.x, posicion.y, 0);
	//glutSolidSphere(radio, 20, 20);
	sprite.draw();
	glPopMatrix();

	glColor3f(0.0f, 255.0f, 255.0f);
	glBegin(GL_LINES);
	glVertex2f(origen.x, origen.y);
	glVertex2f(posicion.x, posicion.y);
	glEnd();
	glFlush();
}


void disparo::SetOrigen(float ox, float oy)
{
	origen.x = ox;
	origen.y = oy;
}
void disparo::SetColor(unsigned char r, unsigned char v, unsigned char b) {
	rojo = r;
	verde = v;
	azul = b;
}
void disparo::SetRadio(float r) {
	radio = r;
}

float disparo::GetRadio()
{
	return radio;
}