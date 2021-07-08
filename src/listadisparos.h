#pragma once
//#include "disparo.h"
#include"pared.h"
#include "disparoespecial.h"
#define MAX_DISPAROS 10

class listadisparos
{
public:

	listadisparos();
	virtual ~listadisparos();

	bool agregar(disparo* d);// Devuelve true sí se ha podido añadir un nuevo disparo
	void destruirContenido();
	void mueve(float t);
	void dibuja();
	void colision(pared& p);

	//void colision(caja& c);
	void eliminar(int index);
	void eliminar(disparo* d);
	int getNumero() { return numero; }
	disparo* operator[](int i);
	disparo** GetLista() { return lista; }
private:
	disparo* lista[MAX_DISPAROS];
	int numero;
	friend class Interaccion;
};



