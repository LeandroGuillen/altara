#include "juego.h"

Juego::Juego()
{	
	init();

	// *************** Crea un personaje principal
	pj=new Personaje;
	pj->setImagen("personaje/leopar0.png", 0, 2500);
	pj->setImagen("personaje/leopar1.png", 1, 75);
	pj->setImagen("personaje/leopar2.png", 2, 20);
	pj->setImagen("personaje/leopar1.png", 3, 75);
	
	pj->setImagenAnim("personaje/leoizq0.png", TA_IZQ, 0, 200);
	pj->setImagenAnim("personaje/leopar0.png", TA_IZQ, 1, 200);
	pj->setImagenAnim("personaje/leoizq1.png", TA_IZQ, 2, 200);
	pj->setImagenAnim("personaje/leopar0.png", TA_IZQ, 3, 200);
	
	pj->setImagenAnim("personaje/leoder1.png", TA_DER, 0, 200);
	pj->setImagenAnim("personaje/leoder0.png", TA_DER, 1, 200);
	pj->setImagenAnim("personaje/leoder2.png", TA_DER, 2, 200);
	pj->setImagenAnim("personaje/leoder0.png", TA_DER, 3, 200);
	
	// Animaciones: abajo=izquierda, arriba=derecha
	pj->setImagenAnim("personaje/leoizq0.png", TA_ABA, 0, 200);
	pj->setImagenAnim("personaje/leopar0.png", TA_ABA, 1, 200);
	pj->setImagenAnim("personaje/leoizq1.png", TA_ABA, 2, 200);
	pj->setImagenAnim("personaje/leopar0.png", TA_ABA, 3, 200);
	
	pj->setImagenAnim("personaje/leoder1.png", TA_ARR, 0, 200);
	pj->setImagenAnim("personaje/leoder0.png", TA_ARR, 1, 200);
	pj->setImagenAnim("personaje/leoder2.png", TA_ARR, 2, 200);
	pj->setImagenAnim("personaje/leoder0.png", TA_ARR, 3, 200);
	
	pj->setPos(200, 200);
	insertarActor(pj);
	// *************** Fin Creacion Personaje

	
	// Creacion de Kidan
	Personaje* kid=new Personaje;
	kid->setImagen("personaje/kidpar0.png");
	
	int n=0;
	kid->setImagenAnim("personaje/kidizq0.png", TA_IZQ, n++, 60);
	kid->setImagenAnim("personaje/kidizq0b.png", TA_IZQ, n++, 60);
	kid->setImagenAnim("personaje/kidizq1.png", TA_IZQ, n++, 60);
	kid->setImagenAnim("personaje/kidizq1b.png", TA_IZQ, n++, 60);
	kid->setImagenAnim("personaje/kidizq2.png", TA_IZQ, n++, 60);
	kid->setImagenAnim("personaje/kidizq1b.png", TA_IZQ, n++, 60);
	kid->setImagenAnim("personaje/kidizq1.png", TA_IZQ, n++, 60);
	
	n=0;
	kid->setImagenAnim("personaje/kidder0.png", TA_DER, n++, 60);
	kid->setImagenAnim("personaje/kidder0b.png", TA_DER, n++, 60);
	kid->setImagenAnim("personaje/kidder1.png", TA_DER, n++, 60);
	kid->setImagenAnim("personaje/kidder1b.png", TA_DER, n++, 60);
	kid->setImagenAnim("personaje/kidder2.png", TA_DER, n++, 60);
	kid->setImagenAnim("personaje/kidder1b.png", TA_DER, n++, 60);
	kid->setImagenAnim("personaje/kidder1.png", TA_DER, n++, 60);
	
	n=0;
	kid->setImagenAnim("personaje/kidaba0.png", TA_ABA, n++, 60);
	kid->setImagenAnim("personaje/kidaba0b.png", TA_ABA, n++, 60);
	kid->setImagenAnim("personaje/kidaba1.png", TA_ABA, n++, 60);
	kid->setImagenAnim("personaje/kidaba1b.png", TA_ABA, n++, 60);
	kid->setImagenAnim("personaje/kidaba2.png", TA_ABA, n++, 60);
	kid->setImagenAnim("personaje/kidaba1b.png", TA_ABA, n++, 60);
	kid->setImagenAnim("personaje/kidaba1.png", TA_ABA, n++, 60);
	
	n=0;
	kid->setImagenAnim("personaje/kidarr0.png", TA_ARR, n++, 60);
	kid->setImagenAnim("personaje/kidarr0b.png", TA_ARR, n++, 60);
	kid->setImagenAnim("personaje/kidarr1.png", TA_ARR, n++, 60);
	kid->setImagenAnim("personaje/kidarr1b.png", TA_ARR, n++, 60);
	kid->setImagenAnim("personaje/kidarr2.png", TA_ARR, n++, 60);
	kid->setImagenAnim("personaje/kidarr1b.png", TA_ARR, n++, 60);
	kid->setImagenAnim("personaje/kidarr1.png", TA_ARR, n++, 60);
	
	kid->setPos(500, 200);
	insertarActor(kid);
	
	pj=kid;
	
	// Fin creacion de Kidan
	
	
	// Ejemplo de como crear un objeto
	ObjetoJuego* tesoro=new ObjetoJuego;
	tesoro->setImagen("objetos/tesoro.png");
	tesoro->setPos(100, 200);
	insertarObjeto(tesoro);
	
}
Juego::~Juego()
{
	MapaObjetos::iterator i;
	for(i=objetos.begin(); i!=objetos.end(); i++)
	{
		delete (*i).second;
	}
	objetos.clear();
	
	TTF_CloseFont(fuentePrincipal);
}

