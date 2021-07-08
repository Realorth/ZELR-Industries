#pragma once
#include "Enemigos.h"
class PerroVil :
    public Enemigos
{
public:
    PerroVil(float x, float y);
    PerroVil(vector2D a);
    PerroVil();
    virtual ~PerroVil(){}
  
    void mueve(float t) { objetomovil::mueve(t); if (velocidad.y < -5.0)velocidad.y = -5.0f; }
    void ataca();
    void gira();
    void reacciona();
};

