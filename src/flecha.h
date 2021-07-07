#pragma once
#include "disparo.h"
class flecha :public disparo
{
public:
	flecha();
	flecha(float, float);
	flecha(vector2D);
	flecha(vector2D, vector2D);
	virtual ~flecha();
};


