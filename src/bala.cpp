#include "bala.h"

bala::bala() :disparo("imagenes/disparo.png")
{
	aceleracion.x = 9.8;
	aceleracion.y = 0;
	sprite.setCenter(0.3f, 0.5f);
	sprite.setSize(1.5f, 1.5f);

}

bala::~bala()
{}