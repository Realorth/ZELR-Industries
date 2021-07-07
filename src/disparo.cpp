#include "disparo.h"
#include "freeglut.h"
#include <math.h>
#include "hombre.h"
#include <string>

disparo::disparo() :objetomovil(), textura("imagenes/disparo.png")
{
	aceleracion.x = 9.8;
	aceleracion.y = 0;
	textura.setSize(1.5f, 1.5f);
	textura.setPos(posicion.x, posicion.y);
	textura.setCenter(posicion.x, posicion.y);
}

disparo::disparo(float x, float y, const char* b) : objetomovil(x, y), textura(b)
{
	if (!strcmp(b, "imagenes/AtaqueBolaFuego.png")) textura.setSize(2.5f, 2.5f);//Mas grande
	else textura.setSize(1.5f, 1.5f);
	textura.setPos(posicion.x, posicion.y);
	textura.setCenter(posicion.x, posicion.y);
}

disparo::disparo(vector2D a, const char* b) : objetomovil(a), textura(b)
{
	if (!strcmp(b, "imagenes/AtaqueBolaFuego.png")) textura.setSize(2.5f, 2.5f);//Mas grande
	else textura.setSize(1.5f, 1.5f);
	textura.setPos(posicion.x, posicion.y);
	textura.setCenter(posicion.x, posicion.y);
}

disparo::disparo(vector2D a, vector2D origen, const char* b) : objetomovil(a), origen(origen),textura(b)
{
	if (!strcmp(b, "imagenes/AtaqueBolaFuego.png")) textura.setSize(2.5f, 2.5f);//Mas grande
	else textura.setSize(1.5f, 1.5f);
	textura.setPos(posicion.x, posicion.y);
	textura.setCenter(posicion.x, posicion.y);
}



disparo::~disparo()
{}

void disparo::dibuja()
{
	glPushMatrix();
	glTranslatef(posicion.x, posicion.y+0.3, 0);
	textura.draw();
	glPopMatrix();
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



