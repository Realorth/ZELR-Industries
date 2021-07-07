#pragma once
#include "Enemigos.h"
class PerroVil :
    public Enemigos
{
public:
    PerroVil(vector2D a) :Enemigos(a, "imagenes/wolfy.png", 4) {
    
    }
    PerroVil():Enemigos(0, 0, "imagenes/wolfy.png", 4) {
  
    }
    
};

