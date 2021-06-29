#pragma once
#include "pared.h"
#include "hombre.h"
#include "ETSIDI.h" 
#include<vector>
class caja
{
public:
	caja();
	virtual ~caja();
	void dibuja();

	friend class Interaccion;

private:
	pared suelo;
	pared techo;
	pared pared_izq;
	pared pared_dcha;
	std::vector<pared*> test;
	//void chequea(hombre & hombre);
	void dibuja_test();
	void textura_test(pared* s);

	void borrar();
protected:

};



