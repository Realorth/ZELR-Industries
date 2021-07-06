#pragma once
#include "vector2D.h"
#include "objetomovil.h"

class esfera: public objetomovil
{
public:
	
	esfera();
	//esfera(float rad, float x, float y, float vx, float vy);
	esfera(float rad, float x = 0.0f, float y = 0.0f,float vx = 0.0f, float vy = 0.0f);

	virtual ~ esfera();
    void dibuja();
	//void mueve(float t);
	void SetColor(unsigned char, unsigned char, unsigned char);
	void SetRadio(float);
	//void SetPos(float, float);
	//void SetVel(float vx, float vy);
	//vector2D GetPos();

	friend class Interaccion;
	

protected:
	unsigned char rojo;
	unsigned char verde;
	unsigned char azul;
	float radio;
	//vector2D posicion;
	//vector2D velocidad;
	//vector2D aceleracion;
	

};

