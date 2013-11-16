#include "personaje.h"

Personaje::Personaje()
 : Actor()
{
	
}

void Personaje::input(SDL_Event& event)
{
	// Tecla pulsada
	if ( event.type == SDL_KEYDOWN )
	{
		switch ( event.key.keysym.sym )
		{
		case SDLK_UP:
			vy = -velocidad;
			break;
		case SDLK_DOWN:
			vy = velocidad;
			break;
		case SDLK_LEFT:
			vx = -velocidad;
			break;
		case SDLK_RIGHT:
			vx = velocidad;
			break;
		default:;
		}
	}
	// Tecla soltada
	else if ( event.type == SDL_KEYUP )
	{
		switch ( event.key.keysym.sym )
		{
		case SDLK_UP:
			vy = 0;
			break;
		case SDLK_DOWN:
			vy = 0;
			break;
		case SDLK_LEFT:
			vx = 0;
			break;
		case SDLK_RIGHT:
			vx = 0;
			break;
		default:;
		}
	}
}

