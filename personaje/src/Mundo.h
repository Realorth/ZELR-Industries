#pragma once
#include "caja.h"
#include "hombre.h"
#include "esfera.h"
#include "bonus.h"
#include "disparo.h"
#include "pared.h"
#include "listaesferas.h"
#include "esferapulsante.h"
#include "disparoespecial.h"

#include "BonusCorazon.h"
#include "BonusArmadura.h"
#include "bonusBolaFuego.h"
//#include "ListaBonus.h"
#include "ListaCoins.h"
#include "coin.h"
#include <string>
#include <iostream>
#include "ListaArmaduras.h"
#include "ListaCorazones.h"
#include "ListaBolaFuego.h"

class Mundo
{
public: 
	virtual ~ Mundo();
	void tecla(unsigned char key);
	void inicializa();
	void rotarOjo();
	void mueve();
	void dibuja();
	void teclaEspecial(unsigned char key);
	void teclaEspecialUp(unsigned char key);
	int getnCoin() { return ncoin; }
	bool getImpacto() { return impacto; }
	
private:
    float x_ojo;
	float y_ojo;
	float z_ojo;
   // esfera esfera2;
	//disparo disparo1;
	//esfera esfera1;
	hombre hombre;
	caja caja;
	//bonus bonus;
	pared plataforma;
	listaesferas esferas;
	listadisparos disparos;
	esferapulsante esferaspulsantes;
	disparoespecial disparogrande;
	
	std::string s = std::to_string(ncoin);
	char const* pcoin = s.c_str();  //use char const* as target type
	/*char mchar = to_chars(m);
	const char* pm;*/
	

	//ListaBonus listaBonus;
	ListaArmaduras listaArmaduras;
	ListaCorazones listaCorazones;
	ListaBolaFuego listaBFuego;
	ListaCoins listaCoins;
	BonusCorazon corazon;
	BonusArmadura armadura;
	bonusBolaFuego bolaFuego;
	coin moneda1;
	coin moneda2;
	bool impacto;
	int ncoin = 0;
	
};
