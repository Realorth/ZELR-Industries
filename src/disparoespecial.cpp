#include "disparoespecial.h"
#include "freeglut.h"


disparoespecial::disparoespecial():disparo(),AtaqueBFuego("imagenes/AtaqueBolaFuego.png")
{
	aceleracion.x = 9.8;
	aceleracion.y = 0;
	AtaqueBFuego.setCenter(0.3f, 0.5f);
	AtaqueBFuego.setSize(2.5f, 2.5f);

}
disparoespecial::~disparoespecial()
{}

void disparoespecial::dibuja()
{
	glPushMatrix();
	glTranslatef(posicion.x, posicion.y + 0.5, 0);
	AtaqueBFuego.draw();
	glPopMatrix();
}
