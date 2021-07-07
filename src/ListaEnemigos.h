#pragma once
#include "Enemigos.h"
#include "Interaccion.h"
#include "hombre.h"
#define MAX_ENEMIGOS 100

class ListaEnemigos
{
private:
	Enemigos* lista[MAX_ENEMIGOS];					//vector de punteros a objetos tipo enemigo
	int numero;//Lleva la cuenta de enemigos 

public:
	ListaEnemigos();//Constructor sin argumentos
	virtual ~ListaEnemigos();
	bool agregar(Enemigos* e);//Argumento la direccion del enemigo
	void dibuja();
	void mueve();																	//ojo a este
	void destruirContenido();
	void eliminar(int index);
	void eliminar(Enemigos* e);
	Enemigos* colision(hombre& h);
	Enemigos* operator [](int i);
	int getNumero() { return numero; }


};