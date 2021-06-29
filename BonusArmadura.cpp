#include "BonusArmadura.h"
#include "ETSIDI.h"
#include <iostream>

BonusArmadura:: BonusArmadura() :bonus(), S_arm("imagenes/Armadura.png")
{
	S_arm.setCenter(posicion.x,posicion.y);
	S_arm.setSize(1.0f,1.0f);
}
BonusArmadura::BonusArmadura(float x, float y):bonus(x,y),S_arm("imagenes/Armadura.png")
{	// En el constructor de bonus se inicializa la posicion
	S_arm.setCenter(posicion.x, posicion.y);
	S_arm.setSize(1.0f, 1.0f);
}

BonusArmadura::BonusArmadura(vector2D A) :bonus(A), S_arm("imagenes/Armadura.png")
{	// En el constructor de bonus se inicializa la posicion
	S_arm.setCenter(posicion.x, posicion.y);
	S_arm.setSize(1.0f, 1.0f);
}
BonusArmadura::~BonusArmadura()
{}
void BonusArmadura::dibuja() {

	glPushMatrix();
	glTranslatef(posicion.x, posicion.y, 0);
	//std::cout << posicion.x << "---" << posicion.y << std::endl;
	glDepthMask(GL_FALSE);
	glEnable(GL_BLEND);
	glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
	glColor4f(1.0, 1.0, 1.0, 1.0);
	S_arm.draw();
	glDisable(GL_BLEND);
	glDepthMask(GL_TRUE);
	glTranslatef(-posicion.x, -posicion.y, 0);
	glPopMatrix();
	

}
