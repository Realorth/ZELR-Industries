#pragma once
#include "ListaEnemigos.h"
#include "AcolitoOscuro.h"
#define MAX_ACOLITOS 15
class ListaAcolitos:public ListaEnemigos
{
	AcolitoOscuro* lista[MAX_ACOLITOS];					//vector de punteros a objetos tipo enemigo
	int numero;
public:
	Enemigos* setsentido(hombre& h);
};

