#pragma once
#include "disparo.h"
class Magia:public disparo
{
public:
	Magia();
	Magia(float, float);
	Magia(vector2D);
	Magia(vector2D, vector2D);
	virtual ~Magia();
};


