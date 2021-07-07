#include "PerroVil.h"

PerroVil::PerroVil(float x, float y) :
	Enemigos(x, y, "imagenes/wolfy.png",4)
{
	velocidad.x = 3.0f;
}

PerroVil::PerroVil(vector2D a):
	Enemigos(a,"imagenes/wolfy.png",4)
{
	velocidad.x =3.0f;
}

PerroVil::PerroVil():
	Enemigos(0,0, "imagenes/wolfy.png", 4)
{
	velocidad.x = 3.0f;
}

void PerroVil::ataca() {}
