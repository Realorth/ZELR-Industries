#pragma once
#include "hombre.h"
#include "listadisparos.h"
#include "disparo.h"
#include "bonus.h"
#include <vector>
#include "BonusArmadura.h"
#include "BonusCorazon.h"
#include "BonusBolaFuego.h"
#include "coin.h"
#include"Enemigos.h"
#include"ListaEnemigos.h"
#include "listadisparos.h"
#include "ListaBonus.h"
class Interaccion
{
public:
	virtual ~Interaccion();

	static bool colision(disparo d, pared p);

	static void rebote(hombre& h,std::vector<pared*> d);
	
	static void rebote(Enemigos** lista, std::vector<pared*>d);
	static void rebote(Enemigos& e, std::vector<pared*> d);
	static bool colision(Enemigos& e, pared p);

	static bool colision(Enemigos& e, disparo& d);
	static float colision(Enemigos* e, listadisparos& ld);


	static void colision(hombre& h, pared p);

	static bool colision(hombre h, bonus& b);
	static bool muertecaida(hombre h);



	static bool proximidad(hombre& h, Enemigos& e);
	static bool colision(hombre& h, Enemigos& e);
	static void colision(hombre& h, Enemigos** le);
	static bool deteccion(hombre& h, Enemigos& e);
	static bool colision(objetomovil& e, pared p);


};

