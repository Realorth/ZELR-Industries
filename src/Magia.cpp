#include "Magia.h"

Magia::Magia():disparo()
{
	textura = "imagenes/magia.png";
}

Magia::Magia(float x, float y) :disparo(x, y, "imagenes/magia.png")
{
}

Magia::Magia(vector2D a) : disparo(a, "imagenes/magia.png")
{
}

Magia::Magia(vector2D a, vector2D origen) : disparo(a, origen, "imagenes/magia.png")
{	
}

Magia::~Magia()
{
}
