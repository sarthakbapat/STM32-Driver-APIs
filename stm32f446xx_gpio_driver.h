#include "stm32f446xx.h"

/******************Configuration structure for GPIO pin*********************************/

typedef struct
{
	uint8_t GPIO_PinNumber;
	uint8_t GPIO_PinMode;									//Possible values from @GPIO_PIN_MODES
	uint8_t GPIO_PinSpeed;								//Possible values from @GPIO_OP_SPEED
	uint8_t GPIO_PinPuPdControl;					//Possible values from @GPIO_PIN_PUPD
	uint8_t GPIO_PinOPType;								//Possible values from @GPIO_OP_TYPES
	uint8_t GPIO_PinAltFunMode;

}GPIO_PinConfig_t;

/******************Configuration structure for GPIO pin ends*********************************/

/******************GPIO pin handler structure************************************************/

typedef struct
{

	GPIO_RegDef *pGPIO;											//Pointer to hold the base address of GPIO port.
	GPIO_PinConfig_t GPIO_PinConfig;				//Variable to hold GPIO pin config settings.

}GPIO_handler_t;

/******************GPIO pin handler structure end********************************************/

/*********GPIO possible pin numbers********/
/*********@GPIO_PIN_NUM********/

#define GPIO_PIN_0								0
#define GPIO_PIN_1								1
#define GPIO_PIN_2								2
#define GPIO_PIN_3								3
#define GPIO_PIN_4								4
#define GPIO_PIN_5								5
#define GPIO_PIN_6								6
#define GPIO_PIN_7								7
#define GPIO_PIN_8								8
#define GPIO_PIN_9								9
#define GPIO_PIN_10								10
#define GPIO_PIN_11								11
#define GPIO_PIN_12							  12
#define GPIO_PIN_13								13
#define GPIO_PIN_14								14
#define GPIO_PIN_15								15

/*********GPIO pin possible modes**********/

/*********@GPIO_PIN_MODES******************/
#define GPIO_MODE_IN							0
#define GPIO_MODE_OUT							1
#define GPIO_MODE_ALTFN						2
#define GPIO_MODE_ANALOG					3
#define GPIO_MODE_IT_FT						4
#define GPIO_MODE_IT_RT						5
#define GPIO_MODE_IT_RFT					6

/*********GPIO pin output types************/
/*********@GPIO_OP_TYPES******************/
#define GPIO_OP_TYP_PP						0
#define GPIO_OP_TYP_OD						1

/*********GPIO port output speed***********/
/*********@GPIO_OP_SPEED******************/
#define GPIO_OP_SPEED_LOW					0
#define GPIO_OP_SPEED_MED					1
#define GPIO_OP_SPEED_FAST				2
#define GPIO_OP_SPEED_HIGH				3

/*********GPIO port pull up down***********/
/*********@GPIO_PIN_PUPD******************/
#define GPIO_PUPD_NO							0
#define GPIO_PUPD_PU							1
#define GPIO_PUPD_PD							2



/******************APIs supported by this driver*********************************************/

/*Init and Deinit*/
void GPIO_init(GPIO_handler_t *pGPIO);
void GPIO_Deinit(GPIO_RegDef *pGPIO);

/*Peripheral clock control*/
void GPIO_Pclk_control(GPIO_RegDef *pGPIO, uint8_t EnorDi);

/*Data read and write to pin or port*/
uint8_t GPIO_ReadFromPin(GPIO_RegDef *pGPIO,uint8_t PinNumber);
void GPIO_WriteToPin(GPIO_RegDef *pGPIO,uint8_t PinNumber, uint8_t value);
uint16_t GPIO_ReadFromPort(GPIO_RegDef *pGPIO);
void GPIO_WriteToPort(GPIO_RegDef *pGPIO, uint16_t value);
void GPIO_TogglePin(GPIO_RegDef *pGPIO,uint8_t PinNumber);

/*Interrupt related APIs*/
void GPIO_IRQConfig(uint8_t IRQNumber, uint8_t priority, uint8_t EnorDi);
void GPIO_IRQHandling(uint8_t PinNumber);


/******************APIs supported by this driver end*****************************************/