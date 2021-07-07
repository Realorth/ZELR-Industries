#include "Enemigos.h"


Enemigos::Enemigos() :objetomovil(),tamano_secuencia(0) ,sprite_enemigo{" ",0}
{
	sprite_enemigo.setSize(3, 2.5);
	sprite_enemigo.setCenter(posicion.x, posicion.y);
	aceleracion.y = -9.81f;
}

Enemigos::Enemigos(float x, float y, const char* b, int tamano_secuencia):objetomovil(x,y), tamano_secuencia(tamano_secuencia), sprite_enemigo{ b,tamano_secuencia }
{
	sprite_enemigo.setSize(3, 2.5);
	sprite_enemigo.setCenter(posicion.x, posicion.y);
	aceleracion.y = -9.81f;
}

Enemigos::Enemigos(vector2D a, std::string b, int tamano_secuencia): objetomovil(a), tamano_secuencia(tamano_secuencia), sprite_enemigo{ b.c_str(),tamano_secuencia }
{
	sprite_enemigo.setSize(2.5, 2.5);
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
	glColor3f(1.0f, 0.0f, 0.0f);
	//glutSolidSphere(altura, 20, 20);
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

bool Enemigos::ataca()
{

    return false;
}
