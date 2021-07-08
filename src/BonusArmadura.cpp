#include "BonusArmadura.h"
#include "ETSIDI.h"
#include <iostream>

BonusArmadura:: BonusArmadura() :bonus()
{
	textura = "imagenes/Armadura.png";
	SetNombre("Armadura");

}
BonusArmadura::BonusArmadura(float x, float y):bonus(x,y, "imagenes/Armadura.png")
{	// En el constructor de bonus se inicializa la posicion
	SetNombre("Armadura");
}

BonusArmadura::BonusArmadura(vector2D A) :bonus(A, "imagenes/Armadura.png")
{	// En el constructor de bonus se inicializa la posicion
	SetNombre("Armadura");
}
BonusArmadura::~BonusArmadura()
{}
