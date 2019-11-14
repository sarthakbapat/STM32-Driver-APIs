#include "stm32f446xx_gpio_driver.h"

#define BUTTON_PRESSED			0						// For Nucleo board it works in inverted logic.

void delay_()
{
	uint32_t i;
	for (i=0;i<500000;i++);
}

int main ()
{
	GPIO_handler_t han_led, han_but;
	GPIO_handler_t *handle = &han_led;					//Pointer for GPIO_handler_t structure for LED handling
	GPIO_handler_t *handle_button = &han_but;		//Pointer for GPIO_handler_t structure for button handling.
	
	handle->pGPIO = GPIOA;
	handle->GPIO_PinConfig.GPIO_PinMode = GPIO_MODE_OUT;
	handle->GPIO_PinConfig.GPIO_PinNumber = GPIO_PIN_5;
	handle->GPIO_PinConfig.GPIO_PinOPType = GPIO_OP_TYP_PP;
	handle->GPIO_PinConfig.GPIO_PinPuPdControl = GPIO_PUPD_NO;
	handle->GPIO_PinConfig.GPIO_PinSpeed = GPIO_OP_SPEED_FAST;
	
	handle_button->pGPIO = GPIOC;
	handle_button->GPIO_PinConfig.GPIO_PinMode = GPIO_MODE_IN;
	handle_button->GPIO_PinConfig.GPIO_PinNumber = GPIO_PIN_13;
	handle_button->GPIO_PinConfig.GPIO_PinPuPdControl = GPIO_PUPD_NO;
	handle_button->GPIO_PinConfig.GPIO_PinSpeed = GPIO_OP_SPEED_FAST;
	
	//Configure all the necessary things for on board LED.
	/*
	handle.pGPIO = GPIOA;
	handle.GPIO_PinConfig.GPIO_PinMode = GPIO_MODE_OUT;
	handle.GPIO_PinConfig.GPIO_PinNumber = GPIO_PIN_5;
	handle.GPIO_PinConfig.GPIO_PinOPType = GPIO_OP_TYP_PP;
	handle.GPIO_PinConfig.GPIO_PinPuPdControl = GPIO_PUPD_NO;
	handle.GPIO_PinConfig.GPIO_PinSpeed = GPIO_OP_SPEED_FAST; */
	
	GPIO_Pclk_control (GPIOA, ENABLE);				//Enable the peripheral clock for GPIO.
	GPIO_Pclk_control (GPIOC, ENABLE);
	GPIO_init(handle);												//Pass the pointer of the structure variable.
	GPIO_init (handle_button);
	
	while (1)
	{
		if (GPIO_ReadFromPin(GPIOC, GPIO_PIN_13) == BUTTON_PRESSED)
		{	
			delay_();															// Delay to avoid debouncing effect of the button.
			GPIO_TogglePin(GPIOA, GPIO_PIN_5);
			delay_();
		}
		else
		{
			GPIO_WriteToPin (GPIOA, GPIO_PIN_5, 0);
		}	
	
	}
	
	return 0;
}
