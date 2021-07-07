#include "disparoespecial.h"
#include "freeglut.h"


disparoespecial::disparoespecial():disparo(),AtaqueBFuego("imagenes/AtaqueBolaFuego.png")
{
	aceleracion.x = 9.8;
	aceleracion.y = 0;
	AtaqueBFuego.setCenter(posicion.x, posicion.y);
	AtaqueBFuego.setPos(posicion.x, posicion.y);
	AtaqueBFuego.setSize(2.5f, 2.5f);
	

}
disparoespecial::disparoespecial(float x, float y) :disparo(x,y), AtaqueBFuego("imagenes/AtaqueBolaFuego.png")
{
	// En el constructor de bonus se inicializa la posicion
	AtaqueBFuego.setCenter(posicion.x, posicion.y);
	AtaqueBFuego.setPos(posicion.x, posicion.y);
	AtaqueBFuego.setSize(2.5f, 2.5f);
}
disparoespecial::disparoespecial(vector2D a) :disparo(a), AtaqueBFuego("imagenes/AtaqueBolaFuego.png")
{
	// En el constructor de bonus se inicializa la posicion
	AtaqueBFuego.setCenter(posicion.x, posicion.y);
	AtaqueBFuego.setPos(posicion.x, posicion.y);
	AtaqueBFuego.setSize(2.5f, 2.5f);
}
disparoespecial::disparoespecial(vector2D a, vector2D origen):disparo(a,origen), AtaqueBFuego("imagenes/AtaqueBolaFuego.png")
{
	// En el constructor de bonus se inicializa la posicion
	AtaqueBFuego.setCenter(posicion.x, posicion.y);
	AtaqueBFuego.setPos(posicion.x, posicion.y);
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
