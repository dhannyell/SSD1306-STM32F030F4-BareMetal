#include "stm32f0xx.h"
#include "GPIO.h"
#include "I2C.h"
#include "SSD1306.h"

void delay(int ms);

int main()
{
	GPIO_Init();
	I2C_Init();	
	//SSD1306_Send_Command(0b1100111);
	SSD1306_Init();
	//SSD1306_Fill(White);
	ssd1306_WriteChar('A', Font_11x18, White);
	ssd1306_UpdateScreen();
	
	while(1)
	{
		delay(500000);
		set_Bit(GPIOB, 1);
		delay(500000);
		reset_Bit(GPIOB, 1);
	}	
}

void delay(int ms)
{
	while(ms--);
}


