#pragma once
#include "bonus.h"
#include "Interaccion.h"
#include "hombre.h"
//#include "ListaBonus.h"

#define MAX_CORAZONES 20

class ListaCorazones
{
private:
	BonusCorazon* lista[MAX_CORAZONES];//vector de punteros a objetos tipo bonus
	int numero;//Lleva la cuenta de bonus existentes

public:
	ListaCorazones();//Constructor sin argumentos
	virtual ~ListaCorazones();
	bool agregar(BonusCorazon* b);//Argumento la direccion del bonus
	void dibuja();
	//void mueve();
	void destruirContenido();
	void eliminar(int index);
	void eliminar(BonusCorazon* b);
	BonusCorazon* colision(hombre& h);

	BonusCorazon* operator [](int i);
	int getNumero() { return numero; }
};
