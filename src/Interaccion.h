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

class Interaccion
{
public:
	virtual ~Interaccion();

	static bool colision(disparo d, pared p);

	static void rebote(hombre& h,std::vector<pared*> d);
	static void colision_border(hombre& h, std::vector<pared*> p);


  
	static void colision(hombre& h, pared p);
	//Cosas  nuevas añadidas
	//static bool colision(hombre h, bonus b);
	//static bool colision(hombre h, BonusArmadura b);
	//static bool colision(hombre h, BonusCorazon b);
	//static bool colision(hombre h, bonusBolaFuego b);
	static bool colision(hombre h, bonus& b);
	static bool colision(hombre h, coin c);
	static bool muertecaida(hombre h);
};

