#include "stm32f446xx_gpio_driver.h"


/******************APIs supported by this driver*********************************************/

/****************************Init and Deinit*************************************************/

/************************************************************

@Function : GPIO_init

@Description : Initialization of the GPIOx.

@GPIO_handler_t *pGPIO : Takes a pointer of GPIO_Handler_t.

@ReturnType : void

@Note :

*************************************************************/

void GPIO_init(GPIO_handler_t *pGPIOx)
{
	//Non interrupt mode
	uint32_t temp = 0;
	//Configure the mode
	if ((pGPIOx->GPIO_PinConfig.GPIO_PinMode <= 3))
	{
		temp = (pGPIOx->GPIO_PinConfig.GPIO_PinMode << (2*pGPIOx->GPIO_PinConfig.GPIO_PinNumber)); 
		//Multiply by 2 because each pin is represented by 2 bits in MODER register.
		pGPIOx->pGPIO->MODER &= ~(0x3 << pGPIOx->GPIO_PinConfig.GPIO_PinNumber);		//Clearing the required bits.
		pGPIOx->pGPIO->MODER |= temp;							//SET the required bits.
	}
	else
  {
			//Interrupt mode .
	}
	
	temp = 0;
	//Configure the speed
	temp = (pGPIOx->GPIO_PinConfig.GPIO_PinSpeed << (2*pGPIOx->GPIO_PinConfig.GPIO_PinNumber));
	pGPIOx->pGPIO->OSPEEDER &= ~(0x3 << pGPIOx->GPIO_PinConfig.GPIO_PinNumber);
	pGPIOx->pGPIO->OSPEEDER |= temp;
	
	temp = 0;
	//Pull up Pull down settings
	temp = (pGPIOx->GPIO_PinConfig.GPIO_PinPuPdControl << (2*pGPIOx->GPIO_PinConfig.GPIO_PinNumber));
	pGPIOx->pGPIO->PUPDR &= ~(0x3 << pGPIOx->GPIO_PinConfig.GPIO_PinNumber);
	pGPIOx->pGPIO->PUPDR |= temp;
	
	temp = 0;
	//configure the output type.
	temp = (pGPIOx->GPIO_PinConfig.GPIO_PinOPType << pGPIOx->GPIO_PinConfig.GPIO_PinNumber);
	pGPIOx->pGPIO->OTYPER &= ~ (0x1 << pGPIOx->GPIO_PinConfig.GPIO_PinNumber);
	pGPIOx->pGPIO->OTYPER |= temp;
	
	temp = 0;
	//configure alternate functionality.
	if (pGPIOx->GPIO_PinConfig.GPIO_PinMode == GPIO_MODE_ALTFN)
	{
		temp = (pGPIOx->GPIO_PinConfig.GPIO_PinAltFunMode << (4*pGPIOx->GPIO_PinConfig.GPIO_PinNumber));
		if (pGPIOx->GPIO_PinConfig.GPIO_PinNumber <= GPIO_PIN_7)
		{
			pGPIOx->pGPIO->AFRL &= ~(0xF << pGPIOx->GPIO_PinConfig.GPIO_PinNumber);
			pGPIOx->pGPIO->AFRL |= temp;
		}
		else 
		{
			pGPIOx->pGPIO->AFRH &= ~(0xF << pGPIOx->GPIO_PinConfig.GPIO_PinNumber);
			pGPIOx->pGPIO->AFRH |= temp;
		}
	
	}

}


/************************************************************

@Function :GPIO_Deinit

@Description : Deinitialize the GPIOx registers.

@GPIO_RegDef *pGPIO : Takes the base address of GPIOx

@ReturnType : void

@Note :

*************************************************************/

void GPIO_Deinit(GPIO_RegDef *pGPIO)
{
		if (pGPIO == GPIOA)
			GPIOA_REG_RESET();
		else if (pGPIO == GPIOB)
			GPIOB_REG_RESET();
		else if (pGPIO == GPIOC)
			GPIOC_REG_RESET();
		else if (pGPIO == GPIOD)
			GPIOD_REG_RESET();
		else if (pGPIO == GPIOE)
			GPIOE_REG_RESET();
		else if (pGPIO == GPIOF)
			GPIOF_REG_RESET();
		else if (pGPIO == GPIOG)
			GPIOG_REG_RESET();
		else if (pGPIO == GPIOH)
			GPIOH_REG_RESET();
}

