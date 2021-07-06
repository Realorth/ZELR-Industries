#include "disparo.h"
#include "freeglut.h"
#include <math.h>
#include "hombre.h"

disparo::disparo() :sprite("imagenes/disparo.png"),objetomovil()
{
	aceleracion.x = 9.8;
	aceleracion.y = 0;
	sprite.setCenter(0.3f, 0.5f);
	sprite.setSize(1.5f, 1.5f);

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
