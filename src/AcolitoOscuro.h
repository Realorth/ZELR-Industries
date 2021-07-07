#pragma once
#include "Enemigos.h"
#include "Interaccion.h"
class AcolitoOscuro :public Enemigos
{
public:
	~AcolitoOscuro();

	AcolitoOscuro(float x, float y);
	AcolitoOscuro(vector2D a);
	AcolitoOscuro();

	void mueve(float t) { objetomovil::mueve(t); if (velocidad.y < -5.0)velocidad.y = -5.0f; }
	void gira();
	
};

