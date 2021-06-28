#pragma once
#include "disparo.h"
#include "caja.h"
#include "pared.h"
#include "disparoespecial.h"
#define MAX_DISPAROS 10

class listadisparos
{
public:

	listadisparos();
	virtual ~listadisparos();
	bool agregar(disparo* d);
	void destruirContenido();
	void mueve(float t);
	void dibuja();
	void colision(pared p);
	disparo* colision(caja c);
	void eliminar(int index);
	void eliminar(disparo* d);

private:
	disparo* lista[MAX_DISPAROS];
	int numero;
};



