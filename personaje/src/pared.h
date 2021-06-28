#pragma once
#include "vector2D.h"

class pared
{
public:
	pared();
	virtual ~pared();
	void dibuja();
	void SetColor(unsigned char, unsigned char, unsigned char);
	void SetPos(float x1, float y1, float x2, float y2);
	float distancia(vector2D punto, vector2D* direccion = 0);

	friend class Interaccion;
	friend class listadisparos;

private:

	unsigned char rojo;
	unsigned char verde;
	unsigned char azul;
    vector2D limite1;
	vector2D limite2;
};

