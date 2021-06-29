#pragma once
#include "hombre.h"
#include "caja.h"
#include "esfera.h"
#include "listaesferas.h"
#include "listadisparos.h"
#include "disparo.h"
#include "bonus.h"
#include <vector>
class Interaccion
{
public:
	virtual ~Interaccion();
	static bool rebote(esfera& e, pared p);
	static void rebote(esfera& e, caja c);
	static bool rebote(esfera& e, esfera& e2);
	static bool colision(esfera e, hombre h);
	static bool colision(disparo d, pared p);
	static bool colision(disparo d, caja c);
	static void rebote(hombre& h,std::vector<pared*> d);



    static void rebote(hombre& h, caja c);
	static void colision(hombre& h, pared p);
	//Cosas  nuevas añadidas
	static bool colision(hombre h, bonus b);

};

