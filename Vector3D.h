#pragma once
#include<math.h>
class Vector3D {
public:
	Vector3D(float x3 = 0, float y3 = 0,float z3=0);
	virtual ~Vector3D();
	//Mñetodos
	void set(float, float, float);
	float operator*(Vector3D);
	Vector3D operator*(float);
	Vector3D operator+(Vector3D);
	Vector3D operator-(Vector3D);
	float modulo();
	Vector3D unitario();
	void Pvect(Vector3D i, Vector3D j);//Asigna al vector qeu llama la función el valor del producto vectorial de los otros dos
	//Atributos
	float x;
	float y;
	float z;
	//Agregar operaciones
};
