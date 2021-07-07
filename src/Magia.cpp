#include "Magia.h"

Magia::Magia():disparo(), SMagia("imagenes/magia.png")
{
	aceleracion.x = 9.8;
	aceleracion.y = 0;
	SMagia.setCenter(posicion.x, posicion.y);
	SMagia.setPos(posicion.x, posicion.y);
	SMagia.setSize(1.5f, 1.5f);
}

Magia::Magia(float x, float y) :disparo(x, y), SMagia("imagenes/magia.png")
{
	SMagia.setCenter(posicion.x, posicion.y);
	SMagia.setPos(posicion.x, posicion.y);
	SMagia.setSize(1.5f, 1.5f);
}

Magia::Magia(vector2D a) : disparo(a), SMagia("imagenes/magia.png")
{
	SMagia.setCenter(posicion.x, posicion.y);
	SMagia.setPos(posicion.x, posicion.y);
	SMagia.setSize(1.5f, 1.5f);
}

Magia::Magia(vector2D a, vector2D origen) : disparo(a, origen), SMagia("imagenes/magia.png")
{
	SMagia.setCenter(posicion.x, posicion.y);
	SMagia.setPos(posicion.x, posicion.y);
	SMagia.setSize(1.5f, 1.5f);
}

Magia::~Magia()
{
}

void Magia::dibuja()
{
	glPushMatrix();
	glTranslatef(posicion.x, posicion.y+0.4, 0);
	SMagia.draw();
	glPopMatrix();
}
