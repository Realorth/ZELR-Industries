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
class Interaccion
{
public:
	virtual ~Interaccion();

	static bool colision(disparo d, pared p);

	static void rebote(hombre& h,std::vector<pared*> d);
	

	static void rebote(Enemigos& e, std::vector<pared*> d);
	static bool colision(Enemigos& e, pared p);
	//static bool Borde(Enemigos&e, std::vector<pared*> d);
	
	static void colision(hombre& h, pared p);
//	static bool borde(Enemigos& a, pared p);
	//Cosas  nuevas añadidas
	//static bool colision(hombre h, bonus b);
	//static bool colision(hombre h, BonusArmadura b);
	//static bool colision(hombre h, BonusCorazon b);
	//static bool colision(hombre h, bonusBolaFuego b);
	static bool colision(hombre h, bonus& b);
	static bool colision(hombre h, coin c);
	static bool muertecaida(hombre h);

	static bool proximidad(hombre& h, Enemigos& e);
	static bool colision(hombre& h, Enemigos& e);
	static bool deteccion(hombre& h, Enemigos& e);
	bool colision(objetomovil& e, pared p);
};

