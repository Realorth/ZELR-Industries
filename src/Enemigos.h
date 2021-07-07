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


	float rango;	//distancia a partir de la cual 
	// reaccionan ante una entidad que atacaria
	int vida = 1;
	int ataque = 1;
	int armadura = 0;
	float velataque = 0;

public:
	Enemigos();
	Enemigos(float x, float y,const char*,int tamano_secuencia);
	Enemigos(vector2D a, std::string, int tamano_secuencia);
	Enemigos(vector2D a, const char* b, int tamano_secuencia);

	Enemigos(vector2D pos, vector2D tam, float r, int hp, int armor, int atk, float vatk, const char* b, int n_secuencias);
	
	virtual ~Enemigos();
	virtual void dibuja();
	virtual void ataca(); 

	int GetRango() { return rango; }
	void SetRango(int r) { rango = r; }
	virtual void reacciona() {}

	void SetVida(int hp) { vida = hp; }
	int Getvida() { return vida; }

	void SetArmadura(int a) { armadura = a; }
	int GetArmadura() { return armadura; }

	int GetAtaque() { return ataque; }
	void SetAtaque(int atk) { ataque = atk; }

	vector2D GetTam() { return tamano; }
	void SetTam(vector2D tam) { tamano = tam; }
	void SetTam(float ancho, float alto) { tamano.set(ancho,alto); }
	
	void gira() { velocidad.x = -velocidad.x; }
};

