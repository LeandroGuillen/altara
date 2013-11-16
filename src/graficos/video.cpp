#include "video.h"

Video::Video()
{
	Uint32 flags = SDL_DOUBLEBUF | SDL_SWSURFACE;// | SDL_FULLSCREEN;
	// Load SDL
	if (SDL_Init(SDL_INIT_EVERYTHING) != 0)
	{
		std::cerr << "No se puede iniciar SDL: " << SDL_GetError() << std::endl;
		exit(1);
	}
	atexit(SDL_Quit);
	
	pantalla = SDL_SetVideoMode(PANTALLA_ANCHO, PANTALLA_ALTO, BPP, flags);
	if (pantalla == NULL)
	{
		std::cerr << "No se puede iniciar el modo de video: " << SDL_GetError() << std::endl;
		exit(1);
	}
	SDL_WM_SetCaption( "Altara Testing", NULL );
	TTF_Init();
	
}
Video::~Video()
{
	SDL_FreeSurface(pantalla);
	
	TTF_Quit();
	SDL_Quit();
}

void Video::aplicarImagen( int x, int y, SDL_Surface* imagen )
{
	// Make a temporary rectangle to hold the offsets
	SDL_Rect offset;
	// Give the offsets to the rectangle
	offset.x = x;
	offset.y = y;
	// Blit the surface
	SDL_BlitSurface(imagen, NULL, pantalla, &offset);
}

void Video::refrescarPantalla()
{
	SDL_Flip(pantalla);
	SDL_FillRect(pantalla, &pantalla->clip_rect, SDL_MapRGB(pantalla->format, 0xFF, 0xFF, 0xFF));
}



