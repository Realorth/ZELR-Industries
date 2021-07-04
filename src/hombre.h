#pragma once
#include "vector2D.h"
#include "caja.h"
#include "ETSIDI.h" 
#include"objetomovil.h"

using ETSIDI::SpriteSequence;

class hombre : public objetomovil
{
public:
	friend class Interaccion;

	hombre();
	virtual ~hombre();

	void dibuja();
	void tecla(unsigned char key);
	void SetColor(unsigned char r, unsigned char v, unsigned char b);
	void SetAltura(float a);
	float GetAltura();
	void Setvida(int v);
	void Setataque(int a);
	int Getvida() { return vida; }
	int GetAtaque() { return ataque; }
	int GetArmadura() { return armadura; }
	void AumentaVida() { vida += 1; }
	void AumentaAtaque() { ataque += 1; }
	void AumentaArmadura() { armadura += 1; }
	void mueve(float t) { objetomovil::mueve(t); 
	if (this->velocidad.y < -5) velocidad.y = -5;
	}
	


protected:
	SpriteSequence sprite{ "imagenes/gunboy.png", 3 };
	float altura;
	unsigned char rojo;
	unsigned char verde;
	unsigned char azul;
	int vida = 5;
	int ataque = 1;
	int armadura = 0;

};

