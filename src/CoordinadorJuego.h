#pragma once
#include "Mundo.h"
#include "lecturamonedas.h"

class CoordinadorJuego
{
public:
	CoordinadorJuego();
	virtual ~CoordinadorJuego();

	void teclaEspecial(unsigned char key);
	void teclaEspecialUp(unsigned char key);
	void tecla(unsigned char key);
	void mueve();
	void dibuja();

protected:
	Mundo mundo;
	enum Estado { INICIO, JUEGO, GAMEOVER,FIN,MENU_PRINCIPAL,ELEGIR_PERSONAJE,INSTRUCCIONES};//Falta estado de pausa
	Estado estado;
	const char* m;
	string a;
	bool Estado_Pausa=true;//Representa sí se ha pausado o no el juego
	
	int Posicon_Seleccion = 0;
	// Ayuda para la tienda
	string PersonajeDesbloqueado;
	int EleccionPersonaje = 0;
	int SoporteEleccionPersonaje = EleccionPersonaje;
	int EleccionMenu = 0;
	int SoporteEleccionMenu = EleccionMenu;
	int Valor_Monedas = 0;
	bool Seguro_Compra = false;
	const char* EleccionCompra;
};

