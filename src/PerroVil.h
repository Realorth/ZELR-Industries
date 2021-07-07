#pragma once
#include "Enemigos.h"
class PerroVil :public Enemigos
{
public:
    //PerroVil(vector2D a) :Enemigos(a, "imagenes/wolfy.png", 4) {}
    PerroVil():Enemigos(0, 0, "imagenes/wolfy.png", 4) { }
    
    PerroVil(vector2D pos, vector2D tam, int r, int hp, int armor, int atk, float vatk)
        :Enemigos(pos, tam, r, hp, armor, atk, vatk, "imagenes/wolfy.png", 4) {}
    PerroVil(vector2D pos):Enemigos(pos, (2.5, 2.5), 1, 2, 0, 1, 0, "imagenes/wolfy.png", 4) {}      //valores por defecto de perro cualquiera


    void ataca();
    void gira();
    void reacciona();
};

