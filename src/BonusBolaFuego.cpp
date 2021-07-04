#include "bonusBolaFuego.h"
#include "ETSIDI.h"

bonusBolaFuego::bonusBolaFuego() :S_BF("imagenes/bolaFuego.png"),bonus()
{
	S_BF.setCenter(posicion.x, posicion.y);
	S_BF.setSize(1.0f, 1.0f);
}
bonusBolaFuego::~bonusBolaFuego()
{}
void bonusBolaFuego::dibuja() {
	glPushMatrix();
	glTranslatef(posicion.x, posicion.y,0);
	S_BF.draw();
	glTranslatef(-posicion.x, -posicion.y, 0);
	glPopMatrix();


}

bonusBolaFuego::bonusBolaFuego(float x, float y) :S_BF("imagenes/bolaFuego.png"), bonus(x,y)
{

	S_BF.setCenter(posicion.x, posicion.y);
	S_BF.setSize(1.0f, 1.0f);
}

bonusBolaFuego::bonusBolaFuego(vector2D a) :S_BF("imagenes/bolaFuego.png"), bonus(a)
{
	S_BF.setCenter(posicion.x, posicion.y);
	S_BF.setSize(1.0f, 1.0f);
}

