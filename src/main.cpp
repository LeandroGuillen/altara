#include "juego.h"


int main ( int argc, char *argv[] ) {
	bool quit=false;
	
	SDL_Event event;
	
	Juego* juego=new Juego;
	
	while ( quit == false )
	{
		while ( SDL_PollEvent( &event ) )
		{
			// PROCESA TECLAS
			if ( event.type == SDL_KEYDOWN )
			{
				if ( event.key.keysym.sym == SDLK_q )	quit=true;
			}
			if ( event.type == SDL_QUIT )
			{
				quit = true;
			}
			juego->tratarInput(event);
		}
		juego->actualizarMundo();
		juego->dibujarMundo();
	}
	delete juego;
	
	return 0;
}

