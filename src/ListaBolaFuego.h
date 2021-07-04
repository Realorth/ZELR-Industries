#pragma once
#include "bonus.h"
#include "Interaccion.h"
#include "hombre.h"

//#include "ListaBonus.h"

#define MAX_BOLASFUEGO 20

class ListaBolaFuego
{
private:
	bonusBolaFuego* lista[MAX_BOLASFUEGO];//vector de punteros a objetos tipo bonus
	int numero;//Lleva la cuenta de bonus existentes

public:
	ListaBolaFuego();//Constructor sin argumentos
	virtual ~ListaBolaFuego();
	bool agregar(bonusBolaFuego* b);//Argumento la direccion del bonus
	void dibuja();
	//void mueve();
	void destruirContenido();
	void eliminar(int index);
	void eliminar(bonusBolaFuego* b);
	bonusBolaFuego* colision(hombre& h);

	bonusBolaFuego* operator [](int i);
	int getNumero() { return numero; }
};

