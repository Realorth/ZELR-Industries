#include "BonusCorazon.h"
#include "ETSIDI.h"

BonusCorazon::BonusCorazon():bonus()
{
	textura = "imagenes/Heart.png";
	SetNombre("Corazon");
}

BonusCorazon::BonusCorazon(float x, float y):bonus(x,y,"imagenes/Heart.png")
{	
	SetNombre("Corazon");
}
BonusCorazon::BonusCorazon(vector2D a):bonus(a,"imagenes/Heart.png")
{	
	SetNombre("Corazon");
}
BonusCorazon::~BonusCorazon()
{}




