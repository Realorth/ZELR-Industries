#pragma once
#include "bonus.h"
#include "Interaccion.h"
#include "hombre.h"
//#include "ListaBonus.h"

#define MAX_ARMADURAS 20
class ListaArmaduras
{
private:
	BonusArmadura* lista[MAX_ARMADURAS];//vector de punteros a objetos tipo bonus
	int numero;//Lleva la cuenta de bonus existentes

public:
	ListaArmaduras();//Constructor sin argumentos
	virtual ~ListaArmaduras();
	bool agregar(BonusArmadura* b);//Argumento la direccion del bonus
	void dibuja();
	//void mueve();
	void destruirContenido();
	void eliminar(int index);
	void eliminar(BonusArmadura* b);
	BonusArmadura* colision(hombre& h);

	BonusArmadura* operator [](int i);
	int getNumero() { return numero; }

};

