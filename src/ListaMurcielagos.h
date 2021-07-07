#pragma once
#include "Interaccion.h"
#include "hombre.h"
#include "Murcielago.h"
#define MAX_MURCIELAGOS 10

class ListaMurcielagos:public Enemigos
{
private:
	Murcielago* lista[MAX_MURCIELAGOS];      //vector de punteros a objetos tipo Murcielago
	int numero;									//Lleva la cuenta de murcielagos existentes

public:

};