#include "disparo.h"
#include "objetomovil.h"
#include "vector2D.h"
#include "ETSIDI.h"

class disparoespecial : public disparo
{
protected:
	ETSIDI::Sprite AtaqueBFuego;
public:
	disparoespecial();
	disparoespecial(float, float);
	disparoespecial(vector2D);
	disparoespecial(vector2D,vector2D);
	~disparoespecial();
	void dibuja();
	
};
