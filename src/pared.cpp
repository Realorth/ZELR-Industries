#include "pared.h"
#include "freeglut.h"
#include "vector2D.h"
#include"ETSIDI.h"
pared::pared():color(0,0,200)
{	
}
pared::~pared()
{}

void pared::dibuja()
{
	// TODO: Agregar aquí el código de implementación.
	glDisable(GL_LIGHTING);
	glColor3ub(color.r, color.g, color.b);
	glBegin(GL_POLYGON);
	glVertex3d(limite1.x, limite1.y, ancho);
	glVertex3d(limite2.x, limite2.y, ancho);
    glVertex3d(limite2.x, limite2.y, -ancho);
	glVertex3d(limite1.x, limite1.y, -ancho);
	glEnd();
	glEnable(GL_LIGHTING);

}
void pared::SetColor(Byte r, Byte v, Byte b) {
	color.set(r, v, b);
}
void pared::SetPos(float x1, float y1, float x2, float y2)
{
	limite1.x = x1;
	limite1.y = y1;
	limite2.x = x2;
	limite2.y = y2;
}
//Calculo de distancia de una pared a un punto, adicionalmente
//se modifica el valor de un vector direccion opcional que contendrá
//el vector unitario saliente que indica la direccion de la
//recta más corta entre el punto y la pared.
float pared::distancia(vector2D punto, vector2D* direccion)
{
	vector2D u = (punto - limite1);
	vector2D v = (limite2 - limite1).unitario();
	float longitud = (limite1 - limite2).modulo();
	vector2D dir;
	float valor = u * v;
	float distancia = 0;

	if (valor < 0)
		dir = u;
	else if (valor > longitud)
		dir = (punto - limite2);
	else
		dir = u - v * valor;

	distancia = dir.modulo();

	if (direccion != 0) //si nos dan un vector…
		*direccion = dir.unitario();
	return distancia;
}

float pared::Distancia(vector2D p1, vector2D p2)
{	//Calcula la distancia entre dos puntos en el espacio 2D
	float delta_x = p1.x - p2.x;
	float delta_y = p1.y - p2.y;
	double norma = pow(delta_x, 2) + pow(delta_y, 2);
	return (float)sqrt(norma);
}
float pared::dist_pto_recta( vector2D c) {
	auto p1 = this->limite1;
	auto p2 = this->limite2;
	//Calcula primero la distancia entre la recta, que pasa por el segmento y un punto
	double numerador = (double)(p2.x - p1.x) * (c.y - p1.y) - (p2.y - p1.y) * (c.x - p1.x);
	double d = fabs(numerador) / ((double)Distancia(p1, p2));
	double u = ((c.y - p1.y) * (p2.y - p1.y) + (c.x - p1.x) * (p2.x - p1.x)) / powf(Distancia(p1, p2), 2);
	if (u >= 0 && u <= 1)
		return d;
	//Sí la solución se encuentra afuera del segmento se devuelve el valor mínimo
	float dist_p1_d = Distancia(p1, c);
	float dist_p2_d = Distancia(p2, c);
	return dist_p1_d <= dist_p1_d ? dist_p1_d : dist_p2_d;
}