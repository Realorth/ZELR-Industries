#pragma once
#include "vector2D.h"

class objetomovil
{
public:
	objetomovil();
	objetomovil(float x, float y) :posicion(x, y),velocidad(0,0),aceleracion(0,0){}
	objetomovil(vector2D a):posicion(a),velocidad(0,0),aceleracion(0,0){}
	~objetomovil();

	void mueve(float t);
	vector2D& GetPos();
	void SetPos(float x, float y);
	void SetVel(float x, float y);
	void SetAcel(float x, float y);
	// Ahora sí se le pasa un vector2D
	void SetPos(vector2D a) { posicion = a; }
	void SetVel(vector2D a) { velocidad = a; }
	void SetAcel(vector2D a) { aceleracion = a; }
	// Ahora las de  obtener los valores
	vector2D GetVel() { return velocidad; }
	vector2D GetAcel() { return aceleracion; }
protected:
	vector2D posicion;
	vector2D velocidad;
	vector2D aceleracion;

};

