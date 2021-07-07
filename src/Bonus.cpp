#include "bonus.h"
#include <stdlib.h>
#include "freeglut.h"
#include "ETSIDI.h"

bonus::bonus():objetomovil(),textura("imagenes/coin.png")
{
	textura.setSize(1.0f, 1.0f);
	textura.setPos(posicion.x, posicion.y);
	textura.setCenter(0.5f, 0.5f);
}

bonus::bonus(float x, float y, const char* b) : objetomovil(x, y), textura(b)
{
	textura.setSize(1.0f, 1.0f);
	textura.setPos(posicion.x, posicion.y);
	textura.setCenter(0.5f, 0.5f);
}

bonus::bonus(vector2D a, const char* b) :objetomovil(a), textura(b)
{
	textura.setSize(1.0f, 1.0f);
	textura.setPos(posicion.x, posicion.y);
	textura.setCenter(0.5f, 0.5f);
}

bonus::~bonus()
{}

void bonus::dibuja()
{
	textura.draw();
}

