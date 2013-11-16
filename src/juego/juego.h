#ifndef JUEGO_H
#define JUEGO_H

#include "global.h"
#include "video.h"
#include "util.h"
#include "actor.h"
#include "personaje.h"

class Juego {
public:
	Juego();
	~Juego();

	void tratarInput(SDL_Event&);
	void actualizarMundo();
	void dibujarMundo();
	// Inserta un objeto en la lista para pintar, actualiza, ...
	void insertarObjeto(ObjetoJuego* a);
	void insertarActor(Actor* a);

private:
	void dibujarObjetos();
	void FPS();
	void init();

	Video video;
	SDL_Surface *seconds;
	Cronometro *crono;
	bool mostrarFPS;

	typedef std::map<int, ObjetoJuego*> MapaObjetos;
	typedef std::map<int, Actor*> MapaActores;

	MapaObjetos objetos;
	MapaActores actores;

	Personaje* pj;
	//Enemigo* en;
	TTF_Font *fuentePrincipal;
};

#endif
