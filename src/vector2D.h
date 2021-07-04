#pragma once

class vector2D
{
public:
	//vector2D();
    virtual ~vector2D();
	float x;
	float y;

	//friend class Interaccion;
	//friend class vector2D;//Absurdo

//private:

	vector2D(float xv = 0.0f, float yv = 0.0f); // (1)constructor
	float modulo(); // (2) modulo del vector
	float argumento(); // (3) argumento del vector
	vector2D unitario(); // (4) devuelve un vector unitario
	vector2D operator - (vector2D); // (5) resta de vectores
	vector2D operator + (vector2D); // (6) suma de vectores
	float operator *(vector2D pe); // (7) producto escalar
	vector2D operator *(float e); // (8) producto por un escalar 
	vector2D operator+(float a);
	vector2D operator-(float a);
	void set(float x, float y) { this->x = x; this->y = y; }
};
