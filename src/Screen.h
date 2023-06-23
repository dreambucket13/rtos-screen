/*
 * Screen.h
 *
 * Active agent to run as task and blink and LED on the given GPIO pad
 *
 *  Created on: 15 Aug 2022
 *      Author: jondurrant
 */

#ifndef SCREEN_H_
#define SCREEN_H_

#include <string>

#include "pico/stdlib.h"
#include "FreeRTOS.h"
#include "task.h"
#include "semphr.h"



class Screen {
public:
	/***
	 * Constructor
	 * 
	 */
	Screen();

	/***
	 * Destructor
	 */
    ~Screen();

	bool WriteToScreen(std::string input);

protected:

	SemaphoreHandle_t xSem = NULL;

};


#endif /* SCREEN_H_ */
