#pragma once
#include "vector2D.h"
#include "objetomovil.h"
#include "ETSIDI.h"

class bonus : public objetomovil
{
	
public:
	bonus();
	bonus(float x , float y,float lado=0.5f):objetomovil(x,y),lado(lado){}
	bonus(vector2D a, float lado=0.5f) :objetomovil(a), lado(lado) {}
	virtual ~bonus();
	// funcion principal de dibujo del bonus
	virtual void dibuja();
	void SetPos(float x, float y) { posicion.x = x; posicion.y = y; }
	void SetPos(vector2D a) { posicion = a; }


protected:
	//vector2D posicion;
	float lado;

};