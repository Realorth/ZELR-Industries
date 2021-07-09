#include "CoordinadorJuego.h"

CoordinadorJuego::CoordinadorJuego():
	estado(INICIO),Estado_Pausa(true),EleccionPersonaje(0)
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
		switch (key)
		{
		case ' ':
			estado = MENU_PRINCIPAL;
			break;
		case 's':case 'S':
			exit(0);
			break;
		}
	}
	else if (estado==ELEGIR_PERSONAJE) {
		switch (key)
		{
		case 'e':
		case 'E':
			if (PersonajeDesbloqueado.find("P") < 0xfffff && !Seguro_Compra) //Pistolero
				SoporteEleccionPersonaje = 0;
			else {
				if (Valor_Monedas > 0)
					Seguro_Compra = true;
			}
			break;
		case 'R':
		case 'r':
			if (PersonajeDesbloqueado.find("A") < 0xfffff &&!Seguro_Compra ) //Arquero
				SoporteEleccionPersonaje = 1;
			else {
				if (Valor_Monedas >= 50) {
					Seguro_Compra = true;
					EleccionCompra = "A";
				}

			}
			break;
		case 't':
		case 'T':
			if (PersonajeDesbloqueado.find("M") < 0xfffff && !Seguro_Compra) // Acolito
				SoporteEleccionPersonaje = 2;
			else {
				if (Valor_Monedas >= 100) {
					Seguro_Compra = true;
					EleccionCompra = "M";
				}

			}
			break;
		case 'S':
		case 's':
			if(!Seguro_Compra)
			estado = MENU_PRINCIPAL;
			else 
				Seguro_Compra = false;
			break;
		case ' ':
			if (Seguro_Compra) {
				LecturaMonedas::escribirPerDes(PersonajeDesbloqueado, EleccionCompra);
				if (!strcmp(EleccionCompra, "A"))
					Valor_Monedas -= 50;
				else if (!strcmp(EleccionCompra, "M"))
					Valor_Monedas -= 100;
				a = to_string(Valor_Monedas);
				m = a.c_str();
				LecturaMonedas::escribir(a);
				Seguro_Compra = false;
			}
			else {
				EleccionPersonaje = SoporteEleccionPersonaje;
				estado = MENU_PRINCIPAL;
			}

			break;
		}
	}
	else if(estado==MENU_PRINCIPAL){
		switch (key)
		{
		case 'E':
		case 'e':
			estado = ELEGIR_PERSONAJE;
			break;
		case ' ':
			Estado_Pausa = false;
			mundo.setPersonaje(EleccionPersonaje);
			mundo.inicializa();
			estado = JUEGO;
			break;
		case'I':case'i':
			estado = INSTRUCCIONES;
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
			/*Valor_Monedas = Valor_Monedas + mundo.getnCoin();
			a = to_string(Valor_Monedas);
			m = a.c_str();
			LecturaMonedas::escribir(a);
			estado = MENU_PRINCIPAL;*/
			estado = INICIO;
			break;
		case ' ':
			if (mundo.getImpacto()) 
				estado = INICIO;
			else
				estado = JUEGO;
			mundo.setcaida(false);//Para reiniciar el juego
			mundo.setImpacto(false);//Para reiniciar el juego
			break;
		}
	}
	else if (estado == FIN) {
		if (key == 'c'||key=='C')
			estado = INICIO;
	}
	else if (estado == INSTRUCCIONES) {
		
	switch (key)
	{
	case's':case'S':case ' ':
		estado = MENU_PRINCIPAL;
			break;
	default:
		break;
	}

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
		ETSIDI::playMusica("sonidos/Inicio.wav", true);
		flagGameOver = true;
		gluLookAt(0, 7.5, 30,//posicion ojo
			0.0, 7.65, 0.0,//hacia donde mira
			0.0, 1.0, 0.0);//definimos hacia arriba eje y
		ETSIDI::setTextColor(1, 1, 0);
		/*ETSIDI::setFont("fuentes/Astral_Groove.ttf", 12); */
		ETSIDI::setFont("fuentes/waltographUI.ttf", 30); 
		ETSIDI::printxy("JUEGO DE PLATAFORMAS", -9, 8);
		ETSIDI::setTextColor(0, 1, 1);
		ETSIDI::setFont("fuentes/waltographUI.ttf", 15);
		ETSIDI::printxy("ZELR-INDUSTRIES", -12, 15);
		ETSIDI::setTextColor(1, 1, 1);
		ETSIDI::setFont("fuentes/Bitwise.ttf", 12);
		ETSIDI::printxy("PULSE EL ESPACIO PARA JUGAR", -5, 6);
		ETSIDI::printxy("PULSE LA TECLA -S- PARA SALIR", -5, 4);
		if (flagLecturaMonedas) {
			LecturaMonedas::leer(a);
			m = a.c_str();
			Valor_Monedas = atoi(m);
			LecturaMonedas::leerPerDes(PersonajeDesbloqueado);
			if (PersonajeDesbloqueado.find("P") > 0xffff) {
				// Proteccion en caso que no exista el personaje principal
				PersonajeDesbloqueado = "";
				LecturaMonedas::escribirPerDes(PersonajeDesbloqueado, "P");
				LecturaMonedas::leerPerDes(PersonajeDesbloqueado);
			}
			flagLecturaMonedas = false;
		}
	}
	else if (estado == MENU_PRINCIPAL) {
		gluLookAt(0, 7.5, 30,//posicion ojo
			0.0, 7.65, 0.0,//hacia donde mira
			0.0, 1.0, 0.0);//definimos hacia arriba eje y

		ETSIDI::setTextColor(0, 1, 1);
		ETSIDI::setFont("fuentes/waltographUI.ttf", 15);
		ETSIDI::printxy("ZELR-INDUSTRIES", -12, 15);

		//Impresión de las monedas disponibles en pantalla
		ETSIDI::setTextColor(1, 1, 1);
		ETSIDI::setFont("fuentes/Bitwise.ttf", 12);
		ETSIDI::printxy("Monedas Disponibles: ", 5, 14);
		ETSIDI::printxy(m, 12, 14);
		// Impresion del menu
		ETSIDI::setFont("fuentes/Bitwise.ttf", 14);
		ETSIDI::printxy("PULSE  -E- PARA ELEGIR EL PERSONAJE", -9, 10);
		ETSIDI::printxy("PULSE -ESPACIO- PARA EMPEZAR A JUGAR", -9, 6);
		ETSIDI::printxy("PULSE -I- PARA VER LOS CONTROLES", -9, 8);
	// Impresion de la opción de volver a atrás
		ETSIDI::setTextColor(0.5, 0.5, 1);
		ETSIDI::setFont("fuentes/Bitwise.ttf", 12);
		ETSIDI::printxy("PULSE LA TECLA -S- PARA ATRAS", -10, 2);

	}
	else if (estado == ELEGIR_PERSONAJE){
		gluLookAt(0, 7.5, 30,//posicion ojo
			0.0, 7.65, 0.0,//hacia donde mira
			0.0, 1.0, 0.0);//definimos hacia arriba eje y

		ETSIDI::setTextColor(0, 1, 1);
		ETSIDI::setFont("fuentes/waltographUI.ttf", 15);
		ETSIDI::printxy("ZELR-INDUSTRIES", -12, 15);
		//Imprimir Monedas
		ETSIDI::setTextColor(1, 1, 1);
		ETSIDI::setFont("fuentes/Bitwise.ttf", 12);
		ETSIDI::printxy("Monedas Disponibles: ", 5, 14);
		ETSIDI::printxy(m, 12, 14);

		if (!Seguro_Compra) {
			// Pistolero
			if (EleccionPersonaje == 0) {
				ETSIDI::setTextColor(1, 0, 1);
				ETSIDI::printxy("PERSONAJE ELEGIDO: PISTOLERO", -9, 10);
			}else {
				if (SoporteEleccionPersonaje == 0) 
					ETSIDI::setTextColor(1, 1, 0.4);
				else 
					ETSIDI::setTextColor(1, 1, 1);
					ETSIDI::printxy("PULSE LA TECLA -E- PARA ELEGIR EL PISTOLERO", -9, 10);
			}
			// Arquero
			if (PersonajeDesbloqueado.find("A") < 0xfffff) {
				if (EleccionPersonaje == 1) {
					ETSIDI::setTextColor(1, 0, 1);
					ETSIDI::printxy("PERSONAJE ELEGIDO: ARQUERO", -9, 8);
				}else {
					if (SoporteEleccionPersonaje == 1)
						ETSIDI::setTextColor(1, 1, 0.4);
					else
						ETSIDI::setTextColor(1, 1, 1);
					ETSIDI::printxy("PULSE LA TECLA -A- PARA ELEGIR EL ARQUERO", -9, 8);
				}
			}else if(Valor_Monedas<50){
				ETSIDI::setTextColor(1, 0, 0);
				ETSIDI::printxy("PERSONAJE ARQUERO NO DISPONIBLE>>DESBLOQUEO CON 50 MONEDAS", -10, 8);
			}else {
				ETSIDI::setTextColor(0, 0.7, 0.7);
				ETSIDI::printxy("PULSE LA TECLA -R- PARA COMPRAR EL ARQUERO (50 MONEDAS)", -10, 8);
			}
			// Mago
			if (PersonajeDesbloqueado.find("M") < 0xfffff) {
				if (EleccionPersonaje == 2) {
					ETSIDI::setTextColor(1, 0, 1);
					ETSIDI::printxy("PERSONAJE ELEGIDO: MAGO", -9, 6);
				}else {
					if (SoporteEleccionPersonaje == 2)
						ETSIDI::setTextColor(1, 1, 0.4);
					else
						ETSIDI::setTextColor(1, 1, 1);
					ETSIDI::printxy("PULSE LA TECLA -T- PARA ELEGIR EL MAGO", -9, 6);
				}
			}else if(Valor_Monedas<100) {
				ETSIDI::setTextColor(1, 0, 0);
				ETSIDI::printxy("PERSONAJE MAGO NO DISPONIBLE>>DESBLOQUEO CON 100 MONEDAS", -10, 6);
			}else {
				ETSIDI::setTextColor(0, 0.7, 0.7);
				ETSIDI::printxy("PULSE LA TECLA -T- PARA COMPRAR EL MAGO (100 MONEDAS)", -10, 6);
			}
			// El resto
			ETSIDI::setTextColor(0.5, 0.5, 1);
			ETSIDI::setFont("fuentes/Bitwise.ttf", 12);
			ETSIDI::printxy("PULSE LA TECLA -S- PARA ATRAS", -10, 2);
			ETSIDI::setTextColor(0.1, 0.3, 0.7);
			ETSIDI::setFont("fuentes/waltographUI.ttf", 14);
			ETSIDI::printxy("PULSE LA BARRA -ESPACIADORA- PARA APLICAR CAMBIOS", -10, 12);
			// Fin de llaves
		}else {

			// Sí se espera confirmación de compra
			Vector3D a(0, 7.5, 30);
			glDisable(GL_LIGHTING);
			glColor3ub(150, 150, 150);
			glBegin(GL_POLYGON);
			glVertex3f(a.x - 15, a.y + 6, 0.01f);
			glVertex3f(a.x - 15, a.y - 6, 0.01f);
			glVertex3f(a.x + 15, a.y - 6, 0.01f);
			glVertex3f(a.x + 15, a.y + 6, 0.01f);
			glEnd();
			glEnable(GL_LIGHTING);

			ETSIDI::setTextColor(0, 0, 0);
			ETSIDI::setFont("fuentes/Astral_Groove.ttf", 10);
			ETSIDI::printxy("SEGURO QUE LO QUIERES COMPRAR?", - 12, 10,0.02F);
			const char* c = "PULSE LA TECLA ESPACIADORA PARA CONFIRMAR";
			ETSIDI::setTextColor(0, 0, 0);
			ETSIDI::setFont("fuentes/Marlboro.ttf", 20);
			ETSIDI::printxy(c,  - 10, 7,0.02F);
			const char* b = "PULSE LA TECLA -S- PARA ATRAS";
			ETSIDI::printxy(b, - 10, 5,0.02F);
		}


	}
	else if (estado == JUEGO) {

		if (mundo.getFinalJuego()) {
			mundo.setFinalJuego(false);
			estado = FIN;
		}
		else if (mundo.getFinalMuerte()) {
			mundo.setFinalMuerte(false);
			flagGameOver = true;
			estado = GAMEOVER;
		}
		else
		{
			mundo.GestorNiveles();
			mundo.dibuja();
			if (Estado_Pausa) {
				auto a = mundo.getOjo();
				// DIbujo de polígono para poder aparecer texto en pantalla
				glDisable(GL_LIGHTING);
				glColor3ub(255, 255, 255);
				glBegin(GL_POLYGON);
				glVertex3f(a.x - 12, a.y + 5, 0.01f);
				glVertex3f(a.x - 12, a.y - 5, 0.01f);
				glVertex3f(a.x + 12, a.y - 5, 0.01f);
				glVertex3f(a.x + 12, a.y + 5, 0.01f);
				glEnd();
				glEnable(GL_LIGHTING);
				//Impresión del estado PAUSA
				ETSIDI::setTextColor(1, 0, 0);
				ETSIDI::setFont("fuentes/Astral_Groove.ttf", 16);
				ETSIDI::printxy("PAUSA", a.x - 10, 10,0.02F);
				// Impresión de las dos opciones
				ETSIDI::setTextColor(0, 0, 0);
				ETSIDI::setFont("fuentes/Marlboro.ttf", 20);
				const char* c = "PULSE LA TECLA ESPACIADORA O -P- PARA CONTINUAR";
				ETSIDI::printxy(c, a.x - 10, 7,0.02F);
				const char* b = "PULSE LA TECLA -S- PARA SALIR";
				ETSIDI::printxy(b, a.x - 10, 5,0.02F);
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
		if (mundo.getImpacto())
			ETSIDI::printxy("PULSE LA TECLA ESPACIADORA PARA SALIR", -10 + mundo.getOjo().x, 2);
		else
			ETSIDI::printxy("PULSE LA TECLA ESPACIADORA PARA VOLVER A JUGAR", -10 + mundo.getOjo().x, 2);
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
		ETSIDI::setTextColor(0, 0, 0);
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
	else if (estado == INSTRUCCIONES) {
		gluLookAt(0, 7.5, 30,//posicion ojo
			0.0, 7.65, 0.0,//hacia donde mira
			0.0, 1.0, 0.0);//definimos hacia arriba eje y

		ETSIDI::setTextColor(0, 1, 1);
		ETSIDI::setFont("fuentes/waltographUI.ttf", 15);
		ETSIDI::printxy("ZELR-INDUSTRIES", -12, 15);

		ETSIDI::setTextColor(0.5, 0.5, 1);
		ETSIDI::setFont("fuentes/Bitwise.ttf", 12);
		ETSIDI::printxy("PULSE LA TECLA -S- PARA ATRAS", -10, -1);

		// Empiezan las instrucciones
		ETSIDI::setTextColor(0.2, 0.4, 0.8);
		ETSIDI::setFont("fuentes/waltographUI.ttf", 14);
		ETSIDI::printxy("DEPLAZARSE: ", -10, 12);
		ETSIDI::printxy("ATACAR: ", -10, 7);
		ETSIDI::printxy("PAUSA: ", -10, 2);
		ETSIDI::setTextColor(0.85, 0.85, 0.85);
		//ETSIDI::setFont("fuentes/KindAndRich.ttf", 16);
		ETSIDI::setFont("fuentes/Edge Of Madness.ttf", 9);
		ETSIDI::printxy("PARA PAUSAR EL JUEGO:   TECLA -P-", -8, 1);
		ETSIDI::printxy("IZQUIERDA:   TECLA DE FLECHA IZQUIERDA", -8, 11);
		ETSIDI::printxy("DERECHA:   TECLA DE FLECHA DERECHA", -8, 10);
		ETSIDI::printxy("SALTAR:   TECLA DE FLECHA ARRIBA", -8, 9);
		ETSIDI::printxy("DISPARO NORMAL:   BARRA ESPACIADORA ( 1pt DE VIDA )", -8, 6);
		ETSIDI::printxy("DISPARO ESPECIAL:   TECLA -D- ( 2ptS DE VIDA )", -8, 5);
	}
}
