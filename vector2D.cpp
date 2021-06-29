#include "vector2D.h"
#include <math.h>

vector2D::vector2D(float xv, float yv)
{
	x = xv;
	y = yv;
}
vector2D::~vector2D()
{
}
float vector2D::modulo()
{
	return (float)sqrt((double)x * x + (double)y * y);
}
float vector2D::argumento()
{
	return (float)atan2(y, x);
}
vector2D vector2D::unitario()
{
	vector2D retorno(x, y);
	float mod = modulo();
	if (mod > 0.00001)
	{
		retorno.x /= mod;
		retorno.y /= mod;
	}
	return retorno;
}
vector2D vector2D::operator - (vector2D v)
{
	vector2D res;
	res.x = x - v.x;
	res.y = y - v.y;
	return res;
}
vector2D vector2D::operator + (vector2D v)
{
	vector2D res;
	res.x = x + v.x;
	res.y = y + v.y;
	return res;
}
float vector2D:: operator *(vector2D pe)
{
	return  (x * pe.x + y * pe.y);
}
vector2D vector2D:: operator *(float e)
{
	vector2D res;
	res.x = x * e;
	res.y = y * e;
	return res;
}

vector2D vector2D::operator+(float a)
{
	vector2D res(*this);
	res.x += a;
	return res;
}

vector2D vector2D::operator-(float a)
{
	vector2D res(*this);
	res.x -= a;
	return res;
}
