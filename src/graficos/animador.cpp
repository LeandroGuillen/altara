#include "animador.h"

Animador::Animador(){
	marcoActual = 0;
	ultimoTiempo = SDL_GetTicks();
	pausado = false;
	repeticiones = -1;
}
Animador::~Animador(){}

void Animador::update(){
	// Si la animacion esta pausada no hace nada
	if(pausado) return;

	// Comprueba si ha pasado suficiente tiempo para pasar
	// al siguiente marco
	if( retardos[marcoActual] < (SDL_GetTicks() - ultimoTiempo) )
	{
		marcoActual++;
		ultimoTiempo = SDL_GetTicks();

		// Si hemos llegado al final
		if(marcoActual >= imagenes.size())
		{
			// Si no es bucle infinito disminuir las repeticiones
			if( repeticiones != -1 )
			{
				// Si no quedan repeticiones pausar la animacion
				if( repeticiones == 0)
					pausado = true;
				else
					repeticiones--;
			}
			marcoActual= 0;
		}
	}
}
void Animador::pause(){ pausado=true; }
void Animador::resume(){ pausado=false; ultimoTiempo = SDL_GetTicks(); }
void Animador::reset(){ marcoActual=0; ultimoTiempo = SDL_GetTicks(); }
void Animador::saltarAlMarco (int marco){
	// Solo si el marco existe
	if(marco< imagenes.size())
		marcoActual = marco;
	ultimoTiempo = SDL_GetTicks();
}

void Animador::setRepeticiones(int Repeticiones){ repeticiones=Repeticiones; }
void Animador::setImagen(SDL_Surface* img, int posicion){
	// Si la posicion no existe, la insertamos al final
	if(posicion >= imagenes.size())
	{
		imagenes.push_back(img);
		retardos.push_back(100);
	}
	// Y si no la coloca en su lugar
	else
		imagenes[posicion] = img;
}

void Animador::setRetardo(Uint32 retardo, int posicion){
	// Solo pone un retardo para un marco que existe
	if( posicion < retardos.size() )
		retardos[posicion] = retardo;
}

SDL_Surface* Animador::getImagen(){ return imagenes[marcoActual]; }

