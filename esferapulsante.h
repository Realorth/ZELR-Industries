#pragma once
#include "esfera.h"

class esferapulsante: public esfera
{
public:
	esferapulsante();
	~esferapulsante();

	void mueve(float t);

private:
	float pulso;
	float radio_max;
	float radio_min;

};

