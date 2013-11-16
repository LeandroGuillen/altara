#include "objetojuego.h"

// Declaracion de miembros estaticos
CargadorImagenes ObjetoJuego::ci;
int ObjetoJuego::id=0;

ObjetoJuego::ObjetoJuego()
{
	tieneAnimacion=false;
	animacionActual=NULL;
	animacion=NULL;
	myId=id++;
	posx=400;
	posy=200;
}
ObjetoJuego::~ObjetoJuego()
{
	delete animacion;
}


void ObjetoJuego::pintar(SDL_Surface* pantalla)
{
	SDL_Rect offset;
	offset.x = posx;
	offset.y = posy;
	
	SDL_BlitSurface(animacionActual->getImagen(), NULL, pantalla, &offset);
}

void ObjetoJuego::update()
{
	animacionActual->update();
}

void ObjetoJuego::setImagen(const std::string& str, int posicion, Uint32 retardo)
{
	if(animacion==NULL)
	{
		animacion=new Animador;
	}
	SDL_Surface* sur=ci.cargar(str);
	
	if(sur==NULL) printf("Error: %s\n", SDL_GetError());
		
	animacion->setImagen(sur, posicion);
	animacion->setRetardo(retardo, posicion);
	animacionActual=animacion;
}

void ObjetoJuego::setPos(int x, int y)
{
	if(x>0 and y>0)
	{
		posx=x;
		posy=y;
	}
}
