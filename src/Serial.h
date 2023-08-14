/*
 * Serial.h
 *
 */

#ifndef SERIAL_H_
#define SERIAL_H_

#include <string>

#include "pico/stdlib.h"
#include "FreeRTOS.h"
#include "task.h"
#include "semphr.h"



class Serial {
public:
	/***
	 * Constructor
	 * 
	 */
	Serial();

	/***
	 * Destructor
	 */
    ~Serial();

	bool WriteToSerial(std::string input);

protected:

	SemaphoreHandle_t xSem = NULL;

};


#endif /* SERIAL_H_ */
