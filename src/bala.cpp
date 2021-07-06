bala::bala() :disparo(),SBala("imagenes/disparo.png")
{
	aceleracion.x = 9.8;
	aceleracion.y = 0;
	SBala.setCenter(0.3f, 0.5f);
	SBala.setSize(1.5f, 1.5f);

}

bala::~bala()
{}

void bala::dibuja()
{
	glPushMatrix();
	glTranslatef(posicion.x, posicion.y, 0);
	SBala.draw();
	glPopMatrix();
}
