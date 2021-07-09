#pragma once
#include "lecturamonedas.h"
#include <string>
#include <cstring>
#include<sstream>

using namespace std;

void LecturaMonedas::leer(string& m)
{
	string line;
	ifstream myfile("monedas.txt");
	if (myfile.is_open())
	{
		getline(myfile, line);

		myfile.close();
	}
	else {
		cout << "Unable to open this file" << endl;
	}
	m = line;
}

void LecturaMonedas::escribirPerDes(string& lhs, const char* rhs)
{
	LecturaMonedas::leerPerDes(lhs);
	char* aux = new char[lhs.size()+1];
	strcpy(aux, lhs.c_str());
	ofstream myfile;
	myfile.open("Personaje_Desbloqueado.txt");
	if (myfile.is_open()) {
		std::strcat(aux,rhs);
		myfile << aux;
		myfile.close();
	}
	else {
		cout << "Unable to create this file" << endl;
	}
	lhs = aux;
}
void LecturaMonedas::leerPerDes(string& m)
{
	string line;
	ifstream myfile("Personaje_Desbloqueado.txt");
	if (myfile.is_open())
	{
		getline(myfile, line);

		myfile.close();
	}
	else {
		cout << "Unable to open this file" << endl;
	}
	m = line;
}
void LecturaMonedas::escribir(string& lhs)
{
	ofstream myfile;
	myfile.open("monedas.txt");
	if (myfile.is_open()) {
		myfile << lhs;
		myfile.close();
	}
	else {
		cout << "Unable to create this file" << endl;
	}
}