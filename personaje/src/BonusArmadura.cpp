#include "BonusArmadura.h"
#include "ETSIDI.h"
#include <iostream>

BonusArmadura:: BonusArmadura() : S_arm("imagenes/Armadura.png")
{
	S_arm.setCenter(posicion.x,posicion.y);
	S_arm.setSize(1.0f,1.0f);
}

void BonusArmadura::dibuja() {


	//glDepthMask(GL_FALSE);//No sé para qué sirve
	//glEnable(GL_BLEND);
	//glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
	//// Empieza la textura
	//glEnable(GL_TEXTURE_2D);
	//glBindTexture(GL_TEXTURE_2D, ETSIDI::getTexture("imagenes/Armadura.png").id);
	//glDisable(GL_LIGHTING);
	////Se dibuja el polígono
	//glBegin(GL_POLYGON);
	//glColor4f(1.0, 1.0, 1.0, 1.0);
	//glTexCoord2d(0, 0);	glVertex2f(posicion.x, posicion.y + 1);
	//glTexCoord2d(1, 0);	glVertex2f((posicion.x + 1), posicion.y + 1);
	//glTexCoord2d(1, 1);	glVertex2f((posicion.x + 1), posicion.y);
	//glTexCoord2d(0, 1);	glVertex2f(posicion.x, posicion.y);
	//glEnd();
	////
	//glDisable(GL_BLEND);
	//glDepthMask(GL_TRUE);
	//glEnable(GL_LIGHTING);
	//glDisable(GL_TEXTURE_2D);
	glPushMatrix();
	glTranslatef(posicion.x, posicion.y, 0);
	S_arm.draw();
	glPopMatrix();
	

}
