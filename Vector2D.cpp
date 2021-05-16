#include "Vector2D.h"


Vector2D::Vector2D(float xv , float yv ) {
	x = xv;
	y = yv;
}

Vector2D::~Vector2D() {

}
float Vector2D::modulo()
{
	return (float)sqrt(x * x + y * y);
}
float Vector2D::argumento()
{
	return (float)atan2(y, x);
}

Vector2D Vector2D::unitario()
{
	Vector2D retorno(x, y);
	float mod = modulo();
	if (mod > 0.00001)
	{
		retorno.x /= mod;
		retorno.y /= mod;
	}
	return retorno;
}

Vector2D Vector2D::operator+ (Vector2D op)
{
	Vector2D resultado;
	resultado.x = x + op.x;
	resultado.y = y + op.y;
	return resultado;
}

Vector2D Vector2D::operator+ (float real)
{
	Vector2D resultado;
	resultado.x = x + real;
	resultado.y = y;
	return resultado;

}

Vector2D Vector2D::operator-(Vector2D op)
{
	Vector2D resultado;
	resultado.x = x - op.x;
	resultado.y = y - op.y;
	return resultado;

}

Vector2D Vector2D::operator-(float op)
{
	Vector2D resultado;
	resultado.x = (x - op);
	resultado.y = y;
	return resultado;
}

float Vector2D::operator*(Vector2D op)
{
	return (float) ((x * (op.x)) + (y * (op.y)));
}

Vector2D Vector2D::operator*(float p)
{
	Vector2D resultado;
	resultado.x =( p * x);
	resultado.y = (p * y);
	return resultado;
}