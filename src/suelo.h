#pragma once
#include"ListaPared.h"
#include<vector>
#include<time.h>
#include"ETSIDI.h"
#include<string>
#include<cstring>
class suelo:public ListaPared
{
public:
	suelo() :ListaPared() {}
	virtual ~suelo() { }
	void Genera();
	void dibuja();
};

