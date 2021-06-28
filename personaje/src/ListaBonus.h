#pragma once
#include "bonus.h"
#include "Interaccion.h"
#include "hombre.h"
#define MAX_BONUS 20


class ListaBonus
{
private:
	bonus* lista[MAX_BONUS];//vector de punteros a objetos tipo bonus
	int numero;//Lleva la cuenta de bonus existentes

public:
	ListaBonus();//Constructor sin argumentos
	virtual ~ListaBonus();
	virtual bool agregar(bonus* b);//Argumento la direccion del bonus
	void dibuja();
	//void mueve();
	virtual void destruirContenido();
	void eliminar(int index);
	void eliminar(bonus* b);
	//bonus* colision(hombre& h);

	virtual bonus* operator [](int i);
	virtual int getNumero() /*{ return numero; }*/ = 0;


};
