/*
 * main.c
 *
 * this is the main lcd application
 *
 * author:    Dr. Alex Shenfield
 * date:      04/09/2017
 * purpose:   55-604481 embedded computer networks : lab 102
 */

// include the basic headers and hal drivers
#include "stm32f7xx_hal.h"

// include the shu bsp libraries for the stm32f7 discovery board
#include "pinmappings.h"
#include "clock.h"
#include "stm32746g_discovery_lcd.h"
#include "adc.h"
#include "gpio.h"

gpio_pin_t pot = {PF_8, GPIOF, GPIO_PIN_8};

//test
// LCD DEFINES

// define a message boarder (note the lcd is 28 characters wide using Font24)
#define BOARDER     "****************************"

// specify a welcome message
const char * welcome_message[2] = 
{
  "*     Hello LCD World!     *",
  "*      Welcome to SHU      *"
};

// CODE

// this is the main method
int main()
{
  // we need to initialise the hal library and set up the SystemCoreClock 
  // properly
  HAL_Init();
  init_sysclk_216MHz();
	init_adc(pot);
  
  // initialise the lcd
  BSP_LCD_Init();
  BSP_LCD_LayerDefaultInit(LTDC_ACTIVE_LAYER, SDRAM_DEVICE_ADDR);
  BSP_LCD_SelectLayer(LTDC_ACTIVE_LAYER);

  // set the background colour to blue and clear the lcd
  BSP_LCD_SetBackColor(LCD_COLOR_BLUE);
  BSP_LCD_Clear(LCD_COLOR_BLUE);
  
  // set the font to use
  BSP_LCD_SetFont(&Font24); 
	
	// Bar Stuff
	
	
  
  // print the welcome message ...
  BSP_LCD_SetTextColor(LCD_COLOR_WHITE);
  BSP_LCD_DisplayStringAtLine(0, (uint8_t *)BOARDER);
  BSP_LCD_DisplayStringAtLine(1, (uint8_t *)welcome_message[0]);
  BSP_LCD_DisplayStringAtLine(2, (uint8_t *)welcome_message[1]);
  BSP_LCD_DisplayStringAtLine(3, (uint8_t *)BOARDER); 
    
  // delay a little ...
  HAL_Delay(5000);
  

  while(1)
  {
		BSP_LCD_Clear(LCD_COLOR_BLUE);
		BSP_LCD_DisplayStringAtLine(0, (uint8_t *)BOARDER);
		BSP_LCD_DisplayStringAtLine(1, (uint8_t *)welcome_message[0]);
		BSP_LCD_DisplayStringAtLine(2, (uint8_t *)welcome_message[1]);
		BSP_LCD_DisplayStringAtLine(3, (uint8_t *)BOARDER); 
		
		uint16_t adc_val = read_adc(pot);
		adc_val = (adc_val-20)/40;
		
		
    // format a string based around the uptime counter
    char str[20];
    sprintf(str, "%d Percent", adc_val);
    
    // print the message to the lcd
    BSP_LCD_ClearStringLine(6);
    BSP_LCD_DisplayStringAtLine(6, (uint8_t *)str);
		
		BSP_LCD_FillRect(20, 220, (adc_val*4.3), 30);
		
		
    HAL_Delay(1000);
  }
}
