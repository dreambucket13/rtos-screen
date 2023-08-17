/*
 * Screen.cpp
 *
 *  
 */

#include "Screen.h"

#include "stdio.h"

//includes from screen demo
#include <string.h>
#include <math.h>
#include <vector>
#include <cstdlib>
#include <iostream>

#include "libraries/pico_display_2/pico_display_2.hpp"
#include "drivers/st7789/st7789.hpp"
#include "libraries/pico_graphics/pico_graphics.hpp"
#include "rgbled.hpp"
#include "button.hpp"


using namespace pimoroni;


//Screen Delay
#define DELAY			portTICK_PERIOD_MS(3000) 

ST7789* st7789;
PicoGraphics_PenRGB332* graphics;

// RGBLED led(PicoDisplay2::LED_R, PicoDisplay2::LED_G, PicoDisplay2::LED_B);

// Button button_a(PicoDisplay2::A);
// Button button_b(PicoDisplay2::B);
// Button button_x(PicoDisplay2::X);
// Button button_y(PicoDisplay2::Y);



/***
 * Constructor
 * 
 */
Screen::Screen() {

    st7789 = new ST7789(320, 240, ROTATE_0, false, get_spi_pins(BG_SPI_FRONT));
    graphics = new PicoGraphics_PenRGB332(st7789->width, st7789->height, nullptr);

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
Screen::~Screen() {

    // delete st7789;
    // delete graphics;

	// if (xSem != NULL){
	// 	vSemaphoreDelete(xSem);
	// }

}



 bool Screen::WriteToScreen(std::string& text_to_display){

	if (xSemaphoreTake(xSem, 0) == pdTRUE){

		Pen BG = graphics->create_pen(120, 40, 60);
		Pen WHITE = graphics->create_pen(255, 255, 255);
		st7789->set_backlight(128);
		graphics->set_pen(BG);
    	graphics->clear();

        Point text_location(0, 0);

        graphics->set_pen(WHITE);
        graphics->text(text_to_display, text_location, 320);

        // update screen
        st7789->update(graphics);

		//limit how often screen updates
		vTaskDelay(500 / portTICK_PERIOD_MS);

		//it's me, hi, i'm the problem it's me
		xSemaphoreGive(xSem);

		return true;

	}

	return false;
 }
