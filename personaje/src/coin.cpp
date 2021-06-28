#include "coin.h"



coin::coin():S_coin("imagenes/coin.png")
{
	S_coin.setCenter(posicion.x, posicion.y);
	S_coin.setSize(1.0f, 1.0f);
}

coin::coin(float x, float y):S_coin("imagenes/coin.png")
{
	posicion.x = x;
	posicion.y = y;
}

void coin::dibuja()
{
	glPushMatrix();
	glTranslatef(posicion.x, posicion.y, 0);
	S_coin.draw();
	glPopMatrix();
}