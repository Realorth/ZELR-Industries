#pragma once
#include "disparo.h"
class flecha :public disparo
{
protected:
	ETSIDI::Sprite S_Flecha;

public:
	flecha();
	flecha(float, float);
	flecha(vector2D);
	flecha(vector2D, vector2D);
	virtual ~flecha();
	void dibuja();
};


