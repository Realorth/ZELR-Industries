#pragma once
#include "hombre.h"
#include "caja.h"
#include "esfera.h"
#include "listaesferas.h"
#include "listadisparos.h"
#include "disparo.h"
#include "bonus.h"
#include "BonusArmadura.h"
#include "BonusCorazon.h"
#include "BonusBolaFuego.h"
#include "coin.h"


class Interaccion
{
public:
	
	static bool rebote(esfera& e, pared p);
	static void rebote(esfera& e, caja c);
	static bool rebote(esfera& e, esfera& e2);
	static bool colision(esfera e, hombre h);
	static bool colision(disparo d, pared p);
	static bool colision(disparo d, caja c);




    static void rebote(hombre& h, caja c);
	static void colision(hombre& h, pared p);
	//Cosas  nuevas añadidas
	//static bool colision(hombre h, BonusCorazon b);
	static bool colision(hombre h, BonusArmadura b);
	static bool colision(hombre h, BonusCorazon b);
	static bool colision(hombre h, bonusBolaFuego b);
	static bool colision(hombre h, coin c);

};

