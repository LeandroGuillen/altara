#include "cargadorimagenes.h"

CargadorImagenes::CargadorImagenes(){
	
}

CargadorImagenes::~CargadorImagenes(){
	imagenes.clear();
}

SDL_Surface* CargadorImagenes::cargar(const std::string& nombre ){
	SDL_Surface* imagenCargada = NULL;
	SDL_Surface* imagenOptimizada = NULL;
	std::string archivo=std::string(DIR_IMAGENES)+nombre;
	
	std::map<std::string, SDL_Surface*>::iterator it=imagenes.find(archivo);
	
	if(it==imagenes.end())
	{
		imagenCargada=IMG_Load(archivo.c_str());
		if(imagenCargada!=NULL)
		{
			imagenOptimizada = SDL_DisplayFormatAlpha(imagenCargada);
			SDL_FreeSurface(imagenCargada);
			
			imagenes[archivo]=imagenOptimizada;
		}
		else
		{
			return NULL;
		}
	}
	return imagenes.find(archivo)->second;
}

void CargadorImagenes::quitar(const std::string& nombre)
{
	imagenes.erase(nombre);
}

