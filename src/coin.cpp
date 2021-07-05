#include "coin.h"



coin::coin() :S_coin("imagenes/coin.png"),bonus()
{
	S_coin.setCenter(posicion.x, posicion.y);
	S_coin.setPos(posicion.x, posicion.y);
	S_coin.setSize(1.0f, 1.0f);
}

coin::coin(float x, float y) :S_coin("imagenes/coin.png"),bonus(x,y)
{
	S_coin.setCenter(posicion.x, posicion.y);
	S_coin.setPos(posicion.x, posicion.y);
	S_coin.setSize(1.0f, 1.0f);
}

coin::coin(vector2D a):bonus(a), S_coin("imagenes/coin.png")
{
	S_coin.setCenter(posicion.x, posicion.y);
	S_coin.setPos(posicion.x, posicion.y);
	S_coin.setSize(1.0f, 1.0f);
}

void coin::dibuja()
{
	glPushMatrix();
	glTranslatef(this->posicion.x, this->posicion.y, 0.1f);
	S_coin.draw();
	glTranslatef(-this->posicion.x, -this->posicion.y, -0.1f);
	glPopMatrix();
}
