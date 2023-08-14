/*
 * Serial.cpp
 *
 *  
 */

#include "Serial.h"

#include "stdio.h"

#include <string.h>
#include <math.h>
#include <vector>
#include <cstdlib>
#include <iostream>


//Serial Delay
#define DELAY			portTICK_PERIOD_MS(3000) 



/***
 * Constructor
 * 
 */
Serial::Serial() {

    xSem = xSemaphoreCreateBinary( );
	if (xSem == NULL){
		printf("ERROR could not create semaphore\n");
	} else {
		BaseType_t semaphoreStatus = xSemaphoreGive(xSem);
		if (semaphoreStatus == pdFALSE){
			printf("Failed to give semaphore\n");
		}
	}

}

/***
 * Destructor
 */
Serial::~Serial() {

}



 bool Serial::WriteToSerial(std::string text_to_display){

	if (xSemaphoreTake(xSem, 0) == pdTRUE){
		
		printf("Printing from %s\n", text_to_display.c_str());

		vTaskDelay(500 / portTICK_PERIOD_MS);

		xSemaphoreGive(xSem);

		return true;

	}

	return false;
 }
