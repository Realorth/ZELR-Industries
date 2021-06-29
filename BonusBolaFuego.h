#pragma once
#include "bonus.h"

class bonusBolaFuego :public bonus
{
protected:
	ETSIDI::Sprite S_BF;
public:
	void dibuja();
	bonusBolaFuego();
	bonusBolaFuego(float x, float y);
	bonusBolaFuego(vector2D);
	virtual ~bonusBolaFuego();
};


