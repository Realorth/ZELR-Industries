#include "Enemigos.h"
#include"freeglut.h"

Enemigos::Enemigos() :objetomovil(),tamano_secuencia(0) ,sprite_enemigo{" ",0}
{
	sprite_enemigo.setPos(posicion.x, posicion.y);
	sprite_enemigo.setSize(3, 2.5);
	sprite_enemigo.setCenter(posicion.x, posicion.y);
	aceleracion.y = -9.81f;
}


Enemigos::Enemigos(vector2D a, std::string b, int n_secuencia): 
	objetomovil(a), tamano_secuencia(tamano_secuencia), sprite_enemigo(b.c_str(), n_secuencia)
{
	sprite_enemigo.setPos(posicion.x, posicion.y);
	sprite_enemigo.setSize(3, 2.5);
	sprite_enemigo.setCenter(posicion.x, posicion.y);
	aceleracion.y = -9.81f;
}

Enemigos::Enemigos(vector2D pos, const char* b, int n_secuencias, vector2D tam):
	objetomovil(pos), tamano(tam), sprite_enemigo(b, n_secuencias)
{
}




Enemigos::Enemigos(float x, float y, const char* b, int n_secuencias, float wide, float height):
	objetomovil(x,y),tamano(wide,height),sprite_enemigo(b,n_secuencias)
{
	posicion.set(x, y);
	sprite_enemigo.setPos(posicion.x, posicion.y);
	sprite_enemigo.setSize(tamano.x, tamano.y);
	sprite_enemigo.setCenter(posicion.x, posicion.y);
	aceleracion.y = -9.81f;
}

Enemigos::~Enemigos()
{
	
}

void Enemigos::dibuja()
{
	// TODO: Agregar aquí el código de implementación.
	glPushMatrix();
	glTranslatef(posicion.x, posicion.y, 0);
	sprite_enemigo.setCenter(tamano.x/2, tamano.y/5);
	sprite_enemigo.setSize(3.0f,3.0f);
	//glColor3f(1.0f, 0.0f, 0.0f);
	//glutSolidSphere(1, 20, 20);
	//gestion de direccion y animacion 
	if (velocidad.x > 0.01)sprite_enemigo.flip(false, false);
	if (velocidad.x < -0.01)sprite_enemigo.flip(true, false);
	if ((velocidad.x < 0.01) && (velocidad.x > -0.01))
		sprite_enemigo.setState(0);
	else if (sprite_enemigo.getState() == 0)
		sprite_enemigo.setState(1, false);
	sprite_enemigo.draw();
	glPopMatrix();
}

void Enemigos::ataca()
{

	return;
}
