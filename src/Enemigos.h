#pragma once
#include"objetomovil.h"
#include"ETSIDI.h"
#include<string>
class Enemigos: public objetomovil
{
protected:
	ETSIDI::SpriteSequence sprite_enemigo;
	int tamano_secuencia = 0;
	vector2D tamano;
	//tamano.x ==ancho
	//tamano.y= altura

	float rango=0;	//distancia a partir de la cual 
	// reaccionan ante una entidad que atacaria
	int vida = 1;
	int ataque = 1;
	int armadura = 0;
	float velataque = 0;

public:
	Enemigos();
	Enemigos(vector2D a, std::string, int tamano_secuencia);
	Enemigos(vector2D pos, const char* b, int n_secuencias, vector2D tam = {3,2.5});
	Enemigos(float x, float y, const char* b, int n_secuencias, float wide=3, float height=2.5);
	virtual ~Enemigos();
	virtual void dibuja();
	virtual void ataca(); 

	int GetRango() { return rango; }
	void SetRango(int r) { rango = r; }
	void AumentaRango(int i = 1) { rango += i; }
	void DisminuyeRango(int i = 1) { rango -= i; }
	virtual void reacciona() {}

	void SetVida(int hp) { vida = hp; }
	int Getvida() { return vida; }
	void AumentaVida(int i=1) { vida+=i; }
	void DisminuyeVida(int i=1) { vida-=i; }

	void SetArmadura(int a) { armadura = a; }
	int GetArmadura() { return armadura; }
	void AumentaArmadura(int i = 1) { armadura += i; }
	void DisminuyeArmadura(int i = 1) { armadura -= i; }

	int GetAtaque() { return ataque; }
	void SetAtaque(int atk) { ataque = atk; }
	void AumentaAtaque(int i = 1) { ataque += i; }
	void DisminuyeAtaque(int i = 1) { ataque -= i; }

	vector2D GetTam() { return tamano; }
	void SetTam(vector2D tam) { tamano = tam; }
	void SetTam(float ancho, float alto) { tamano.set(ancho,alto); }
	
	void gira() { velocidad.x = -velocidad.x; }
};

