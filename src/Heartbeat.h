/*
 * Heartbeat.h
 *
 * Active agent to run as task and blink and LED on the given GPIO pad
 *
 *  Created on: 15 Aug 2022
 *      Author: jondurrant
 */

#ifndef Heartbeat_H_
#define Heartbeat_H_

#include "pico/stdlib.h"
#include "FreeRTOS.h"
#include "task.h"
#include "hardware/gpio.h"

#include "Agent.h"


class Heartbeat: public Agent {
public:
	/***
	 * Constructor
	 * @param gp - GPIO Pad number for LED
	 */
	Heartbeat(uint8_t gp=0);

	/***
	 * Destructor
	 */
	virtual ~Heartbeat();


protected:

	/***
	 * Run loop for the agent.
	 */
	virtual void run();


	/***
	 * Get the static depth required in words
	 * @return - words
	 */
	virtual configSTACK_DEPTH_TYPE getMaxStackSize();

	//ISR
	static void ButtonISR(uint gpio, uint32_t events);

	//GPIO PAD for LED
	uint8_t xLedPad = 0;

};


#endif /* Heartbeat_H_ */
