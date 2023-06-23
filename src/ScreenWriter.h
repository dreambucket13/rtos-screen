/*
 * ScreenWriter.h
 *
 * Blink an LED this class owns and a shared one together
 *
 *  Created on: 17 Aug 2022
 *      Author: jondurrant
 */

#ifndef ScreenWriter_H_
#define ScreenWriter_H_

#include "Screen.h"
#include "Agent.h"

class ScreenWriter : public Agent{
public:
	/***
	 * Constructor
	 * @param gp - GPIO Pad number for LED
	 */
	ScreenWriter(Screen *shared=NULL, std::string text_to_display="Default");

	/***
	 * Destructor
	 */
	virtual ~ScreenWriter();


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

	Screen *pSharedScreen = NULL;
	std::string text_to_display;

};


#endif /* ScreenWriter_H_ */
