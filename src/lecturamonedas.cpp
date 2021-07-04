#pragma once
#include "lecturamonedas.h"
#include <string>
#include <cstring>

using namespace std;

void LecturaMonedas::leer(string& m)
{
	string line;
	const char* cadena;
	ifstream myfile("monedas.txt");
	if (myfile.is_open())
	{
		getline(myfile, line);

		myfile.close();
	}
	cadena = line.c_str();
	m = cadena;

}