void Juego::tratarInput(SDL_Event& event)
{
	pj->input(event);
}

void Juego::actualizarMundo()
{
	crono->start();
	MapaActores::iterator i;
	for(i=actores.begin(); i!=actores.end(); i++)
	{
		(*i).second->update();
	}
}
void Juego::dibujarMundo()
{
	// dibujarMapa();
	dibujarObjetos();
	// dibujarInterfaz();
	video.refrescarPantalla();
	FPS();
}
void Juego::FPS()
{
	// Calcula los FPS
	if(crono->get_ticks() < 1000 / video.FRAMES_PER_SECOND())
	{
		//Sleep the remaining frame time
		SDL_Delay( ( 1000 / video.FRAMES_PER_SECOND() ) - crono->get_ticks() );
	}
	if(mostrarFPS)
	{
		SDL_Color textColor = { 0x00, 0x00, 0x00 };
		
		// Muestra los FPS en la esquina inferior izquierda de la pantalla
		std::stringstream time;
		time << "FPS: " << 1000/crono->get_ticks() << "  Q para salir";
		seconds = TTF_RenderText_Solid( fuentePrincipal, time.str().c_str(), textColor );
		video.aplicarImagen(10, 570, seconds);
		SDL_FreeSurface( seconds );
		
	}
}
void Juego::insertarObjeto(ObjetoJuego *a)
{
	if(a!=NULL)
	{
		objetos[a->getId()]=a;
	}
}
void Juego::insertarActor(Actor* a)
{
	if(a!=NULL)
	{
		actores[a->getId()]=a;
	}
	insertarObjeto(a);
}

void Juego::dibujarObjetos()
{
	if(not objetos.empty())
	{
		MapaObjetos::iterator i;
		for(i=objetos.begin(); i!=objetos.end(); i++)
		{
			(*i).second->pintar(video.getPantalla());
		}
	}
}
void Juego::init()
{
	// Establece la fuente del programa
	fuentePrincipal=TTF_OpenFont("recursos/fuentes/lazy.ttf", 16 );
	// Inicializar valores
	crono=new Cronometro;
	mostrarFPS=true;	
}



