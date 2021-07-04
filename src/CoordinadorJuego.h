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
	enum Estado { INICIO, JUEGO, GAMEOVER,FIN };//Falta estado de pausa
	Estado estado;
	const char* m;
	string a;

};

