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

// Map Light 1 LEDs
gpio_pin_t ledr = {PI_1, GPIOI, GPIO_PIN_1};
gpio_pin_t ledo = {PB_14, GPIOB, GPIO_PIN_14};
gpio_pin_t ledg = {PB_15, GPIOB, GPIO_PIN_15};

// Map Light 2 LEDs
gpio_pin_t ledr2 = {PI_0, GPIOI, GPIO_PIN_0};
gpio_pin_t ledo2 = {PB_8, GPIOB, GPIO_PIN_8};
gpio_pin_t ledg2 = {PB_9, GPIOB, GPIO_PIN_9};

// this is the main method
int main()
{
  // we need to initialise the hal library and set up the SystemCoreClock 
  // properly
  HAL_Init();
  init_sysclk_216MHz();
  
  // initialise the gpio pins
  init_gpio(ledr, OUTPUT);
	init_gpio(ledo, OUTPUT);
	init_gpio(ledg, OUTPUT);
	init_gpio(ledr2, OUTPUT);
	init_gpio(ledo2, OUTPUT);
	init_gpio(ledg2, OUTPUT);
  
  // loop forever ...
  while(1)
  {
    // Set 1 R on G and O Off
    write_gpio(ledo, LOW);
		write_gpio(ledr, HIGH);
	  write_gpio(ledg, LOW);
		
		//Set 2 R and O on, G Off
		write_gpio(ledo2,HIGH);
		write_gpio(ledr2, HIGH);
	  write_gpio(ledg2, LOW);
		
    // wait for 10 second
    HAL_Delay(10000);
		
		//Set 2 R and O Off, G On
		write_gpio(ledo2, LOW);
		write_gpio(ledr2, LOW);
	  write_gpio(ledg2, HIGH);
		
		//wait 10 sec
		HAL_Delay(10000);
		
		//Set 2 R and G Off, O On
		write_gpio(ledo2, HIGH);
		write_gpio(ledr2, LOW);
	  write_gpio(ledg2, LOW);	
		
		//wait 10 sec
		HAL_Delay(10000);
		
		//Set 2 O and G Off, R On
		write_gpio(ledo2, LOW);
		write_gpio(ledr2, HIGH);
	  write_gpio(ledg2, LOW);	
		
		// Set O and R On, G Off
		write_gpio(ledo, HIGH);
		write_gpio(ledr, HIGH);
	  write_gpio(ledg, LOW);	
		
		//wait 10 sec
		HAL_Delay(10000);
		
		// Set O and R Off, G On
		write_gpio(ledo, LOW);
		write_gpio(ledr, LOW);
	  write_gpio(ledg, HIGH);	
		
		//wait 10 sec
		HAL_Delay(10000);
		
		// Set G and R Off, O On
		write_gpio(ledo, HIGH);
		write_gpio(ledr, LOW);
	  write_gpio(ledg, LOW);	
		
		//wait 10 sec
		HAL_Delay(10000);
		
  }
}
