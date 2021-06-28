#pragma once
#include "pared.h"
#include "hombre.h"
#include "ETSIDI.h" 

class caja
{
public:
	caja();
	//virtual ~caja();
	void dibuja();

	friend class Interaccion;

private:
	pared suelo;
	pared techo;
	pared pared_izq;
	pared pared_dcha;

	//void chequea(hombre & hombre);
};



