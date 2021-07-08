#include "coin.h"



coin::coin() :bonus()
{
	textura ="imagenes/coin.png" ;
	SetNombre("Moneda");
}

coin::coin(float x, float y) :bonus(x,y,"imagenes/coin.png")
{
	SetNombre("Moneda");
}

coin::coin(vector2D a):bonus(a,"imagenes/coin.png")
{
	SetNombre("Moneda");
}

