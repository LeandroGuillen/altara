#ifndef ANIMADOR_H
#define ANIMADOR_H

#include "global.h"

class Animador
{
private:
	std::vector<SDL_Surface*> imagenes;
	std::vector<Uint32> retardos;

	int marcoActual;

	Uint32 ultimoTiempo;

	bool pausado;
	int repeticiones;

public:
	Animador();
	~Animador();

	int numAnimaciones(){ return imagenes.size(); };

	void update();
	void pause();
	void resume();
	void reset();
	void saltarAlMarco (int marco);

	void setRepeticiones (int Repeticiones);
	void setImagen(SDL_Surface* img, int posicion);
	void setRetardo(Uint32 retardo, int posicion);

	SDL_Surface* getImagen();
};

#endif
