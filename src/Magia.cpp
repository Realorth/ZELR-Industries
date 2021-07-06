#include "Magia.h"

Magia::Magia():disparo(), SMagia("imagenes/magia.png")
{
	aceleracion.x = 9.8;
	aceleracion.y = 0;
	SMagia.setCenter(0.3f, 0.5f);
	SMagia.setSize(1.5f, 1.5f);
}

Magia::~Magia()
{
}

void Magia::dibuja()
{
	glPushMatrix();
	glTranslatef(posicion.x, posicion.y+1.0, 0);
	SMagia.draw();
	glPopMatrix();
}
