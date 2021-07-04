#include "LlaveFin.h"

LlaveFin::LlaveFin() :bonus(), S_llave("imagenes/llave.png")
{
	S_llave.setCenter(posicion.x, posicion.y);
	S_llave.setSize(1.0f, 1.0f);
}

LlaveFin::LlaveFin(float x, float y) : bonus(x, y), S_llave("imagenes/llave.png")
{
	S_llave.setCenter(posicion.x, posicion.y);
	S_llave.setSize(1.0f, 1.0f);
}

LlaveFin::LlaveFin(vector2D a) : bonus(a), S_llave("imagenes/llave.png")
{
	S_llave.setCenter(posicion.x, posicion.y);
	S_llave.setSize(1.0f, 1.0f);
}

LlaveFin::~LlaveFin()
{
}

void LlaveFin::dibuja()
{
	glPushMatrix();
	glTranslatef(posicion.x, posicion.y, 0);
	S_llave.draw();
	glPopMatrix();
}