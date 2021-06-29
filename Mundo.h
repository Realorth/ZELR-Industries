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
#include "Vector3D.h"
#include "BonusCorazon.h"
#include "BonusArmadura.h"
#include "bonusBolaFuego.h"
#include "ListaBonus.h"

#include"Mapa.h"
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

	
private:
	Vector3D ojo;
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

	ListaBonus listaBonus;
	BonusCorazon corazon;
	BonusArmadura armadura;
	bonusBolaFuego bolaFuego;

	Mapa mapa;
};
