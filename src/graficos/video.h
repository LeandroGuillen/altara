#ifndef VIDEO_H_
#define VIDEO_H_

#include "global.h"

class Video {
private:
	SDL_Surface* pantalla;
	static const int PANTALLA_ANCHO = 800;
	static const int PANTALLA_ALTO = 600;
	static const int BPP = 32;
	

public:
	Video();
	~Video();
	void aplicarImagen( int x, int y, SDL_Surface* imagen );
	void refrescarPantalla();
	SDL_Surface* getPantalla(){ return pantalla; };

	int FRAMES_PER_SECOND(){ return 40; };
};

#endif //VIDEO_H_

