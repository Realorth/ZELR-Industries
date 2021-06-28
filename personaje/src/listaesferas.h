#pragma once
#include "esfera.h"
#include "Interaccion.h"

#define MAX_ESFERAS 100

class listaesferas
{
	public:
		listaesferas();
		virtual ~listaesferas();
        bool agregar(esfera* e);
		void dibuja();
		void mueve(float t);
		void rebote(caja caja);
		void rebote(pared p);
		void rebote();
		void destruirContenido();
		void agregar();
		void eliminar(int index);
		void eliminar(esfera* e);
		esfera* colision(hombre& h);
		esfera* operator [](int i);
		int getNumero() { return numero; }

	
	private:
		esfera* lista[MAX_ESFERAS];
		int numero;
		

};

