#include "bonusBolaFuego.h"
#include "ETSIDI.h"

bonusBolaFuego::bonusBolaFuego() :bonus()
{
	textura = "imagenes/bolaFuego.png";

}
bonusBolaFuego::~bonusBolaFuego()
{}


bonusBolaFuego::bonusBolaFuego(float x, float y) : bonus(x,y, "imagenes/bolaFuego.png")
{
	
}

bonusBolaFuego::bonusBolaFuego(vector2D a) : bonus(a, "imagenes/bolaFuego.png")
{	
}
