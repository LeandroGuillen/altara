#ifndef ACTOR_H
#define ACTOR_H

#include "objetojuego.h"

/* 5 animaciones:
 * 0	Parado
 * 1	Izquierda
 * 2	Derecha
 * 3	Arriba
 * 4	Abajo */	
enum TipoAnim
{	TA_IZQ=0,
	TA_DER,
	TA_ARR,
	TA_ABA,
	NUM_TA
};

typedef std::map<TipoAnim, Animador*> TipoAnimaciones;

/* Actor
 * Esta clase la componen los objetos que necesiten actuar de
 * cualquier forma.
 * FUNCIONALIDADES:
 * 	- Velocidad
 * 	- Velocidad maxima
 * 	- Ataque
 * 	- Mas acciones...
 * */

class Actor : public ObjetoJuego
{
public:
	Actor();
	~Actor();
	
	int getvx();
	int getvy();
	int getVelocidad();
	
	void setvx(int v);
	void setvy(int v);
	void setVelocidad(int v);
	
	void setImagenAnim(const std::string& str, TipoAnim t, int posicion=200, Uint32 retardo=200);
	
	void update();
	
protected:
	int vx, vy, velocidad;
	
private:
	TipoAnimaciones animaciones;
	//Animacion* 
	TipoAnim ultimaDireccion;
};
#endif
