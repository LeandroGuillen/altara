#include "cronometro.h"

Cronometro::Cronometro()
{
	 //Initialize the variables
	startTicks = 0;
	pausedTicks = 0;
	paused = false;
	started = false;
}


void Cronometro::start()
{
    //Start the timer
	started = true;

    //Unpause the timer
	paused = false;

    //Get the current clock time
	startTicks = SDL_GetTicks();
}
void Cronometro::stop()
{
    //Stop the timer
	started = false;

    //Unpause the timer
	paused = false;
}

void Cronometro::pause()
{
    //If the timer is running and isn't already paused
	if( ( started == true ) && ( paused == false ) )
	{
        //Pause the timer
		paused = true;

        //Calculate the paused ticks
		pausedTicks = SDL_GetTicks() - startTicks;
	}
}

void Cronometro::unpause()
{
    //If the timer is paused
	if( paused == true )
	{
        //Unpause the timer
		paused = false;

        //Reset the starting ticks
		startTicks = SDL_GetTicks() - pausedTicks;

        //Reset the paused ticks
		pausedTicks = 0;
	}
}

int Cronometro::get_ticks()
{
    //If the timer is running
	if( started == true )
	{
        //If the timer is paused
		if( paused == true )
		{
            //Return the number of ticks when the timer was paused
			return pausedTicks;
		}
		else
		{
            //Return the current time minus the start time
			return SDL_GetTicks() - startTicks;
		}
	}

    //If the timer isn't running
	return 0;
}

bool Cronometro::is_started()
{
	return started;
}

bool Cronometro::is_paused()
{
	return paused;
}