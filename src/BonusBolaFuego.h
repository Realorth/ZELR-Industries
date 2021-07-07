#pragma once
#include "bonus.h"

class bonusBolaFuego :public bonus
{
protected:

public:
	bonusBolaFuego();
	bonusBolaFuego(float x, float y);
	bonusBolaFuego(vector2D);
	virtual ~bonusBolaFuego();

};


