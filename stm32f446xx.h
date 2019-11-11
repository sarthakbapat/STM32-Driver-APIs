#include <stdint.h>

/******Some generic macros********/
#define __VO																volatile
#define ENABLE															1
#define DISABLE 														0
#define SET																	ENABLE
#define RESET																DISABLE
#define GPIO_PIN_SET												SET
#define GPIO_PIN_RESET											RESET

/* --------------------------------------------------
			Base addresses for the MCU memory
			U - Indicates unsigned integer
	--------------------------------------------------- */
	
	#define SRAM1_BASE_ADDRESS								0x20000000U						//SRAM1 base address.
	#define SRAM2_BASE_ADDRESS								0x2001C000U						//SRAM2 base address.
	#define SRAM															SRAM1_BASE_ADDRESS 		//SRAM1 is the main SRAM.
	#define FLASH_BASE_ADDRESS								0x08000000U						//Main memory (flash) base address.
	#define ROM_BASE_ADDRESS									0x1FFF0000U						//System memory (ROM) base address.
	
	/* --------------------------------------------------
			Base addresses for the AHBx and APBx peripherals
			U - Indicates unsigned integer
	-----------------------------------------------------*/
	
	#define PERIPHERAL_BASE										0x40000000U						//Bus Peripheral base address.
	#define APB1PERIPH_BASE										PERIPHERAL_BASE				//APB1 is the starting bus peripheral.
	#define APB2PERIPH_BASE										0x40010000U						//APB2 peripheral base address.
	#define AHB1PERIPH_BASE										0x40020000U						//AHB1 peripheral base address.
	#define AHB2PERIPH_BASE										0x50000000U						//AHB2 peripheral base address.
	
	/* --------------------------------------------------
			Base addresses for the peripherals hanging on
			the AHB1 bus.
			U - Indicates unsigned integer
	-----------------------------------------------------*/
	
	#define GPIOA_BASE_ADDRESS								(AHB1PERIPH_BASE + 0x0000U)	//Adding offset to AHB1 base address.
	#define GPIOB_BASE_ADDRESS								(AHB1PERIPH_BASE + 0x0400U)
	#define GPIOC_BASE_ADDRESS								(AHB1PERIPH_BASE + 0x0800U)
	#define GPIOD_BASE_ADDRESS								(AHB1PERIPH_BASE + 0x0C00U)
	#define GPIOE_BASE_ADDRESS								(AHB1PERIPH_BASE + 0x1000U)
	#define GPIOF_BASE_ADDRESS								(AHB1PERIPH_BASE + 0x1400U)
	#define GPIOG_BASE_ADDRESS								(AHB1PERIPH_BASE + 0x1800U)
	#define GPIOH_BASE_ADDRESS								(AHB1PERIPH_BASE + 0x1C00U)
	
	#define RCC_BASE_ADDRESS									(AHB1PERIPH_BASE + 0x3800U)
	
/* ----------------------------------------------------
			Base addresses for the peripherals hanging on
			the APB1 bus.
			U - Indicates unsigned integer
	-----------------------------------------------------*/
	
	#define SPI2_BASE_ADDRESS									(APB1PERIPH_BASE + 0x3800U)	//Adding offset to APB1 base address.
  #define SPI3_BASE_ADDRESS									(APB1PERIPH_BASE + 0x3C00U)
	
	#define USART2_BASE_ADDRESS								(APB1PERIPH_BASE + 0x4400U)								
	#define USART3_BASE_ADDRESS								(APB1PERIPH_BASE + 0x4800U)
	
  #define UART4_BASE_ADDRESS								(APB1PERIPH_BASE + 0x4C00U)	
  #define UART5_BASE_ADDRESS								(APB1PERIPH_BASE + 0x5000U)
	
	#define I2C1_BASE_ADDRESS									(APB1PERIPH_BASE + 0x5400U)	
	#define I2C2_BASE_ADDRESS									(APB1PERIPH_BASE + 0x5800U)
	#define I2C3_BASE_ADDRESS									(APB1PERIPH_BASE + 0x5C00U)
	
