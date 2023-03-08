/*
 * PWM_Drawer-Project.c
 *
 * Created: 23/02/2023 12:40:40 ص
 * Author : Eslam
 */ 


#include <avr/io.h>
#include "STD_types.h"
#include "BIT_math.h"
#include "MCAL/DIO/DIO_int.h"
#include "MCAL/GIE/GIE_int.h"
#include "MCAL/TIMER2/Timer_int.h"
#include "HAL/LCD/LCD_int.h"
#include "MCAL/ICU/ICU_int.h"
#include "MCAL/ICU/ICU_private.h"
#include <avr/interrupt.h>
#define F_CPU 16000000UL
#include <util/delay.h>

u16 read_1 = 0;
u16 read_2 = 0;
u16 read_3 = 0;
u8 counter = 0;
static u32 count = 0;

//New Characters stored in LCD
s8 fall_edge[] = {
	0b00011100,
	0b00000100,
	0b00000100,
	0b00000100,
	0b00000100,
	0b00000100,
	0b00000100,
	0b00000111
};

s8 rise_edge[] = {
	0b00000111,
	0b00000100,
	0b00000100,
	0b00000100,
	0b00000100,
	0b00000100,
	0b00000100,
	0b00011100
};

s8 up[] = {
	0b00011111,
	0b00000000,
	0b00000000,
	0b00000000,
	0b00000000,
	0b00000000,
	0b00000000,
	0b00000000
};

s8 down[] = {
	0b00000000,
	0b00000000,
	0b00000000,
	0b00000000,
	0b00000000,
	0b00000000,
	0b00000000,
	0b00011111
};




ISR(TIMER1_CAPT_vect)
{
	
	counter++;
	if (counter == 1)
	{
		read_1 = ((ICRH<<8) | ICRL);
		//falling edge read
		CLEAR_BIT(TCCR1B,6);
		
	}
	if (counter == 2)
	{
		read_2 = ((ICRH<<8) | ICRL);
		//rising edge read
		SET_BIT(TCCR1B,6);
	}
	if (counter == 3)
	{
		read_3 = ((ICRH<<8) | ICRL);
		//falling edge read
		CLEAR_BIT(TCCR1B,6);
		CLEAR_BIT(TIMSK,5);
		
	}
}

int main(void)
{
	DIO_voidInit();							// Initializing DIO
	LCD_voidInit();							// Initializing LCD
	LCD_voidCustomChar(0x40,fall_edge);		//New Character stored in LCD
	LCD_voidCustomChar(0x48,rise_edge);		//New Character stored in LCD
	LCD_voidCustomChar(0x50,up);			//New Character stored in LCD
	LCD_voidCustomChar(0x58,down);			//New Character stored in LCD
	TIMER2_void_Init();						// Initializing TIMER2
	
	TIMER2_void_SetCompareVal(200);		//TIMER2 CTC with OC2 = 200
	//TIMER2_void_EnableCTCInt();
	
	ICU_voidInit();					//Initializing Input-Capture
	ICU_IntEnable();				//Enabling Input-Capture
	GIE_voidEnable();				//Enabling General Interrupt
	f32 frequancy = 0;
	f32 Duty_Cycle = 0;
	
	u8 string_Freq[10] = {"0"};			//Frequency as String printed in LCD
	u8 string_Duty[15] = {"0"};			//Duty Cycle as String printed in LCD
		u8 level = 0;					//Current printing logic level (0) or (1)
		u8 signal_col = LCD_U8_COL1;
	
	
	while (1)
	{
		if (counter == 3)
		{
			if ( read_1<read_2 && read_2<read_3)					{
				
				
				
				
				frequancy = (f32)F_CPU/(f32)(read_3 - read_1);
				frequancy = (f32)frequancy/(f32)1000;
				Duty_Cycle = ((f32)(read_2 - read_1)/(f32)(read_3 - read_1)) * 100;
				
				
				dtostrf(frequancy, 2, 1, string_Freq);

				itoa((int) Duty_Cycle, string_Duty, 10);
				

				counter = 0;
				

				
				LCD_voidSetCursor(LCD_U8_ROW_1,LCD_U8_COL1);
				LCD_voidSendString("F: ");
				LCD_voidSetCursor(LCD_U8_ROW_1,LCD_U8_COL3);
				LCD_voidSendString(string_Freq);
				LCD_voidSetCursor(LCD_U8_ROW_1,LCD_U8_COL7);
				LCD_voidSendString("kHz");
				LCD_voidSetCursor(LCD_U8_ROW_1,LCD_U8_COL11);
			    LCD_voidSendString("D: ");	
				LCD_voidSetCursor(LCD_U8_ROW_1,LCD_U8_COL13);
				LCD_voidSendString(string_Duty);
				LCD_voidSetCursor(LCD_U8_ROW_1,LCD_U8_COL16);
				LCD_voidSendString("%");							}
		}
	
		ICU_IntEnable();
		
		// PRINTING THE PULSES
		
		if (DIO_u8GetPinValue(DIO_U8_PIN31) == 0)
		{
			if (level == 0)
			{
				LCD_voidSetCursor(LCD_U8_ROW_2,signal_col);
				LCD_voidSendData(0x03);
				
			}
			else if (level ==1)
			{
				LCD_voidSetCursor(LCD_U8_ROW_2,signal_col);
				LCD_voidSendData(0x00);
				
			}
			level = 0;
		}
		else if (DIO_u8GetPinValue(DIO_U8_PIN31) == 1)
		{
			if (level == 0)
			{
				LCD_voidSetCursor(LCD_U8_ROW_2,signal_col);
				LCD_voidSendData(0x01);
				
			}
			else if (level ==1)
			{
				LCD_voidSetCursor(LCD_U8_ROW_2,signal_col);
				LCD_voidSendData(0x02);
				
			}
			level = 1;
		}
		
		// ORDERING PULSES IN ROW 2
		if (signal_col == LCD_U8_COL16)
		{
			signal_col = LCD_U8_COL1;
		}
		if (signal_col <= LCD_U8_COL16)
		{
		signal_col++;
		}
	}
}


