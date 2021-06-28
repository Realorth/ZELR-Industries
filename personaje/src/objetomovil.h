#pragma once
#include "vector2D.h"

class objetomovil
{
public:
	objetomovil();
	~objetomovil();

	void mueve(float t);
	vector2D GetPos();
	void SetPos(float x, float y);
	void SetVel(float x, float y);
	void SetAcel(float x, float y);
	//void SetPos(vector2D pos);
	

protected:
	vector2D posicion;
	vector2D velocidad;
	vector2D aceleracion;

};

