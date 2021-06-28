#include "esfera.h"
#include "freeglut.h"
#include <math.h>

esfera miesfera; //constructor por defecto sin argumentos
esfera miesfera1(8.0F); //nuevo constructor: radio 8
esfera miesfera2(3.0F, 2, 5);//nuevo constructor: radio 3 posición 2,5
esfera* aux = new esfera(5.0f); //creación dinámica con el nuevo 

esfera::esfera()
{
	radio = 0.1f;
	rojo = verde = 255;
	azul = 100; 
	aceleracion.y = -9.8;
}
esfera::esfera(float rad, float x, float y, float vx, float vy)
{
	radio = rad;
	posicion.x = x;
	posicion.y = y;
	velocidad.x = vx;
	velocidad.y = vy;
	rojo = verde = 255;
	azul = 100; //color distinto
	aceleracion.y = -9.8;
}
esfera::~esfera()
{}

void esfera::dibuja()
{
	// TODO: Agregar aquí el código de implementación.
	glColor3ub(rojo, verde, azul);
	glTranslatef(posicion.x, posicion.y, 0);
	glutSolidSphere(radio, 20, 20);
	glTranslatef(-posicion.x, -posicion.y, 0);
}
//void esfera::mueve(float t)
//{
	//posicion.x = posicion.x + velocidad.x * t + aceleracion.x * 0.5f * t * t;
	//posicion.y = posicion.y + velocidad.y * t + aceleracion.y * 0.5f * t * t;
	//velocidad.x = velocidad.x + aceleracion.x * t;
	//velocidad.y = velocidad.y + aceleracion.y * t;

	//posicion = posicion + velocidad * t + aceleracion * (0.5f * t * t);
	//velocidad = velocidad + aceleracion * t;

//}

void esfera::SetColor(unsigned char r, unsigned char v, unsigned char b) {
	rojo = r;
	verde = v;
	azul = b;
}
void esfera::SetRadio(float r) {
	radio = r;
}

//void esfera::SetPos(float ix, float iy) {
	//posicion.x = ix;
	//posicion.y = iy;
//}
//void esfera::SetVel(float vx, float vy)
//{
//	velocidad.x = vx;
//	velocidad.y = vy;
//}
//vector2D esfera::GetPos()
//{
//	return posicion;
//}

