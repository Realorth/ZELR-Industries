#include "Murcielago.h"



Murcielago::Murcielago() :Enemigos(0, 0, "imagenes/Eagle.png", 4)
{
	velocidad.x = 3.0f;
}
Murcielago::Murcielago(float x, float y):Enemigos(x, y, "imagenes/Eagle.png", 4)
{
	velocidad.x = 3.0f;
}
Murcielago::Murcielago(vector2D a): Enemigos(a, "imagenes/Eagle.png", 4)
{
	velocidad.x = 3.0f;
}
