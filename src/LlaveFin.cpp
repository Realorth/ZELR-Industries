#include "LlaveFin.h"

LlaveFin::LlaveFin() :bonus()
{
	SetNombre("Llave");
	textura = "imagenes/llave.png";
	textura.setSize(1.0f, 1.0f);
	textura.setPos(posicion.x, posicion.y);
	textura.setCenter(0.5f, 0.5f);
}

LlaveFin::LlaveFin(float x, float y) : bonus(x, y, "imagenes/llave.png")
{
	SetNombre("Llave");
	textura.setSize(1.0f, 1.0f);
	textura.setPos(posicion.x, posicion.y);
	textura.setCenter(0.5f, 0.5f);
}

LlaveFin::LlaveFin(vector2D a) : bonus(a, "imagenes/llave.png")
{
	SetNombre("Llave");
	textura.setSize(1.0f, 1.0f);
	textura.setPos(posicion.x, posicion.y);
	textura.setCenter(0.5f, 0.5f);
}

LlaveFin::~LlaveFin()
{
}

void LlaveFin::dibuja()
{
	glPushMatrix();
	glTranslatef(posicion.x, posicion.y, 0);
	textura.draw();
	glPopMatrix();
}
