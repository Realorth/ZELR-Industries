#include "bonus.h"
#include <stdlib.h>
#include "freeglut.h"
#include "ETSIDI.h"

bonus::bonus()
{
	lado = 0.5f;
	//aceleracion.y = -9.81f;


}
//bonus::bonus(float x, float y)
//{
//	posicion.x = x;
//	posicion.y = y;
//}
bonus::~bonus()
{}

// funcion principal de dibujo del bonus
void bonus::dibuja()
{
	// TODO: Agregar aquí el código de implementación.
	//glPushMatrix();
	//glTranslatef(posicion.x, posicion.y, 0);
	//glRotatef(30, 1, 1, 1);
	////glColor3f(rand() / (float)RAND_MAX, rand() / (float)RAND_MAX,
	//	//rand() / (float)RAND_MAX);//color aleatorio
	//glutSolidCube(lado);
	//glPopMatrix();


}

//void bonus::mueve(float t)
//{
	//posicion.x = posicion.x + velocidad.x * t + 0.5f * aceleracion.x * t * t;
	//posicion.y = posicion.y + velocidad.y * t + 0.5f * aceleracion.y * t * t;
	//velocidad.x = velocidad.x + aceleracion.x * t;
	//velocidad.y = velocidad.y + aceleracion.y * t;
	//posicion = posicion + velocidad * t + aceleracion * (0.5f * t * t);
	//velocidad = velocidad + aceleracion * t;

//}

