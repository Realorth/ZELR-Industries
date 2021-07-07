#include "BonusCorazon.h"
#include "ETSIDI.h"

BonusCorazon::BonusCorazon():bonus()
{
	textura = "imagenes/Heart.png";

}

BonusCorazon::BonusCorazon(float x, float y):bonus(x,y,"imagenes/Heart.png")
{	

}
BonusCorazon::BonusCorazon(vector2D a):bonus(a,"imagenes/Heart.png")
{	

}
BonusCorazon::~BonusCorazon()
{}




