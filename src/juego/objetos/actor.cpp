#include "actor.h"

Actor::Actor()
:	ObjetoJuego()
{
	vx=0;
	vy=0;
	velocidad=3;
}
Actor::~Actor()
{
	for(int i=0; i<NUM_TA; i++)
	{
		delete animaciones[(TipoAnim)i];
	}
}

void Actor::setImagenAnim(const std::string& str, TipoAnim t, int posicion, Uint32 retardo)
{
	if(animaciones[t]==NULL)
	{
		animaciones[t]=new Animador;
	}
	SDL_Surface* sur=ci.cargar(str);
	
	if(sur==NULL) printf("Error: %s\n", SDL_GetError());
		
	animaciones[t]->setImagen(sur, posicion);
	animaciones[t]->setRetardo(retardo, posicion);
}

void Actor::update()
{
	
	posx+=vx;
	posy+=vy;
	
	if(vx>0)
	{
		animacionActual=animaciones[TA_DER];
		ultimaDireccion=TA_DER;
	}
	else if(vx<0)
	{
		animacionActual=animaciones[TA_IZQ];
		ultimaDireccion=TA_IZQ;
	}
	else if(vy>0)
	{
		animacionActual=animaciones[TA_ABA];
		ultimaDireccion=TA_ABA;
	}
	else if(vy<0)
	{
		animacionActual=animaciones[TA_ARR];
		ultimaDireccion=TA_ARR;
	}
	else
	{
		animacionActual->reset();
		animacionActual=animacion;
		animacionActual->reset();
	}
	
	
	// Actualiza la animacion correspondiente
	ObjetoJuego::update();
}

int Actor::getvx(){	return vx;}
int Actor::getvy(){	return vy;}
int Actor::getVelocidad(){	return velocidad;}

void Actor::setvx(int v){ vx=v; }
void Actor::setvy(int v){ vy=v; }
void Actor::setVelocidad(int v){ velocidad=v; }
