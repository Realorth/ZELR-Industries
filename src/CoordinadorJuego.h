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
	enum Estado { INICIO, JUEGO, GAMEOVER,FIN,MENU_PRINCIPAL,ELEGIR_PERSONAJE};//Falta estado de pausa
	Estado estado;
	const char* m;
	string a;
	bool Estado_Pausa=true;//Representa sí se ha pausado o no el juego
	int Posicon_Seleccion = 0;
	std::vector<char> PersonajeDesbloqueado;
};

