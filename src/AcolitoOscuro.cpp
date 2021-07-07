#include "AcolitoOscuro.h"

void AcolitoOscuro::gira()
{
	vector2D aux = GetVel();
	SetVel(0, 0);
	if (aux.x > 0)			SetPos(GetPos().x - 0.5f, 0);
	else if (aux.x < 0)		SetPos(GetPos().x + 0.5f, 0);
	SetVel(-aux.x, 0);
}
AcolitoOscuro::~AcolitoOscuro()
{
}
AcolitoOscuro::AcolitoOscuro(float x, float y) :
	Enemigos(x, y, "imagenes/Brujo2.png", 4)
{
	velocidad.x = 3.0f;
}

AcolitoOscuro::AcolitoOscuro(vector2D a) :
	Enemigos(a, "imagenes/Brujo2.png", 4)
{
	velocidad.x = 3.0f;
}

AcolitoOscuro::AcolitoOscuro() :
	Enemigos(0, 0, "imagenes/Brujo2.png", 4)
{
	velocidad.x = 3.0f;
}
