#include "bala.h"
bala::bala() :disparo()
{
	textura = "imagenes/disparo.png";
}

bala::bala(float x, float y) :disparo(x, y, "imagenes/disparo.png")
{
}

bala::bala(vector2D a) : disparo(a, "imagenes/disparo.png")
{
}

bala::bala(vector2D a, vector2D origen) : disparo(a, origen, "imagenes/disparo.png")
{
}

bala::~bala()
{}
