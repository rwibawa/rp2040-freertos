#include <stdio.h>

#include "pico/stdlib.h"
#include "hardware/gpio.h"

#include "FreeRTOS.h"
#include "FreeRTOSConfig.h"
#include "task.h"

#define GREEN_LED 15
#define RED_LED 16

#define GPIO_ON   1
#define GPIO_OFF  0

void GreenLEDTask(void *param)
{
  while (true)
  {
    gpio_put(GREEN_LED, GPIO_ON);
    vTaskDelay(1000);
    gpio_put(GREEN_LED, GPIO_OFF);
    vTaskDelay(1000);
  }
}

void RedLEDTask(void *param)
{
  while (true)
  {
    gpio_put(RED_LED, GPIO_ON);
    vTaskDelay(1000);
    gpio_put(RED_LED, GPIO_OFF);
    vTaskDelay(1000);
  }
}

int main()
{
  stdio_init_all();

  gpio_init(GREEN_LED);
  gpio_set_dir(GREEN_LED, GPIO_OUT);

  gpio_init(RED_LED);
  gpio_set_dir(RED_LED, GPIO_OUT);

  TaskHandle_t gLEDtask = NULL;
  TaskHandle_t rLEDtask = NULL;

  uint32_t status = xTaskCreate(
    GreenLEDTask,
    "Green LED",
    1024,             // size of the stack
    NULL,             // pointer to the argument
    tskIDLE_PRIORITY, // low priority - only execute it when nothing to do
    &gLEDtask
  );

  status = xTaskCreate(
    RedLEDTask,
    "Red LED",
    1024,             // size of the stack
    NULL,             // pointer to the argument
    1,                // priority 1
    &rLEDtask
  );

  vTaskStartScheduler();

  for ( ;; )
  {
    // should never get here
  }
}