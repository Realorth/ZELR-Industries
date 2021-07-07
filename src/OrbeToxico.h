#pragma once
#include "esfera.h"
#include "Interaccion.h"

class OrbeToxico:public esfera
{
public:
	OrbeToxico();
	OrbeToxico(float rad, float x = 0.0f, float y = 0.0f, float vx = 0.0f, float vy = 0.0f);
	virtual ~OrbeToxico();
	void dibuja();
};

