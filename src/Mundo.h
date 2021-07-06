#pragma once
#include "hombre.h"
#include "Pistolero.h"
#include "mago.h"
#include "arquero.h"
#include "bonus.h"
#include "disparo.h"
#include "flecha.h"
#include "Magia.h"
#include "bala.h"
#include "pared.h"
#include "disparoespecial.h"
#include "Vector3D.h"
#include "BonusCorazon.h"
#include "BonusArmadura.h"
#include "bonusBolaFuego.h"
#include "fondo.h"
#include "plataforma.h"
#include "suelo.h"
#include "ListaCoins.h"
#include "coin.h"
#include <string>
#include <iostream>
#include "ListaArmaduras.h"
#include "ListaCorazones.h"
#include "ListaBolaFuego.h"
#include "LlaveFin.h"
class Mundo
{
public:
	//Enumeracion para saber que mundo se va a generar
	enum tipo { CEMENTERIO = 0, NIEVE, BASICO };

public: 
	Mundo();
	virtual ~ Mundo();
	void tecla(unsigned char key);
	void inicializa();
	void mueve();
	void dibuja();
	void teclaEspecial(unsigned char key);
	void teclaEspecialUp(unsigned char key);
	int getnCoin() { return ncoin; }
	bool getImpacto() { return impacto; }
	void setImpacto(bool i) { impacto = i; }
	bool getcaida() { return caida; }
	void setcaida(bool c) { caida = c; }
	Vector3D getOjo() { return Vector3D(x_ojo, y_ojo, z_ojo); }
	void setFin(bool f) { fin = f; }
	bool getFin() { return fin; }
	void setMapa(int a);
	void setMapa(tipo a) { ptipo = a; }
	void destruirMapa() ;
	bool CargarNivel();//Falta por definir
	void Genera();
	void setPersonaje(int n) { EleccionPersonaje = n; }
private:
	Vector3D ojo;
    float x_ojo;
	float y_ojo;
	float z_ojo;
	bool impacto=false;
	bool caida = false;//True si el personaje se cae
	bool fin=false;//true si se llega al final del mapa y se toca la llave
	int ncoin = 0;//Numero de monedas de cada partida

	hombre* personaje;
	disparo* disparo1;

	listadisparos disparos;

	disparoespecial disparogrande;

	coin moneda1;
	coin moneda2;
	BonusCorazon corazon;
	BonusArmadura armadura;
	bonusBolaFuego bolaFuego;
	ListaArmaduras listaArmaduras;
	ListaCorazones listaCorazones;
	ListaBolaFuego listaBFuego;
	ListaCoins listaCoins;
	// Se crean instancias para cada parte del mundo
	suelo Suelos;
	plataforma Plataformas;
	fondo Fondo;
	LlaveFin llave;
	tipo ptipo/*=tipo::CEMENTERIO*/;//Guarda el tipo de mapa
	bool sentidoHombre=true;//True derecha, false izquierda
	int EleccionPersonaje;//0 es pistolero, 1 es arquero y 2 es mago
private:
	void destruirContenido();

};
