#pragma once
#include "vector2D.h"
#include "caja.h"
#include "ETSIDI.h" 
#include"objetomovil.h"
using ETSIDI::SpriteSequence;

class hombre : public objetomovil
{
public:
	hombre();
	virtual ~hombre();

	void dibuja();
	void tecla(unsigned char key);
	void SetColor(unsigned char r, unsigned char v, unsigned char b);
	void SetAltura(float a);
	float GetAltura();
	void Setvida(int v);
	void Setataque(int a);
	int Getvida() {return vida;}
	int GetAtaque() { return ataque; }
	int GetArmadura() { return armadura; }
	void AumentaVida() { vida += 1; }
	void AumentaAtaque() { ataque += 1; }
	void AumentaArmadura() { armadura += 1; }
	friend class Interaccion;


protected:
	SpriteSequence sprite{ "imagenes/gunboy.png", 3 };
	float altura;
	unsigned char rojo;
	unsigned char verde;
	unsigned char azul;
	int vida=5;
	int ataque=1;
	int armadura=0;

};

