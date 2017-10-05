/*
 * main.c
 *
 * this is the main blinky application (this code is dependent on the
 * extra shu libraries such as the pinmappings list and the clock configuration
 * library)
 *
 * author:    Dr. Alex Shenfield
 * date:      01/09/2017
 * purpose:   55-604481 embedded computer networks : lab 101
 */

// include the hal drivers
#include "stm32f7xx_hal.h"

// include the shu bsp libraries for the stm32f7 discovery board
#include "pinmappings.h"
#include "clock.h"
#include "gpio.h"
#include "random_numbers.h"

// Map 6 LEDs
gpio_pin_t led1 = {PI_1, GPIOI, GPIO_PIN_1};
gpio_pin_t led2 = {PB_14, GPIOB, GPIO_PIN_14};
gpio_pin_t led3 = {PB_15, GPIOB, GPIO_PIN_15};
gpio_pin_t led4 = {PI_0, GPIOI, GPIO_PIN_0};
gpio_pin_t led5 = {PB_8, GPIOB, GPIO_PIN_8};
gpio_pin_t led6 = {PB_9, GPIOB, GPIO_PIN_9};



// this is the main method
int main()
{
  // we need to initialise the hal library and set up the SystemCoreClock 
  // properly
  HAL_Init();
  init_sysclk_216MHz();
	init_random();
  
  // initialise the gpio pins
  init_gpio(led1, OUTPUT);
	init_gpio(led2, OUTPUT);
	init_gpio(led3, OUTPUT);
	init_gpio(led4, OUTPUT);
	init_gpio(led5, OUTPUT);
	init_gpio(led6, OUTPUT);

	
  // loop forever ...
  while(1)
  {

			write_gpio(led1, LOW);
			write_gpio(led2, LOW);
			write_gpio(led3, LOW);
			write_gpio(led4, LOW);
			write_gpio(led5, LOW);
			write_gpio(led6, LOW);
			
			uint32_t rnd = (get_random_int() % 6) + 1;
				if (rnd==1)
				{
				 write_gpio(led1, HIGH);
				}
				else if (rnd==2)
				{
				 write_gpio(led2, HIGH);
				}
				else if (rnd==3)
				{
				 write_gpio(led3, HIGH);
				}
				else if (rnd==4)
				{
				 write_gpio(led4, HIGH);
				}
				else if (rnd==5)
				{
				 write_gpio(led5, HIGH);
				}
				else
				{
				 write_gpio(led6, HIGH);
				}
		
		 HAL_Delay(5000);
		
		
  }
}
