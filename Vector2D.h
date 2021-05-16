#pragma once
#include<math.h>
class Vector2D
{
public:
	Vector2D(float xv = 0.0f, float yv = 0.0f); 
	virtual ~Vector2D();
	//Sobrecarga de operadores
	Vector2D operator+ (Vector2D op);
	Vector2D operator+ (float real);
	float operator*(Vector2D op);
	Vector2D operator*(float p);
	Vector2D operator-(Vector2D op);
	Vector2D operator-(float op);
		
	// (1)constructor
	float modulo();
	// (2) modulo del vector
	float argumento();
	// (3) argumento del vector
	Vector2D unitario();
	// (4) devuelve un vector unitario

	float x;
	float y;
};
