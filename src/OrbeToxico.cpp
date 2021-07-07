#pragma once
#include "OrbeToxico.h"
#include <math.h>
#include "ColorRGB.h"

OrbeToxico::OrbeToxico():esfera()
{
	radio = 1.5f;
	rojo = 191;
	verde = 255;
	azul = 0;
	aceleracion.y = -9.8;
}
OrbeToxico::OrbeToxico(float rad, float x, float y, float vx, float vy):esfera(rad, x, y, vx, vy)
{
	rojo = 191;
	verde = 255;
	azul = 0; 
	//color.set(191, 255, 0);  //por qué no funciona?
	
	aceleracion.y = -9.8;
}
OrbeToxico::~OrbeToxico()
{}

void OrbeToxico::dibuja()
{
	float aux = radio * 1.5 * sqrt(2) / 2;
	// TODO: Agregar aquí el código de implementación.
	glColor3ub(rojo, verde, azul);
	glTranslatef(posicion.x, posicion.y, 0);
	glutSolidSphere(radio, 20, 20);
	//ahora las 8 esferas pequeñitas
	glTranslatef(radio*1.5, 0, 0);
	glutSolidSphere(radio/4, 20, 20);			//1
	glTranslatef(-radio * 1.5, 0, 0);
	glTranslatef(aux, aux, 0);
	glutSolidSphere(radio / 4, 20, 20);			//2
	glTranslatef(-aux, -aux, 0);
	glTranslatef(0, radio * 1.5, 0);
	glutSolidSphere(radio / 4, 20, 20);			//3
	glTranslatef(0, -radio * 1.5, 0);
	glTranslatef(-aux, aux, 0);
	glutSolidSphere(radio / 4, 20, 20);			//4
	glTranslatef(aux, -aux, 0);
	glTranslatef(-radio * 1.5, 0, 0);
	glutSolidSphere(radio / 4, 20, 20);			//5
	glTranslatef(radio * 1.5, 0, 0);
	glTranslatef(-aux, -aux, 0);
	glutSolidSphere(radio / 4, 20, 20);			//6
	glTranslatef(aux, aux, 0);
	glTranslatef(0, -radio * 1.5, 0);
	glutSolidSphere(radio / 4, 20, 20);			//7
	glTranslatef(0, radio * 1.5, 0);
	glTranslatef(aux, -aux, 0);
	glutSolidSphere(radio / 4, 20, 20);			//8
	glTranslatef(-aux, aux, 0);
	glTranslatef(-posicion.x, -posicion.y, 0);//se lleva la referencia al origen
	//ahora los segmentos de unión entre centros
	glBegin(GL_LINES);											//1
	glVertex2f(posicion.x, posicion.y);
	glVertex2f(posicion.x + radio * 1.5, posicion.y);
	glEnd();
	glBegin(GL_LINES);											//2
	glVertex2f(posicion.x, posicion.y);
	glVertex2f(posicion.x + aux, posicion.y + aux);
	glEnd();
	glBegin(GL_LINES);											//3
	glVertex2f(posicion.x, posicion.y);
	glVertex2f(posicion.x, posicion.y + radio * 1.5);
	glEnd();
	glBegin(GL_LINES);											//4
	glVertex2f(posicion.x, posicion.y);
	glVertex2f(posicion.x - aux, posicion.y + aux);
	glEnd();
	glBegin(GL_LINES);											//5
	glVertex2f(posicion.x, posicion.y);
	glVertex2f(posicion.x - radio * 1.5, posicion.y);
	glEnd();
	glBegin(GL_LINES);											//6
	glVertex2f(posicion.x, posicion.y);
	glVertex2f(posicion.x - aux, posicion.y - aux);
	glEnd();
	glBegin(GL_LINES);											//7
	glVertex2f(posicion.x, posicion.y);
	glVertex2f(posicion.x, posicion.y - radio * 1.5);
	glEnd();
	glBegin(GL_LINES);											//8
	glVertex2f(posicion.x, posicion.y);
	glVertex2f(posicion.x - aux, posicion.y - aux);
	glEnd();


	//glFlush();
}
