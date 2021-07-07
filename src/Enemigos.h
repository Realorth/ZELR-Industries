#pragma once
#include"objetomovil.h"
#include"ETSIDI.h"
#include<string>
class Enemigos: public objetomovil
{
protected:
	ETSIDI::SpriteSequence sprite_enemigo;
	int tamano_secuencia = 0;
	vector2D tamano;
public:
	Enemigos();
	Enemigos(float x, float y,const char*,int tamano_secuencia);
	Enemigos(vector2D a, std::string, int tamano_secuencia);
	Enemigos(vector2D a, const char* b, int tamano_secuencia);

	virtual ~Enemigos();
	virtual void dibuja();
	virtual bool ataca(); 

	
};

