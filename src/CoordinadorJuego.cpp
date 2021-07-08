#include "CoordinadorJuego.h"

CoordinadorJuego::CoordinadorJuego():
	estado(INICIO),Estado_Pausa(true)
{
	estado = INICIO;
}

CoordinadorJuego::~CoordinadorJuego()
{
}

void CoordinadorJuego::teclaEspecial(unsigned char key)
{
	if (estado == JUEGO)
		if(!Estado_Pausa)
			mundo.teclaEspecial(key);

}

void CoordinadorJuego::teclaEspecialUp(unsigned char key)
{
	if (estado == JUEGO )
		if(!Estado_Pausa)
			mundo.teclaEspecialUp(key);
}
void CoordinadorJuego::tecla(unsigned char key)
{
	if (estado == INICIO) {
		if (key == ' ')
			estado = MENU_PRINCIPAL;
		if (key == 's')
			exit(0);
	}
	else if(estado==MENU_PRINCIPAL){
		switch (key)
		{
		case 'e':
		case 'E':
			Estado_Pausa = false;
			mundo.setPersonaje(0);
			mundo.inicializa();
			estado = JUEGO;
			break;
		case 'R':
		case 'r':
			Estado_Pausa = false;
			mundo.setPersonaje(1);
			mundo.inicializa();
			estado = JUEGO;
			break;
		case 't':
		case 'T':
			Estado_Pausa = false;
			mundo.setPersonaje(2);
			mundo.inicializa();
			estado = JUEGO;
			break;
		case 'S':
		case 's':
			Estado_Pausa = true;
			estado = INICIO;
			break;
		}

	}
	else if (estado == JUEGO) {
		if (!Estado_Pausa) {
			mundo.tecla(key);
			if (key == 'P' || key == 'p')
				Estado_Pausa = true;
		}
		else
			switch (key) {
			case 's':
			case 'S':
				Estado_Pausa = false;
				estado = INICIO;
			case ' ':
			case'P':
			case 'p':
				Estado_Pausa = false;
				break;
			}
	}
	else if (estado == GAMEOVER) {
		switch (key) {
		case 'S':case 's':
			mundo.setcaida(false);//Para reiniciar el juego
			mundo.setImpacto(false);//Para reiniciar el juego			
			estado = INICIO;
			break;
		case ' ':
			mundo.setcaida(false);//Para reiniciar el juego
			mundo.setImpacto(false);//Para reiniciar el juego			
			estado = MENU_PRINCIPAL;
			break;
		}
	}
	else if (estado == FIN) {
		if (key == 'c'||key=='C')
			estado = INICIO;
	}
}
void CoordinadorJuego::mueve()
{
	if (estado == JUEGO) {
		if(!Estado_Pausa)
			mundo.mueve();
	}
}

