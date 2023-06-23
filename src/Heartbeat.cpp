/*
 * Heartbeat.cpp
 *
 */

#include "Heartbeat.h"

#include "stdio.h"
#include "FreeRTOS.h" 
#include "portmacro.h"

//Blink Delay
#define DELAY			500
#define ISR_DELAY		50



/***
 * Constructor
 * @param gp - GPIO Pad number for LED
 */
Heartbeat::Heartbeat(uint8_t gp) {
	xLedPad = gp;
	//gpio_set_irq_enabled_with_callback(12, GPIO_IRQ_EDGE_RISE | GPIO_IRQ_EDGE_FALL, true, &ButtonISR);
}

/***
 * Destructor
 */
Heartbeat::~Heartbeat() {
	stop();
}


 /***
  * Main Run Task for agent
  */
 void Heartbeat::run(){

	printf("Blink Started\n");

	gpio_init(xLedPad);

	gpio_set_dir(xLedPad, GPIO_OUT);

	while (true) { // Loop forever
		gpio_put(xLedPad, 1);
		vTaskDelay(DELAY);
		gpio_put(xLedPad, 0);
		vTaskDelay(DELAY);

		printf("%s on Core %d\n", pName, getCore());
	}

 }

 void Heartbeat::ButtonISR(uint gpio, uint32_t events){

  BaseType_t xHigherPriorityTaskWoken = pdFALSE;
  
	// for (int i = 0; i < 5; i++){
	// 	gpio_put(0, 1);
	// 	sleep_ms(100);
	// 	gpio_put(0, 0);
	// 	sleep_ms(100);
	// }

	printf("hello from ISR\n");

	portYIELD_FROM_ISR(xHigherPriorityTaskWoken);

 }

/***
 * Get the static depth required in words
 * @return - words
 */
configSTACK_DEPTH_TYPE Heartbeat::getMaxStackSize(){
	return 150;
}
