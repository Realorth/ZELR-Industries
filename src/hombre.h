#pragma once
#include "vector2D.h"

#include "ETSIDI.h" 
#include"objetomovil.h"
#include"ColorRGB.h"
using ETSIDI::SpriteSequence;

class hombre : public objetomovil
{
public:
	friend class Interaccion;

	hombre();
	virtual ~hombre();

	virtual void dibuja();
	//void tecla(unsigned char key);
	void SetColor(Byte r, Byte g, Byte b) { color.set(r, g, b); }
	void SetAltura(float a);
	float GetAltura();
	void Setvida(int v);
	void Setataque(int a);

	void SetArmadura(int a) { armadura = a; }
	int Getvida() { return vida; }
	int GetAtaque() { return ataque; }
	int GetArmadura() { return armadura; }
	int GetAtaqueEs() { return ataqueEspecial; }
	void AumentaVida(int i = 1) { vida += i; }
	void DisminuyeVida(int i = 1) { vida -= i; }
	void AumentaAtaque(int i = 1) { ataque += i; }
	void DisminuyeAtaque(int i = 1) { ataque -= i; }
	void AumentaArmadura(int i = 1) { armadura += i; }
	void DisminuyeArmadura(int i = 1) { armadura -= i; }
	void AumentarAtaqueEs(int i=1) { ataqueEspecial += i; }
	void DisminuirAtaqueEs(int i=1) { ataqueEspecial -= i; }
	void mueve(float t) { objetomovil::mueve(t); 
	if (this->velocidad.y < -5) velocidad.y = -5;
	}
	


protected:
	//SpriteSequence sprite{ "imagenes/gunboy.png", 3 };
	float altura;
	ColorRGB color;

	int vida = 5;
	int ataque = 1;
	int armadura = 0;
	int ataqueEspecial=0;
};

