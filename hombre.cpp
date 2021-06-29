#include "hombre.h"
#include "freeglut.h"
#include <math.h>

hombre::hombre()
{
	sprite.setCenter(1, 0);
	sprite.setSize(2, 2);
	aceleracion.x = aceleracion.y = 0;
}

hombre::~hombre()
{}

void hombre::dibuja()
{
	// TODO: Agregar aquí el código de implementación.
	glPushMatrix();
	glTranslatef(posicion.x, posicion.y, 0);
	glColor3f(1.0f, 0.0f, 0.0f);
	//glutSolidSphere(altura, 20, 20);
	//gestion de direccion y animacion 
	if (velocidad.x > 0.01)sprite.flip(false, false);
	if (velocidad.x < -0.01)sprite.flip(true, false);
	if ((velocidad.x < 0.01) && (velocidad.x > -0.01))
		sprite.setState(0);
	else if (sprite.getState() == 0)
		sprite.setState(1, false);
	sprite.draw();
	glPopMatrix();
}

void hombre::SetColor(unsigned char r, unsigned char v, unsigned char b) {
	rojo = r;
	verde = v;
	azul = b;
}
void hombre::SetAltura(float a) {
	altura = a;
}

float hombre::GetAltura()
{
	return altura;
}

void hombre::tecla(unsigned char key)
{
	switch (key)
	{
	case 'A': // PARA IZQUIERDA
	case 'a':
	case GLUT_KEY_LEFT:
		posicion.x -= 0.5f;

		break;

	case 'D':// PARA DERECHA
	//case 'd':
	case GLUT_KEY_RIGHT:
		posicion.x += 0.5f;

		break;

	case 'W': // PARA SALTAR
	case 'w':
	case GLUT_KEY_UP:
		velocidad.y = 10;
		aceleracion.y = -9.81f;

		break;

	case 'S': // PARA AGACHAR
	case 's':
	case GLUT_KEY_DOWN:

		break;

	case 'J': // PARA ATAQUE
	case 'j':

		break;

	case 'K': // PARA ATAQUE ESPECIAL
	case 'k':

		break;
	}

}

void hombre::Setvida(int v)
{
	vida = v;
}
void hombre::Setataque(int a)
{
	ataque = a;
}