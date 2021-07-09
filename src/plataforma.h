#pragma once
#include "ListaPared.h"
#include<vector>
#include<string>
#include<cstring>
#include"ETSIDI.h"
class plataforma :
    public ListaPared
{
public:
	plataforma() :ListaPared() {}
	~plataforma() { }
	void Genera();
	void dibuja();
};

