#include "gpio.h"



void GPIO_Clock_Enable(uint32_t *GPIOx)
{
  assert(GPIOx == GPIOA || GPIOx == GPIOB || GPIOx == GPIOC || GPIOx == GPIOD);
  uint16_t *RCC_AHB1 = (uint16_t *)(0x40023830);
  *RCC_AHB1 = 0x00000000;
  if (GPIOx == GPIOA)
  {
    *RCC_AHB1 |= (1<<0);
  }
  else  if (GPIOx == GPIOB)
  {
    *RCC_AHB1 |= (1<<1);
  }
   else  if (GPIOx == GPIOC)
  {
    *RCC_AHB1 |= (1<<2);
  }
  
   else  if (GPIOx == GPIOD)
  {
    *RCC_AHB1 |= (1<<3);
  }
}
 void GPIO_Config(uint32_t *GPIOx, uint8_t Pin, uint8_t Mode, uint8_t Type)
 {
   uint32_t *GPIOA_MODER = GPIOA;
   uint32_t *GPIOB_MODER = GPIOB;
   uint32_t *GPIOC_MODER = GPIOC;
   uint32_t *GPIOD_MODER = GPIOD;
   uint16_t *GPIOA_OTYPER = (uint16_t *)(GPIOA + 0x04 );
   uint16_t *GPIOB_OTYPER = (uint16_t *)(GPIOB + 0x04 );
   uint16_t *GPIOC_OTYPER = (uint16_t *)(GPIOC + 0x04 );
   uint16_t *GPIOD_OTYPER = (uint16_t *)(GPIOD + 0x04 );
   assert(GPIOx == GPIOA || GPIOx == GPIOB || GPIOx == GPIOC || GPIOx == GPIOD);
   assert(Pin == PIN0 || Pin == PIN1 || Pin == PIN2 || Pin == PIN3 || Pin == PIN4 || Pin == PIN5  
   || Pin == PIN6 || Pin == PIN7 || Pin == PIN8 || Pin == PIN9 || Pin == PIN10 || Pin == PIN11
   || Pin == PIN12 || Pin == PIN13 || Pin == PIN14 || Pin == PIN15);
   assert(Mode == INPUT || Mode == OUTPUT ||Mode == ALTERNATE ||Mode == ANALOG_INPUT);
   assert(Type == OUTPUT_PUSH_PULL || Type == OUTPUT_OPEN_DRAIN);
   *GPIOA_MODER = 0x00000000;
   *GPIOA_OTYPER = 0x00000000;
   *GPIOB_MODER = 0x00000000;
   *GPIOB_OTYPER = 0x00000000;
   *GPIOC_MODER = 0x00000000;
   *GPIOC_OTYPER = 0x00000000;
   *GPIOD_MODER = 0x00000000;
   *GPIOD_OTYPER = 0x00000000;
   if (GPIOx == GPIOA)
  {
    *GPIOA_MODER |= (Mode<< Pin*2 );
    *GPIOA_OTYPER |= (Type << Pin);
  }
  else  if (GPIOx == GPIOB)
  {
    *GPIOB_MODER |= (Mode<< Pin*2 );
    *GPIOB_OTYPER |= (Type << Pin);
  }
   else  if (GPIOx == GPIOC)
  {
    *GPIOC_MODER |= (Mode<< Pin*2 );
    *GPIOC_OTYPER |= (Type << Pin);
  }
  
   else  if (GPIOx == GPIOD)
  {
    *GPIOD_MODER |= (Mode<< Pin*2 );
    *GPIOD_OTYPER |= (Type << Pin);
  }

 }
 
