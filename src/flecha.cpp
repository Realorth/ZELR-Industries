#include "flecha.h"

flecha::flecha() :disparo()
{
	textura = "imagenes/flecha.png";
}

flecha::flecha(float x, float y) :disparo(x, y, "imagenes/flecha.png")
{
}

flecha::flecha(vector2D a) : disparo(a, "imagenes/flecha.png")
{
}

flecha::flecha(vector2D a, vector2D origen):disparo(a,origen, "imagenes/flecha.png")
{
}

flecha::~flecha()
{}
