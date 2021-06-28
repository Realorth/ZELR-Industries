#pragma once
#include "coin.h"
#include "Interaccion.h"
#include "hombre.h"
#define MAX_MONEDAS 20

class ListaCoins
{
private:
	coin* lista[MAX_MONEDAS];//vector de punteros a objetos tipo bonus
	int numero;//Lleva la cuenta de bonus existentes

public:
	ListaCoins();//Constructor sin argumentos
	virtual ~ListaCoins();
	bool agregar(coin* b);//Argumento la direccion del bonus
	void dibuja();
	//void mueve();
	void destruirContenido();
	void eliminar(int index);
	void eliminar(coin* c);
	coin* colision(hombre& h);

	coin* operator [](int i);
	int getNumero() { return numero; }
};

