/*
 * printfWriter.cpp
 *
 *  Created on: 17 Aug 2022
 *      Author: jondurrant
 */

#include "printfWriter.h"
#include <stdio.h>

#define DELAY 5000

printfWriter::printfWriter(Serial *SharedSerialPort, std::string text_to_display): Agent() {
	this->text_to_display = text_to_display;
	this->SharedSerialPort = SharedSerialPort;
}

printfWriter::~printfWriter() {
	// NOP
}

/***
* Main Run Task for agent
*/
void printfWriter::run(){

	printf("Screen Writer Started from %s\n",text_to_display.c_str());

	while (true) { // Loop forever

		if (SharedSerialPort != NULL){
			
			while (SharedSerialPort->WriteToSerial(text_to_display) == false){
				//Keep checking
			}

			vTaskDelay (1000 / portTICK_RATE_MS);
		}

	}

}

/***
 * Get the static depth required in words
 * @return - words
 */
configSTACK_DEPTH_TYPE printfWriter::getMaxStackSize(){
	return 150;
}


