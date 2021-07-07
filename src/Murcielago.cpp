#include "Murcielago.h"



Murcielago::Murcielago() :Enemigos(0, 0, "imagenes/Murcielago_derecha.png", 3)
{
	vida = 1000;
	ataque = 3;
	aceleracion.x = aceleracion.y = 0;
	velocidad.x = 11;
}
void Murcielago::vuela() {
	aceleracion = (0, 0);

}//no le afecta la gravedad
void Murcielago::mueve(hombre& h) {
	vector2D dirmov = h.GetPos() - this->posicion;				//obtiene la dirección que debe seguir para perseguir al hombre
	dirmov = dirmov.unitario() * (this->GetVel()).modulo();		//Le aplica el modulo de su velocidad inicial


}