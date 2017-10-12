/*
 * main.c
 *
 * this is the main push button application (this code is dependent on the
 * extra shu libraries such as the pinmappings list and the clock configuration
 * library)
 *
 * author:    Alex Shenfield
 * date:      01/09/2017
 * purpose:   55-604481 embedded computer networks : lab 101
 */

// include the hal drivers
#include "stm32f7xx_hal.h"

// include the shu bsp libraries for the stm32f7 discovery board
#include "pinmappings.h"
#include "clock.h"
#include "gpio.h"

// map the led to GPIO PI_1 (the inbuilt led) and the push button to PI_11 
// (the user button)
gpio_pin_t led1 = {PA_15, GPIOA, GPIO_PIN_15};
gpio_pin_t led2 = {PI_1, GPIOI, GPIO_PIN_1};
gpio_pin_t led3 = {PI_2, GPIOI, GPIO_PIN_2};
gpio_pin_t pb1 = {PA_8, GPIOA, GPIO_PIN_8};

int ledCounter = 1;

// this is the main method
int main()
{
  // we need to initialise the hal library and set up the SystemCoreClock 
  // properly
  HAL_Init();
  init_sysclk_216MHz();
  
  // initialise the gpio pins
  init_gpio(led1, OUTPUT);
	init_gpio(led2, OUTPUT);
	init_gpio(led3, OUTPUT);
  init_gpio(pb1, INPUT);
  
  // loop forever ...
  while(1)
  {
    // if the button is pressed ...
    if(read_gpio(pb1))
    {
			//Delay 50
			HAL_Delay(75);
			
			//read again
			if(read_gpio(pb1))
			{
				if(ledCounter==1){
					
				// LED 1 on, counter 2
				write_gpio(led1, HIGH);
				write_gpio(led2, LOW);
				write_gpio(led3, LOW);
				ledCounter=2;
				}
				else if(ledCounter==2){
				write_gpio(led1, LOW);
				write_gpio(led2, HIGH);
				write_gpio(led3, LOW);
				ledCounter=3;	
				}
				else if(ledCounter==3){
				write_gpio(led1, LOW);
				write_gpio(led2, LOW);
				write_gpio(led3, HIGH);
				ledCounter=1;	
				}	
				
			}
		}
  }
}
