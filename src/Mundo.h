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
#include "coin.h"
#include <string>
#include <iostream>
#include "ListaBonus.h"
#include "LlaveFin.h"
#include "Murcielago.h"
#include "PerroVil.h"
#include "AcolitoOscuro.h"
#include"ListaEnemigos.h"
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
	void GestorNiveles();
	void Genera();
	void setPersonaje(int n) { EleccionPersonaje = n; }
	
	bool getFinalJuego() { return flag_Final; }
	bool getFinalMuerte() { return flag_Muerte; }
	void setFinalJuego(bool a) { flag_Final = a; }
	void setFinalMuerte(bool a) { flag_Muerte = a;  }

	void setFlagMapa(bool a) { flagMapa = a; }
	bool getFlagMapa() { return flagMapa; }
private:
	Vector3D ojo;
    float x_ojo;
	float y_ojo;
	float z_ojo;
	bool impacto=false;
	bool caida = false;//True si el personaje se cae
	bool fin=false;//true si se llega al final del mapa y se toca la llave
	int ncoin = 0;//Numero de monedas de cada partida
		
	bool flag_Muerte = false;//Representa el estado
	// acabar el juego por falta de vidas
	bool flag_Final = false;//Representa el final del juego
	int Cual_Mapa = 0;
	bool flagMapa = true;
	hombre* personaje;
	disparo* disparo1;
	ListaEnemigos WolfPack;
	ListaBonus listaBonus;
	listadisparos disparos;
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
	bool CargarNivel();//Falta por definir
};
