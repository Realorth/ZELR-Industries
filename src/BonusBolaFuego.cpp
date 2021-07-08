#include "bonusBolaFuego.h"
#include "ETSIDI.h"

bonusBolaFuego::bonusBolaFuego() :bonus()
{
	textura = "imagenes/bolaFuego.png";
	SetNombre("BolaFuego");

}
bonusBolaFuego::~bonusBolaFuego()
{}


bonusBolaFuego::bonusBolaFuego(float x, float y) : bonus(x,y, "imagenes/bolaFuego.png")
{
	SetNombre("BolaFuego");
}

bonusBolaFuego::bonusBolaFuego(vector2D a) : bonus(a, "imagenes/bolaFuego.png")
{	
	SetNombre("BolaFuego");
}
