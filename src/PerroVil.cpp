#include "PerroVil.h"

void PerroVil::gira()
{
	vector2D aux = GetVel();
	SetVel(0, 0);
	if (aux.x > 0)			SetPos(GetPos().x - 0.5f, 0);
	else if (aux.x < 0)		SetPos(GetPos().x + 0.5f, 0);
	SetVel(-aux.x, 0);
}

void PerroVil::ataca() {}
void PerroVil::reacciona() 
{
	aceleracion.x = 0.002 + aceleracion.x * 1.2;			//Empieza a patrullar cada vez más rápido
}
