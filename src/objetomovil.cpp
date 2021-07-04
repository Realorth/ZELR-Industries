#include "objetomovil.h"

objetomovil::objetomovil():posicion(),velocidad(),aceleracion()
{

}

objetomovil::~objetomovil()
{}

void objetomovil::mueve(float t)
{
	posicion = posicion + velocidad * t + aceleracion * (t * t * 0.5f);
	velocidad = velocidad + aceleracion * t;
}
vector2D& objetomovil::GetPos()
{
	return posicion;
}
void objetomovil::SetPos(float x, float y)
{
	posicion.x = x;
	posicion.y = y;
}
void objetomovil::SetVel(float x, float y)
{
	velocidad.x = x;
	velocidad.y = y;
}
void objetomovil::SetAcel(float x, float y)
{
	aceleracion.x = x;
	aceleracion.y = y;
}


