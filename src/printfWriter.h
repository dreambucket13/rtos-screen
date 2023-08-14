/*
 * printfWriter.h
 *
 * Just prints to serial
 *
 */

#ifndef printfWriter_H_
#define printfWriter_H_

#include "Serial.h"
#include "Agent.h"

class printfWriter : public Agent{
public:
	/***
	 * Constructor
	 * @param gp - GPIO Pad number for LED
	 */
	printfWriter(Serial *SerialPort = NULL, std::string text_to_display="Default");

	/***
	 * Destructor
	 */
	virtual ~printfWriter();


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

	std::string text_to_display;
	Serial *SharedSerialPort;
};


#endif /* printfWriter_H_*/
