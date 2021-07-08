#pragma once
#include "Enemigos.h"
#include "hombre.h"

class Murcielago:public Enemigos
{
	
public:
	public:
	Murcielago();
	Murcielago(float x, float y);
	Murcielago(vector2D a);
	virtual ~Murcielago(){}

	void mueve(float t) { objetomovil::mueve(t); if (velocidad.y < -5.0)velocidad.y = -5.0f; }
};

