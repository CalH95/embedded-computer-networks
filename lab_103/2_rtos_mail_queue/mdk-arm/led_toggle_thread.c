// include cmsis_os for the rtos api
#include "cmsis_os.h"

// include main.h (this is where we initialise the mail type and queue)
#include "main.h"

// include the shu bsp libraries for the stm32f7 discovery board
#include "pinmappings.h"
#include "clock.h"
#include "random_numbers.h"
#include "gpio.h"

// RTOS DEFINES

// declare the thread function prototypes, thread id, and priority
void led_toggle_thread(void const *argument);
osThreadId tid_led_toggle_thread;
osThreadDef(led_toggle_thread, osPriorityNormal, 1, 0);

gpio_pin_t ledToggle = {PI_2, GPIOI, GPIO_PIN_2};


int init_led_toggle_thread(void)
{
	
	
	init_gpio(ledToggle, OUTPUT);
	tid_led_toggle_thread = osThreadCreate(osThread(led_toggle_thread), NULL);

  // check if everything worked ...
  if(!tid_led_toggle_thread)
  {
    return(-1);
  }
  return(0);	
	
	
}

void display_thread(void const *argument)
{
  // infinite loop getting out fake data ...
  while(1)
  {
		toggle_gpio(ledToggle);
	}
	
}