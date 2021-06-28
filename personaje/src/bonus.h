#pragma once
#include "vector2D.h"
#include "objetomovil.h"
#include "ETSIDI.h"

class bonus : public objetomovil
{
	
public:
	bonus();
	/*bonus(float x, float y);*/
	virtual ~bonus();


	// funcion principal de dibujo del bonus
	virtual void dibuja();
	//void mueve(float t);


protected:
	//vector2D posicion;
	float lado;

	//vector2D velocidad;
	//vector2D aceleracion;
};