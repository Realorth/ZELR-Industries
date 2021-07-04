#pragma once
#include"freeglut.h"
typedef unsigned char Byte;
struct ColorRGB {
	Byte r, g, b;
	ColorRGB(Byte red=255, Byte green=255,Byte blue=255):r(red),g(green),b(blue) {}
	void set(Byte r = 255, Byte g = 255, Byte b = 255) {
		this->r = r; this->b = b; this->g = g;
	}
	void ponColor() {
		glColor3ub(r, g, b);
	}
};