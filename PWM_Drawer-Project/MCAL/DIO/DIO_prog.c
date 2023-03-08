/*
 * DIO_prog.c
 *
 * Created: 23/02/2023 01:40:20 ص
 *  Author: Eslam
 */ 


#include "STD_types.h"
#include "DIO_int.h"
#include "BIT_math.h"
#include "DIO_config.h"
#include "DIO_private.h"

void DIO_voidInit(void)
{
	DDRA = DIO_U8_DIRA;
	DDRB = DIO_U8_DIRB;
	DDRC = DIO_U8_DIRC;
	DDRD = DIO_U8_DIRD;
}
void DIO_voidSetPinValue(u8 Copy_u8Pin , u8 Copy_u8Value)
{
	if(Copy_u8Pin < DIO_U8_END_PORTA)
	{
		switch(Copy_u8Value)
		{
			case DIO_U8_HIGH: SET_BIT(PORTA,Copy_u8Pin); break;
			case DIO_U8_LOW:  CLEAR_BIT(PORTA,Copy_u8Pin); break;
		}
	}
	else if(Copy_u8Pin < DIO_U8_END_PORTB)
	{
		Copy_u8Pin = Copy_u8Pin - DIO_U8_END_PORTA;
		switch(Copy_u8Value)
		{
			case DIO_U8_HIGH: SET_BIT(PORTB,Copy_u8Pin); break;
			case DIO_U8_LOW:  CLEAR_BIT(PORTB,Copy_u8Pin); break;
		}
	}
	else if(Copy_u8Pin < DIO_U8_END_PORTC)
	{
		Copy_u8Pin = Copy_u8Pin - DIO_U8_END_PORTB;
		switch(Copy_u8Value)
		{
			case DIO_U8_HIGH: SET_BIT(PORTC,Copy_u8Pin); break;
			case DIO_U8_LOW:  CLEAR_BIT(PORTC,Copy_u8Pin); break;
		}
	}
	
	else if(Copy_u8Pin < DIO_U8_END_PORTD)
	{
		Copy_u8Pin = Copy_u8Pin - DIO_U8_END_PORTC;
		switch(Copy_u8Value)
		{
			case DIO_U8_HIGH: SET_BIT(PORTD,Copy_u8Pin); break;
			case DIO_U8_LOW:  CLEAR_BIT(PORTD,Copy_u8Pin); break;
		}
	}
}
u8 DIO_u8GetPinValue(u8 Copy_u8Pin)
{
	u8 Local_u8Value = 0;
	if(Copy_u8Pin < DIO_U8_END_PORTA)
	{
		Local_u8Value = GET_BIT(PINA , Copy_u8Pin);
	}
	else if(Copy_u8Pin < DIO_U8_END_PORTB)
	{
		Copy_u8Pin = Copy_u8Pin - DIO_U8_END_PORTA;
		Local_u8Value = GET_BIT(PINB , Copy_u8Pin);
	}
	else if(Copy_u8Pin < DIO_U8_END_PORTC)
	{
		Copy_u8Pin = Copy_u8Pin - DIO_U8_END_PORTB;
		Local_u8Value = GET_BIT(PINC , Copy_u8Pin);
	}
	
	else if(Copy_u8Pin < DIO_U8_END_PORTD)
	{
		Copy_u8Pin = Copy_u8Pin - DIO_U8_END_PORTC;
		Local_u8Value = GET_BIT(PIND , Copy_u8Pin);
	}
	
	return Local_u8Value;
}