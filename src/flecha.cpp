#include "flecha.h"

flecha::flecha() :disparo(),S_Flecha("imagenes/flecha.png")
{
	aceleracion.x = 9.8;
	aceleracion.y = 0;
	S_Flecha.setCenter(posicion.x, posicion.y);
	S_Flecha.setPos(posicion.x, posicion.y);
	S_Flecha.setSize(2.0f, 2.0f);
}

flecha::flecha(float x, float y) :disparo(x, y), S_Flecha("imagenes/flecha.png")
{
	S_Flecha.setCenter(posicion.x, posicion.y);
	S_Flecha.setPos(posicion.x, posicion.y);
	S_Flecha.setSize(2.0f, 2.0f);
}

flecha::flecha(vector2D a) : disparo(a), S_Flecha("imagenes/flecha.png")
{
	S_Flecha.setCenter(posicion.x, posicion.y);
	S_Flecha.setPos(posicion.x, posicion.y);
	S_Flecha.setSize(2.0f, 2.0f);
}

flecha::flecha(vector2D a, vector2D origen):disparo(a,origen), S_Flecha("imagenes/flecha.png")
{
	S_Flecha.setCenter(posicion.x, posicion.y);
	S_Flecha.setPos(posicion.x, posicion.y);
	S_Flecha.setSize(2.0f, 2.0f);
}

flecha::~flecha()
{}

void flecha::dibuja() {
	glPushMatrix();
	glTranslatef(posicion.x, posicion.y+0.4, 0);
	S_Flecha.draw();
	glPopMatrix();
}
