#ifndef CARGADOR_IMAGENES_H
#define CARGADOR_IMAGENES_H

#include "global.h"

class CargadorImagenes {
public:
	CargadorImagenes();
	~CargadorImagenes();

	SDL_Surface* cargar(const std::string& nombre);
	void quitar(const std::string& nombre);

protected:
	std::map<std::string, SDL_Surface*> imagenes;
};

#endif
