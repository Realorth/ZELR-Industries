#pragma once
class Vector
{
public:	
	//Constructor y destructor
	Vector(){}
	virtual ~Vector() {}
	//Función set, para dar  un valor a los vectores
	virtual void set(float, float, float) = 0;
	
	virtual Vector unitario() = 0;
	virtual float modulo()=0; // (2) modulo del vector
	virtual float argumento()=0; // (3) argumento del vector
	virtual Vector operator- (Vector)=0; // (5) resta de vectores
	virtual Vector operator- (float) = 0;
	virtual Vector operator+(float) = 0;
	virtual	Vector operator + (Vector)=0; // (6) suma de vectores
	virtual float operator *(Vector pe)=0; // (7) producto escalar
	virtual Vector operator *(float e)=0; // (8) producto por un escalar 
};
