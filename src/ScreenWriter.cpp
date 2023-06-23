/*
 * ScreenWriter.cpp
 *
 *  Created on: 17 Aug 2022
 *      Author: jondurrant
 */

#include "ScreenWriter.h"
#include <stdio.h>

#define DELAY 5000

ScreenWriter::ScreenWriter(Screen *shared, std::string text_to_display): Agent() {
	pSharedScreen = shared;
	this->text_to_display = text_to_display;
}

ScreenWriter::~ScreenWriter() {
	// NOP
}

/***
* Main Run Task for agent
*/
void ScreenWriter::run(){

	printf("Screen Writer Started\n");

	while (true) { // Loop forever

		printf("%s on Core %d\n", pName, getCore());
		
		if (pSharedScreen != NULL){
			
			while (pSharedScreen->WriteToScreen(text_to_display) == false){
				//Keep checking
			}
		}

		vTaskDelay(DELAY);
	}

}

/***
 * Get the static depth required in words
 * @return - words
 */
configSTACK_DEPTH_TYPE ScreenWriter::getMaxStackSize(){
	return 150;
}
