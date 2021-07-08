#pragma once
#include "bonus.h"
#include "Interaccion.h"
#include "hombre.h"
#define MAX_BONUS 200


class ListaBonus
{
private:
	bonus* lista[MAX_BONUS];//vector de punteros a objetos tipo bonus
	int numero;//Lleva la cuenta de bonus 

public:
	ListaBonus();//Constructor sin argumentos
	virtual ~ListaBonus();
	bool agregar(bonus* b);//Argumento la direccion del bonus
	void dibuja();
	//void mueve();
	void destruirContenido();
	void eliminar(int index);
	void eliminar(bonus* b);
	bonus* colision(hombre& h);
;
	bonus* operator [](int i);
	int getNumero() { return numero; }


};