/****************************Init and Deinit end*********************************************/

/****************************Peripheral clock control****************************************/

/************************************************************

@Function : GPIO_Pclk_control

@Description : Enables or disables the peripheral clock for a
GPIOx port.

@GPIO_RegDef *pGPIO : Takes the base address of GPIOx port.
@uint8_t EnorDi : Enable or disable macro.

@ReturnType : void

@Note :

*************************************************************/

void GPIO_Pclk_control(GPIO_RegDef *pGPIO, uint8_t EnorDi)
{
	if (EnorDi == ENABLE)
	{
		if (pGPIO == GPIOA)
			GPIOA_PCLK_EN;
		else if (pGPIO == GPIOB)
			GPIOB_PCLK_EN;
		else if (pGPIO == GPIOC)
			GPIOC_PCLK_EN;
		else if (pGPIO == GPIOD)
			GPIOD_PCLK_EN;
		else if (pGPIO == GPIOE)
			GPIOE_PCLK_EN;
		else if (pGPIO == GPIOF)
			GPIOF_PCLK_EN;
		else if (pGPIO == GPIOG)
			GPIOG_PCLK_EN;
		else if (pGPIO == GPIOH)
			GPIOH_PCLK_EN;
	
	}
	else
	{
		if (pGPIO == GPIOA)
			GPIOA_PCLK_DI;
		else if (pGPIO == GPIOB)
			GPIOB_PCLK_DI;
		else if (pGPIO == GPIOC)
			GPIOC_PCLK_DI;
		else if (pGPIO == GPIOD)
			GPIOD_PCLK_DI;
		else if (pGPIO == GPIOE)
			GPIOE_PCLK_DI;
		else if (pGPIO == GPIOF)
			GPIOF_PCLK_DI;
		else if (pGPIO == GPIOG)
			GPIOG_PCLK_DI;
		else if (pGPIO == GPIOH)
			GPIOH_PCLK_DI;
	}

}

/****************************Peripheral clock control end************************************/

/****************************Data read and write to pin or port******************************/

/************************************************************

@Function :

@Description :

@param1 :

@ReturnType :

@Note :

*************************************************************/

uint8_t GPIO_ReadFromPin(GPIO_RegDef *pGPIO,uint8_t PinNumber)
{

}


/************************************************************

@Function :

@Description :

@param1 :

@ReturnType :

@Note :

*************************************************************/

void GPIO_WriteToPin(GPIO_RegDef *pGPIO,uint8_t PinNumber, uint8_t value)
{

}

/************************************************************

@Function :

@Description :

@param1 :

@ReturnType :

@Note :

*************************************************************/

uint16_t GPIO_ReadFromPort(GPIO_RegDef *pGPIO)
{

}

/************************************************************

@Function :

@Description :

@param1 :

@ReturnType :

@Note :

*************************************************************/

void GPIO_WriteToPort(GPIO_RegDef *pGPIO, uint16_t value)
{

}

/************************************************************

@Function :

@Description :

@param1 :

@ReturnType :

@Note :

*************************************************************/

void GPIO_TogglePin(GPIO_RegDef *pGPIO,uint8_t PinNumber)
{

}

/****************************Data read and write to pin or port end**************************/

/****************************Interrupt related APIs******************************************/

/************************************************************

@Function :

@Description :

@param1 :

@ReturnType :

@Note :

*************************************************************/

void GPIO_IRQConfig(uint8_t IRQNumber, uint8_t priority, uint8_t EnorDi)
{

}

/************************************************************

@Function :

@Description :

@param1 :

@ReturnType :

@Note :

*************************************************************/

void GPIO_IRQHandling(uint8_t PinNumber)
{

}

/****************************Interrupt related APIs end**************************************/

/******************APIs supported by this driver end*****************************************/