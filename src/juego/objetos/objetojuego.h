#ifndef OBJETO_H
#define OBJETO_H

#include "global.h"
#include "animador.h"
#include "cargadorimagenes.h"

/* ObjetoJuego
 * Esta clase contiene todos los objetos que hay en la pantalla y que
 * se pueden dibujar: NPCs, jugador, armas, powerups, etc...
 * FUNCIONALIDADES:
 * 	- Dibujar objeto (con animaciones)
 * 	- Posicion
 * 	- Identificador unico para cada objeto del juego
 * */

class ObjetoJuego
{
public:
	ObjetoJuego();
	~ObjetoJuego();
	void pintar(SDL_Surface* pantalla);
	void update();
	// Posicion=200 para que se añadan por el final
	void setImagen(const std::string& str, int posicion=200, Uint32 retardo=200);
	int getId() { return myId; }
	void setPos(int x, int y);

protected:
	Animador* animacionActual;
	Animador* animacion; 
	
	// Tiene mas de una animacion?
	bool tieneAnimacion;
	
	// Contiene todas las imagenes para la calse ObjetoJuego
	static CargadorImagenes ci;
	
	static int id;
	
	int myId;
	int posx, posy;
};
#endif
