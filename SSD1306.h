#include "I2C.h"
#include "fonts.h"
//Defines--------------------------------
#define SSD1306_Address 0b111100
#define SSD1306_WIDTH 128
#define SSD1306_HEIGHT 64
#define SSD1306_BUFFERSIZE (SSD1306_WIDTH*SSD1306_HEIGHT)/8
//---------------------------------------

typedef enum {
	Black = 0x00, /*!< Black color, no pixel */
	White = 0x01  /*!< Pixel is set. Color depends on LCD */
} SSD1306_COLOR;

void SSD1306_Init(void);
void SSD1306_Send_Command(char command);
void SSD1306_Send_Data(char data);
void SSD1306_Send_Array(char *Array, int size);
void SSD1306_Fill(SSD1306_COLOR c);
void ssd1306_UpdateScreen(void);
void ssd1306_DrawPixel(uint8_t, uint8_t,uint8_t);
char ssd1306_WriteChar(char ch, FontDef Font, SSD1306_COLOR color);