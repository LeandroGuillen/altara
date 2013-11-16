#ifndef CRONOMETRO_H
#define CRONOMETRO_H

#include "global.h"

class Cronometro{
public:
private:
	//The clock time when the timer started
	int startTicks;
	//The ticks stored when the timer was paused
	int pausedTicks;
	//The timer status
	bool paused;
	bool started;
public:
	//Initializes variables
	Cronometro();

	//The various clock actions
	void start();
	void stop();
	void pause();
	void unpause();

	//Gets the timer's time
	int get_ticks();

	//Checks the status of the timer
	bool is_started();
	bool is_paused();
};

#endif