void CoordinadorJuego::dibuja()
{
	static bool flagLecturaMonedas = true;//Flag para la lectura de las monedas(leer una vez)
	static bool flagGameOver = true;//Flag para el game over
	static bool flagMapa = true;//Flag para cambio de mapa

	if (estado == INICIO) {
		flagGameOver = true;
		gluLookAt(0, 7.5, 30,//posicion ojo
				0.0, 7.65, 0.0,//hacia donde mira
				0.0, 1.0, 0.0);//definimos hacia arriba eje y
		ETSIDI::setTextColor(1, 1, 0);
		ETSIDI::setFont("fuentes/Astral_Groove.ttf", 12);
		ETSIDI::printxy("JUEGO DE PLATAFORMAS", -7, 8);
		ETSIDI::setTextColor(0, 0, 1);
		ETSIDI::setFont("fuentes/Astral_Groove.ttf", 8);
		ETSIDI::printxy("ZELR-INDUSTRIES", -12, 15);
		ETSIDI::setTextColor(1, 1, 1);
		ETSIDI::setFont("fuentes/Bitwise.ttf", 12);
		ETSIDI::printxy("PULSE EL ESPACIO PARA JUGAR", -5, 6);
		ETSIDI::printxy("PULSE LA TECLA -S- PARA SALIR", -5, 4);
	}
	else if (estado == MENU_PRINCIPAL) {
		gluLookAt(0, 7.5, 30,//posicion ojo
			0.0, 7.65, 0.0,//hacia donde mira
			0.0, 1.0, 0.0);//definimos hacia arriba eje y

		ETSIDI::setTextColor(1, 1, 1);
		ETSIDI::setFont("fuentes/Bitwise.ttf", 12);
		ETSIDI::printxy("PULSE LA TECLA -E- PARA EMPEZAR A JUGAR CON PISTOLERO", -9, 7);
		ETSIDI::printxy("ZERL INDUSTRIES", 2, 1);
		ETSIDI::printxy("Monedas Disponibles: ", -3, 14);
		ETSIDI::printxy("PULSE LA TECLA -S- PARA ATRAS", -6, 3);
		//Impresión de las monedas disponibles en pantalla
		if (flagLecturaMonedas) {
			LecturaMonedas::leer(a);
			m = a.c_str();
			cout << m;
			flagLecturaMonedas = false;
		}
		ETSIDI::setTextColor(1, 1, 1);
		ETSIDI::setFont("fuentes/Bitwise.ttf", 12);
		ETSIDI::printxy(m, 5, 14);

		if (atoi(m) >= 500)
			ETSIDI::printxy("PULSE LA TECLA -R- PARA EMPEZAR A JUGAR CON ARQUERO", -9, 6);

		if (atoi(m) >= 1000)
			ETSIDI::printxy("PULSE LA TECLA -T- PARA EMPEZAR A JUGAR CON MAGO", -9, 5);

		ETSIDI::setTextColor(1, 0, 0);
		if (atoi(m) < 500)
			ETSIDI::printxy("JUGADOR ARQUERO NO DISPONIBLE>>DESBLOQUEO CON 500 MONEDAS", -10, 6);
		if (atoi(m) < 1000)
			ETSIDI::printxy("JUGADOR MAGO NO DISPONIBLE>>DESBLOQUEO CON 1000 MONEDAS", -10, 5);
	}
	else if (estado == JUEGO) {
		static bool flagLecturaMonedas = true;//Flag para la lectura de las monedas(leer una vez)
	static bool flagGameOver = true;//Flag para el game over
	static bool flagMapa = true;//Flag para cambio de mapa


	if (estado == INICIO) {
		flagGameOver = true;
		gluLookAt(0, 7.5, 30,//posicion ojo
				0.0, 7.65, 0.0,//hacia donde mira
				0.0, 1.0, 0.0);//definimos hacia arriba eje y


		ETSIDI::setTextColor(1, 1, 0);
		ETSIDI::setFont("fuentes/Astral_Groove.ttf", 12);
		ETSIDI::printxy("JUEGO DE PLATAFORMAS", -7, 8);
		ETSIDI::setTextColor(0, 0, 1);
		ETSIDI::setFont("fuentes/Astral_Groove.ttf", 8);
		ETSIDI::printxy("ZELR-INDUSTRIES", -12, 15);
		ETSIDI::setTextColor(1, 1, 1);
		ETSIDI::setFont("fuentes/Bitwise.ttf", 12);
		ETSIDI::printxy("PULSE EL ESPACIO PARA JUGAR", -5, 6);
		ETSIDI::printxy("PULSE LA TECLA -S- PARA SALIR", -5, 4);		
	}
	else if (estado == MENU_PRINCIPAL) {
		gluLookAt(0, 7.5, 30,//posicion ojo
			0.0, 7.65, 0.0,//hacia donde mira
			0.0, 1.0, 0.0);//definimos hacia arriba eje y

		ETSIDI::setTextColor(1, 1, 1);
		ETSIDI::setFont("fuentes/Bitwise.ttf", 12);
		ETSIDI::printxy("PULSE LA TECLA -E- PARA EMPEZAR A JUGAR CON PISTOLERO", -9, 7);
		ETSIDI::printxy("ZERL INDUSTRIES", 2, 1);
		ETSIDI::printxy("Monedas Disponibles: ", -3, 14);
		ETSIDI::printxy("PULSE LA TECLA -S- PARA ATRAS", -6, 3);
		//Impresión de las monedas disponibles en pantalla
		if (flagLecturaMonedas) {
			LecturaMonedas::leer(a);
			m = a.c_str();
			cout << m;
			flagLecturaMonedas = false;
		}
		ETSIDI::setTextColor(1, 1, 1);
		ETSIDI::setFont("fuentes/Bitwise.ttf", 12);
		ETSIDI::printxy(m, 5, 14);

		if (atoi(m) >= 500)
			ETSIDI::printxy("PULSE LA TECLA -R- PARA EMPEZAR A JUGAR CON ARQUERO", -9, 6);

		if (atoi(m) >= 1000)
			ETSIDI::printxy("PULSE LA TECLA -T- PARA EMPEZAR A JUGAR CON MAGO", -9, 5);

		ETSIDI::setTextColor(1, 0, 0);
		if (atoi(m) < 500)
			ETSIDI::printxy("JUGADOR ARQUERO NO DISPONIBLE>>DESBLOQUEO CON 500 MONEDAS", -10, 6);
		if (atoi(m) < 1000)
			ETSIDI::printxy("JUGADOR MAGO NO DISPONIBLE>>DESBLOQUEO CON 1000 MONEDAS", -10, 5);

	}
	else if (estado == JUEGO) {

		if (mundo.getFinalJuego()) {
			mundo.setFinalJuego(false);
			estado = FIN;
		}else if(mundo.getFinalMuerte()) {
			mundo.setFinalMuerte(false);
			estado = GAMEOVER;
		}
		else
		{
		mundo.GestorNiveles();
		mundo.dibuja();
			if (Estado_Pausa) {
				auto a = mundo.getOjo();
				glDisable(GL_LIGHTING);
				glColor3ub(255, 255, 255);
				glBegin(GL_POLYGON);
				glVertex3f(a.x-12,a.y+5 ,0.01f );
				glVertex3f(a.x-12,a.y-5 ,0.01f );
				glVertex3f(a.x+12,a.y-5 ,0.01f );
				glVertex3f(a.x+12,a.y+5 ,0.01f );
				glEnd();
				glEnable(GL_LIGHTING);

				ETSIDI::setTextColor(1, 0, 0);
				ETSIDI::setFont("fuentes/Astral_Groove.ttf", 16);
				ETSIDI::printxy("PAUSA",a.x-10, 10);
				const char* c = "PULSE LA TECLA ESPACIO O -P- PARA CONTINUAR";
				ETSIDI::setTextColor(0, 0, 0);
				ETSIDI::setFont("fuentes/Marlboro.ttf", 20);
				ETSIDI::printxy(c, a.x-10, 7);
				const char* b = "PULSE LA TECLA -S- PARA SALIR";
				ETSIDI::printxy(b, a.x-10, 5);
			}
		}
	}
	else if (estado == GAMEOVER) {
		static bool flag = true;
		//bool flagSonido = true;
		mundo.dibuja();
		ETSIDI::setTextColor(1, 0, 0);
		ETSIDI::setFont("fuentes/Bitwise.ttf", 16);
		ETSIDI::printxy("GAMEOVER: Has perdido...", -10 + mundo.getOjo().x, 10);
		ETSIDI::printxy("PULSE LA TECLA -S- PARA SALIR", -10 + mundo.getOjo().x, 5);
		ETSIDI::printxy("PULSE LA TECLA ESPACIO PARA VOLVER A JUGAR", - 10 + mundo.getOjo().x, 2);
		//Almacenamiento de las monedas adquiridas en el fichero .txt
		if (flagGameOver) {
			ETSIDI::play("sonidos/GameOver.wav");//Solo suena una vez cuando se pierde
			ofstream dato("monedas.txt");
			int inicial = atoi(m);//Convierte const char* a int para realizar la suma
			if (dato.is_open()) {
				dato << mundo.getnCoin() + inicial;
				dato.close();
			}
			else cout << "Unable to open file";
			flag = false;
			flagGameOver = false;
		}
		//Vuelve a establecer el flag a true para que
		//cuando se vuelva a la pantalla de inicio aparezca las monedas totales
		flagLecturaMonedas = true;
	}
	else if (estado == FIN) {
		static bool flag = true;
		mundo.dibuja();
		ETSIDI::setFont("fuentes/Bitwise.ttf", 16);
		ETSIDI::printxy("ENHORABUENA:¡¡Has triunfado!!", -5 + mundo.getOjo().x, 10);
		ETSIDI::printxy("PULSE LA TECLA -C- PARA CONTINUAR", -5 + mundo.getOjo().x, 9);

		//Almacenamiento de las monedas adquiridas en el fichero .txt
		if (flag) {
			ofstream dato("monedas.txt");
			int inicial = atoi(m);//Convierte const char* a int para realizar la suma
			if (dato.is_open()) {
				dato << mundo.getnCoin() + inicial;
				dato.close();
			}
			else cout << "Unable to open file";
			flag = false;

		}
		//Vuelve a establecer el flag a true para que
		//cuando se vuelva a la pantalla de inicio aparezca las monedas totales
		flagLecturaMonedas = true;

	}

}
