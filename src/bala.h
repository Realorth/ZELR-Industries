#pragma once
#include "disparo.h"
class bala :
    public disparo
{
public:
	bala();
	bala(float, float);
	bala(vector2D);
	bala(vector2D, vector2D);
	virtual ~bala();
	void dibuja();
protected:
	ETSIDI::Sprite SBala;
};
