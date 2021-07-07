#include "bala.h"
bala::bala() :disparo(),SBala("imagenes/disparo.png")
{
	aceleracion.x = 9.8;
	aceleracion.y = 0;
	SBala.setCenter(posicion.x, posicion.y);
	SBala.setPos(posicion.x, posicion.y);
	SBala.setSize(1.5f, 1.5f);

}

bala::bala(float x, float y) :disparo(x, y), SBala("imagenes/disparo.png")
{
	SBala.setCenter(posicion.x, posicion.y);
	SBala.setPos(posicion.x, posicion.y);
	SBala.setSize(1.5f, 1.5f);
}

bala::bala(vector2D a) : disparo(a), SBala("imagenes/disparo.png")
{
	SBala.setCenter(posicion.x, posicion.y);
	SBala.setPos(posicion.x, posicion.y);
	SBala.setSize(1.5f, 1.5f);
}

bala::bala(vector2D a, vector2D origen) : disparo(a, origen), SBala("imagenes/disparo.png")
{
	SBala.setCenter(posicion.x, posicion.y);
	SBala.setPos(posicion.x, posicion.y);
	SBala.setSize(1.5f, 1.5f);
}

bala::~bala()
{}

void bala::dibuja()
{
	glPushMatrix();
	glTranslatef(posicion.x, posicion.y+0.3, 0);
	SBala.draw();
	glPopMatrix();
}

