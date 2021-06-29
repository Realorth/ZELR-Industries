#include "BonusCorazon.h"
#include "ETSIDI.h"

BonusCorazon::BonusCorazon():S_Cor("imagenes/Heart.png"),bonus()
{
	S_Cor.setCenter(posicion.x, posicion.y);
	S_Cor.setSize(1.0f, 1.0f);
}

BonusCorazon::BonusCorazon(float x, float y):bonus(x,y),S_Cor("imagenes/Heart.png")
{
	S_Cor.setCenter(posicion.x, posicion.y);
	S_Cor.setSize(1.0f, 1.0f);
}
BonusCorazon::BonusCorazon(vector2D a):bonus(a), S_Cor("imagenes/Heart.png")
{
	S_Cor.setCenter(posicion.x, posicion.y);
	S_Cor.setSize(1.0f, 1.0f);
}
BonusCorazon::~BonusCorazon()
{}
void BonusCorazon::dibuja() {
	glPushMatrix();
	glTranslatef(posicion.x, posicion.y, 0);
	S_Cor.draw();
	glPopMatrix();

}

