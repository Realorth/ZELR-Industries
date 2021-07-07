#pragma once
#include "Enemigos.h"
#include "hombre.h"

class Murcielago:public Enemigos
{
	
public:
	Murcielago();

	Murcielago(vector2D pos, vector2D tam, int r, int hp, int armor, int atk, float vatk)	                     //---------------
		:Enemigos(pos, tam, r, hp, armor, atk, vatk, "imagenes/Murcielago_derecha.png", 3) {}

	Murcielago(vector2D pos) :Enemigos(pos, (1.0, 1.0), 15, 1000, 0, 3, 0, "imagenes/Murcielago_derecha.png", 3) {}

	void vuela();

	void mueve( hombre& h); //persigue
	
	void ataca() {}
	~Murcielago() {}
};

