#ifndef PERSONAJE_H
#define PERSONAJE_H

#include "actor.h"

class Personaje : public Actor
{
public:
	Personaje();
	
	void input(SDL_Event& event);


};

#endif
