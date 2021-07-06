#include "flecha.h"

flecha::flecha() :disparo(),S_Flecha("imagenes/flecha.png")
{
	aceleracion.x = 9.8;
	aceleracion.y = 0;
	S_Flecha.setCenter(0.3f, 0.5f);
	S_Flecha.setSize(1.5f, 1.5f);

}

flecha::~flecha()
{}

void flecha::dibuja() {
	glPushMatrix();
	glTranslatef(posicion.x, posicion.y+1, 0);
	S_Flecha.draw();
	glPopMatrix();
}
