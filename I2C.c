#include "I2C.h"
#include "GPIO.h"

void I2C_Init(void)
	{
	//Clocks------------------------------------------------
		//Enable PORTA clocks
		RCC->AHBENR  |= RCC_AHBENR_GPIOAEN;
		//Enable I2C1 clocks
		RCC->APB1ENR |= RCC_APB1ENR_I2C1EN ;	
	//------------------------------------------------------	
		
	//GPIO-------------------------------------------------- 
	//Configure Alternate Fucntion GPIO to I2C1
		GPIOA->AFR[1]  |= GPIO_Aternate_Function_I2C1;
	//Set GPIOA Pin 9-10 as Alternate Function
		GPIOA->MODER   |= 0x280000;
	//Set GPIOA pin 9-10 as speed as High
		GPIOA->OSPEEDR |= 0x3c0000; 
	//Set GPIOA pin 9-10 as open drain
		GPIOA->OTYPER  |= 0x600;
	//Set GPIOA pin 9-10 as no Pull-up Pull-down
		GPIOA->PUPDR   |= 0x0;
	//------------------------------------------------------
	
	//I2C Resgisters
		I2C1->TIMINGR = 0x00201D2D;
	//Enable I2C
		I2C1->CR1 |= 1;
	//Set NBYTES
		I2C1->CR2 |= (NBytes) <<16;
	//Set AUTOEND ON
		I2C1->CR2 |= 1 <<25;
	//Set Transfer Direction
		I2C1->CR2 |= Transfer_Direction <<0;		
	}
	
	void I2C_Send(char bits[], char Address)
	{				
	 //Set Address
	  I2C1->CR2 |= (Address)<<1;
	 //Set data
		while(!((I2C1->ISR & I2C_ISR_TXE) == I2C_ISR_TXE));
		I2C1->TXDR		= bits[0];
	 //Start I2C 
		I2C1->CR2 		|= 1 << 13;	
	 //Set data
		while(!((I2C1->ISR & I2C_ISR_TXE) == I2C_ISR_TXE));
		I2C1->TXDR		= bits[1];    
	 //Start I2C 
		I2C1->CR2 		|= 1 << 13;	
   //while(!((I2C1->ISR & I2C_ISR_TXE) == I2C_ISR_TXE));		
	 //Stop I2C
	  //I2C1->CR2     |= 1 << 14;
	}
	
	
