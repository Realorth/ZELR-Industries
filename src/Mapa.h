#pragma once
#include"vector2D.h"
#include"Vector3D.h"
#include"ColorRGB.h"
#include"pared.h"
#include<vector>
#include"ETSIDI.h"
#include<memory>
#include<algorithm>
#include<random>
#define MAX_LONG 50
class Mapa //Es una lista de paredes
{
public:
	enum tipo {CEMENTERIO=0,NIEVE,BASICO};

protected:
	std::vector<pared*> suelo;
	std::vector<pared*> plataforma;
	std::vector<pared*> fondo;
	int numero=0; //innecesario
	tipo ptipo;//Guarda el tipo de mapa

public:
	Mapa();//Arreglar
	Mapa(int l);//para cuando  se quiere definir un mapa
	Mapa(tipo l);
	virtual ~Mapa();
	void Agregar(pared*);
	void Inicializa();//Hacer
	void Genera();//Arreglar
	void BorrarContenido();
	void Borrar(int index);
	void Borrar_suelo(int index);
	void dibuja();
	void SetTipo(int l);
	void SetTipo(tipo a) { ptipo = a; }
	tipo GetTipo() { return ptipo; }
	std::vector<pared*> GetPlataforma(){ return plataforma; }
	std::vector<pared*> GetSuelo() { return suelo; }
	friend class Interaccion;
private:
	//ETSIDI::Sprite* Suelo=nullptr;
	ETSIDI::Sprite* Plataforma = nullptr;
	ETSIDI::Sprite* Suelo = nullptr;
	// Se crean para facilitar el dibujo de cada propiedad
	void dibuja_suelo();
	void dibuja_fondo();
	void dibuja_plataforma();
	// Se crea para facilitar la aplicación de las texturas	
	void textura_suelo(int op, pared* a);
	// Ayuda para las texturas
	inline void polygon(pared* s);
	inline void polygon3D(pared* s);

	//Funciones de ayuda para la generación del mundo

	void Genera_fondo();
	void Genera_fondo(int,float);
};

