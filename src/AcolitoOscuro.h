#pragma once
#include "Enemigos.h"
#include "Interaccion.h"
class AcolitoOscuro :public Enemigos
{
	SpriteSequence spriteacolito{ "imagenes/brujo3.png", 4 };
	int sentido = -1;
public:
	
	AcolitoOscuro();

	AcolitoOscuro(vector2D pos, vector2D tam, int r, int hp, int armor, int atk, float vatk)	                     //---------------
		:Enemigos(pos, tam, r, hp, armor, atk, vatk, "imagenes/brujo3.png", 4) {}
	AcolitoOscuro(vector2D pos) :Enemigos(pos, (3, 3), 25, 2, 0, 2, 85, "imagenes/brujo3.png", 4) {}      //valores por defecto de acólito cualquiera




	int GetSentido() { return sentido; }
	void SetSentido(int s) { sentido = s; }
	void ataca();
	
	~AcolitoOscuro();
};

