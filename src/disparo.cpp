#include "disparo.h"
#include "freeglut.h"
#include <math.h>
#include "hombre.h"

disparo::disparo() :objetomovil()
{
	aceleracion.x = 9.8;
	aceleracion.y = 0;
	

}



disparo::~disparo()
{}

void disparo::dibuja()
{
	
}


void disparo::SetOrigen(float ox, float oy)
{
	origen.x = ox;
	origen.y = oy;
}
void disparo::SetColor(Byte r, Byte g, Byte b) {
	color.set(r, g, b);
}
void disparo::SetRadio(float r) {
	radio = r;
}

float disparo::GetRadio()
{
	return radio;
}

float disparo::GetLongitud()
{
	vector2D distancia = posicion - origen;

	return sqrt(distancia.x*distancia.x+distancia.y*distancia.y);
}