/* ----------------------------------------------------
			Base addresses for the peripherals hanging on
			the APB2 bus.
			U - Indicates unsigned integer
	-----------------------------------------------------*/
	
	#define USART1_BASE_ADDRESS								(APB2PERIPH_BASE + 0x1000U)
	#define USART6_BASE_ADDRESS								(APB2PERIPH_BASE + 0x1400U)
	
	#define SPI1_BASE_ADDRESS									(APB2PERIPH_BASE + 0x3000U)
	#define SPI4_BASE_ADDRESS									(APB2PERIPH_BASE + 0x3400U)
	
	#define EXTI_BASE_ADDRESS									(APB2PERIPH_BASE + 0x3C00U)
	#define SYSCFG_BASE_ADDRESS								(APB2PERIPH_BASE + 0x3800U)
	
	
	/***************************** Peripheral Register Definition Structures ********************************/
	
	//This section contains the C structures for all the peripheral registers.
	
	/* Following is the generic register definition for the GPIOx peripherals. The registers are arranged in the
	   way they appear in the MCU memory. The offsets are added to the base address so the order becomes important.*/
	typedef struct
	{
		__VO uint32_t MODER;										
		__VO uint32_t OTYPER;
		__VO uint32_t OSPEEDER;
		__VO uint32_t PUPDR;
		__VO uint32_t IDR;
		__VO uint32_t ODR;
		__VO uint32_t BSRR;
		__VO uint32_t LCKR;
		__VO uint32_t AFRL;
		__VO uint32_t AFRH;
		
	}GPIO_RegDef;
	
	typedef struct
	{
		__VO uint32_t CR;										
		__VO uint32_t PLLCFGR;
		__VO uint32_t CFGR;
		__VO uint32_t CIR;
		__VO uint32_t AHB1RSTR;
		__VO uint32_t AHB2RSTR;
		__VO uint32_t AHB3RSTR;
				 uint32_t Reserved1;
		__VO uint32_t APB1RSTR;
		__VO uint32_t APB2RSTR;
		     uint32_t Reserved2;
		     uint32_t Reserved3;
		__VO uint32_t AHB1ENR;
		__VO uint32_t AHB2ENR;
		__VO uint32_t AHB3ENR;
		     uint32_t Reserved4;
		__VO uint32_t APB1ENR;
		__VO uint32_t APB2ENR;
		     uint32_t Reserved5;
		     uint32_t Reserved6;
		__VO uint32_t AHB1LPENR;
		__VO uint32_t AHB2LPENR;
		__VO uint32_t AHB3LPENR;
		     uint32_t Reserved7;
		__VO uint32_t APB1LPENR;
		__VO uint32_t APB2LPENR;
		     uint32_t Reserved8;
		     uint32_t Reserved9;
		__VO uint32_t BDCR;
		__VO uint32_t CSR;
		     uint32_t Reserved10;
		     uint32_t Reserved11;
		__VO uint32_t SSCGR;
		__VO uint32_t PLLI2SCFGR;
		__VO uint32_t PLLSAICFGR;
		__VO uint32_t DCKCFGR;
		__VO uint32_t CKGATENR;
		__VO uint32_t DCKCFGR2;
		
	}RCC_RegDef;
	
	/***************************** Peripheral Register Definition Structures End*****************************/
	
	/******************* Peripheral base address typecasted to the peripheral structure type********************/
	
	#define GPIOA															((GPIO_RegDef*)GPIOA_BASE_ADDRESS)
	#define GPIOB															((GPIO_RegDef*)GPIOB_BASE_ADDRESS)
	#define GPIOC															((GPIO_RegDef*)GPIOC_BASE_ADDRESS)
	#define GPIOD															((GPIO_RegDef*)GPIOD_BASE_ADDRESS)
	#define GPIOE															((GPIO_RegDef*)GPIOE_BASE_ADDRESS)
	#define GPIOF															((GPIO_RegDef*)GPIOF_BASE_ADDRESS)
	#define GPIOG															((GPIO_RegDef*)GPIOG_BASE_ADDRESS)
	#define GPIOH															((GPIO_RegDef*)GPIOH_BASE_ADDRESS)
	
	#define RCC																((RCC_RegDef*)RCC_BASE_ADDRESS)
	
	/******************* Peripheral base address typecasted to the peripheral structure type end*****************/
	
	/******************************Clock enable macros for GPIOx ports********************************************/
	
	#define GPIOA_PCLK_EN											(RCC->AHB1ENR |= (1<<0))		//Set bit 0 of AHB1ENR for GPIOA.
	#define GPIOB_PCLK_EN											(RCC->AHB1ENR |= (1<<1))		//Set bit 1 of AHB1ENR for GPIOB.
	#define GPIOC_PCLK_EN											(RCC->AHB1ENR |= (1<<2))		//Set bit 2 of AHB1ENR for GPIOC.
	#define GPIOD_PCLK_EN											(RCC->AHB1ENR |= (1<<3))		//Set bit 3 of AHB1ENR for GPIOD.
	#define GPIOE_PCLK_EN											(RCC->AHB1ENR |= (1<<4))		//Set bit 4 of AHB1ENR for GPIOE.
	#define GPIOF_PCLK_EN											(RCC->AHB1ENR |= (1<<5))		//Set bit 5 of AHB1ENR for GPIOF.
	#define GPIOG_PCLK_EN											(RCC->AHB1ENR |= (1<<6))		//Set bit 6 of AHB1ENR for GPIOG.
	#define GPIOH_PCLK_EN											(RCC->AHB1ENR |= (1<<7))		//Set bit 7 of AHB1ENR for GPIOH.
	
	
	/******************************Clock enable macros for GPIO ports end*****************************************/
	
	/******************************Clock enable macros for I2Cx bus***********************************************/
	
	#define I2C1_PCLK_EN											(RCC->APB1ENR |= (1<<21))		//Set bit 21 of APB1ENR for I2C1.
	#define I2C2_PCLK_EN											(RCC->APB1ENR |= (1<<22))		//Set bit 22 of APB1ENR for I2C2.
	#define I2C3_PCLK_EN											(RCC->APB1ENR |= (1<<23))		//Set bit 23 of APB1ENR for I2C3.
	
	/******************************Clock enable macros for I2Cx bus end*******************************************/
	
	/******************************Clock enable macros for SPIx bus***********************************************/
	
	#define SPI1_PCLK_EN											(RCC->APB2ENR |= (1<<12))		//Set bit 12 of APB2ENR for SPI1.
	#define SPI2_PCLK_EN											(RCC->APB1ENR |= (1<<14))		//Set bit 14 of APB1ENR for SPI2.
	#define SPI3_PCLK_EN											(RCC->APB1ENR |= (1<<15))		//Set bit 15 of APB1ENR for SPI3.
	#define SPI4_PCLK_EN											(RCC->APB2ENR |= (1<<13))		//Set bit 13 of APB2ENR for SPI4.
	
	/******************************Clock enable macros for SPIx bus end*******************************************/
	
	/******************************Clock enable macros for UART***************************************************/
	
	#define UART4_PCLK_EN											(RCC->APB1ENR |= (1<<19))		//Set bit 19 of APB1ENR for UART4.
	#define UART5_PCLK_EN											(RCC->APB1ENR |= (1<<20))		//Set bit 20 of APB1ENR for UART5.
	
	/******************************Clock enable macros for UART end***********************************************/
	
	/******************************Clock enable macros for USART***************************************************/
	
	#define USART1_PCLK_EN										(RCC->APB2ENR |= (1<<4))		//Set bit 4 of APB2ENR for USART1.
	#define USART2_PCLK_EN										(RCC->APB1ENR |= (1<<17))		//Set bit 17 of APB1ENR for USART2.
	#define USART3_PCLK_EN										(RCC->APB1ENR |= (1<<18))		//Set bit 18 of APB1ENR for USART3.
	#define USART6_PCLK_EN										(RCC->APB2ENR |= (1<<5))		//Set bit 5 of APB2ENR for USART6.
	
	/******************************Clock enable macros for USART end***********************************************/
	
	/******************************Clock enable macros for SYSCFG***************************************************/
	
	#define SYSCFG_PCLK_EN										(RCC->APB2ENR |= (1<<14))		//Set bit 14 of APB2ENR for SYSCFG.
	
	/******************************Clock enable macros for SYSCFG end***********************************************/
	
	
  /******************************Clock disable macros for GPIOx ports********************************************/
	
	#define GPIOA_PCLK_DI											(RCC->AHB1ENR &= ~(1<<0))		//Clear bit 0 of AHB1ENR for GPIOA.
	#define GPIOB_PCLK_DI											(RCC->AHB1ENR &= ~(1<<1))		//Clear bit 1 of AHB1ENR for GPIOB.
	#define GPIOC_PCLK_DI											(RCC->AHB1ENR &= ~(1<<2))		//Clear bit 2 of AHB1ENR for GPIOC.
	#define GPIOD_PCLK_DI											(RCC->AHB1ENR &= ~(1<<3))		//Clear bit 3 of AHB1ENR for GPIOD.
	#define GPIOE_PCLK_DI											(RCC->AHB1ENR &= ~(1<<4))		//Clear bit 4 of AHB1ENR for GPIOE.
	#define GPIOF_PCLK_DI											(RCC->AHB1ENR &= ~(1<<5))		//Clear bit 5 of AHB1ENR for GPIOF.
	#define GPIOG_PCLK_DI											(RCC->AHB1ENR &= ~(1<<6))		//Clear bit 6 of AHB1ENR for GPIOG.
	#define GPIOH_PCLK_DI											(RCC->AHB1ENR &= ~(1<<7))		//Clear bit 7 of AHB1ENR for GPIOH.
	
	
	/******************************Clock disable macros for GPIO ports end*****************************************/
	
	/******************************Clock disable macros for I2Cx bus***********************************************/
	
	#define I2C1_PCLK_DI											(RCC->APB1ENR &= ~(1<<21))		//Clear bit 21 of APB1ENR for I2C1.
	#define I2C2_PCLK_DI											(RCC->APB1ENR &= ~(1<<22))		//Clear bit 22 of APB1ENR for I2C2.
	#define I2C3_PCLK_DI											(RCC->APB1ENR &= ~(1<<23))		//Clear bit 23 of APB1ENR for I2C3.
	
	/******************************Clock disable macros for I2Cx bus end*******************************************/
	
	/******************************Clock disable macros for SPIx bus***********************************************/
	
	#define SPI1_PCLK_DI											(RCC->APB2ENR &= ~(1<<12))		//Clear bit 12 of APB2ENR for SPI1.
	#define SPI2_PCLK_DI											(RCC->APB1ENR &= ~(1<<14))		//Clear bit 14 of APB1ENR for SPI2.
	#define SPI3_PCLK_DI											(RCC->APB1ENR &= ~(1<<15))		//Clear bit 15 of APB1ENR for SPI3.
	#define SPI4_PCLK_DI											(RCC->APB2ENR &= ~(1<<13))		//Clear bit 13 of APB2ENR for SPI4.
	
	/******************************Clock disable macros for SPIx bus end*******************************************/
	
	/******************************Clock disable macros for UART***************************************************/
	
	#define UART4_PCLK_DI											(RCC->APB1ENR &= ~(1<<19))		//Clear bit 19 of APB1ENR for UART4.
	#define UART5_PCLK_DI											(RCC->APB1ENR &= ~(1<<20))		//Clear bit 20 of APB1ENR for UART5.
	
	/******************************Clock disable macros for UART end***********************************************/
	
	/******************************Clock disable macros for USART***************************************************/
	
	#define USART1_PCLK_DI										(RCC->APB2ENR &= ~(1<<4))		//Clear bit 4 of APB2ENR for USART1.
	#define USART2_PCLK_DI										(RCC->APB1ENR &= ~(1<<17))	//Clear bit 17 of APB1ENR for USART2.
	#define USART3_PCLK_DI										(RCC->APB1ENR &= ~(1<<18))	//Clear bit 18 of APB1ENR for USART3.
	#define USART6_PCLK_DI										(RCC->APB2ENR &= ~(1<<5))		//Clear bit 5 of APB2ENR for USART6.
	
	/******************************Clock disable macros for USART end***********************************************/
	
	/******************************Clock disable macros for SYSCFG***************************************************/
	
	#define SYSCFG_PCLK_DI										(RCC->APB2ENR &= ~(1<<14))		//Clear bit 14 of APB2ENR for SYSCFG.
	
	/******************************Clock disable macros for SYSCFG end***********************************************/
	
	/******************************Macros to reset GPIOx peripherals*************************************************/
	//Using do-while is a technique to include 2 macros in one definition
	#define GPIOA_REG_RESET()									do{(RCC->AHB1RSTR |= (1<<0)); (RCC->AHB1RSTR &= ~(1<<0));}while (0)
	#define GPIOB_REG_RESET()									do{(RCC->AHB1RSTR |= (1<<1)); (RCC->AHB1RSTR &= ~(1<<1));}while (0)
	#define GPIOC_REG_RESET()									do{(RCC->AHB1RSTR |= (1<<2)); (RCC->AHB1RSTR &= ~(1<<2));}while (0)
	#define GPIOD_REG_RESET()									do{(RCC->AHB1RSTR |= (1<<3)); (RCC->AHB1RSTR &= ~(1<<3));}while (0)
	#define GPIOE_REG_RESET()									do{(RCC->AHB1RSTR |= (1<<4)); (RCC->AHB1RSTR &= ~(1<<4));}while (0)
	#define GPIOF_REG_RESET()									do{(RCC->AHB1RSTR |= (1<<5)); (RCC->AHB1RSTR &= ~(1<<5));}while (0)
	#define GPIOG_REG_RESET()									do{(RCC->AHB1RSTR |= (1<<6)); (RCC->AHB1RSTR &= ~(1<<6));}while (0)
	#define GPIOH_REG_RESET()									do{(RCC->AHB1RSTR |= (1<<7)); (RCC->AHB1RSTR &= ~(1<<7));}while (0)
	
	/******************************Macros to reset GPIOx peripherals end*********************************************/
	
	