#include "disparo.h"
#include "freeglut.h"
#include <math.h>
#include "hombre.h"

disparo::disparo() :sprite("imagenes/disparo.png"),objetomovil()
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
void disparo::SetColor(Byte r, Byte g, Byte b) {
	color.set(r, g, b);
}
void disparo::SetRadio(float r) {
	radio = r;
}

float disparo::GetRadio()
{
	return radio;
}