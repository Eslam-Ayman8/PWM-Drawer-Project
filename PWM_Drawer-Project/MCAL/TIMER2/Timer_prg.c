/*
 * Timer_prg.c
 *
 * Created: 23/02/2023 01:46:31 ص
 *  Author: Eslam
 */ 



#include "STD_TYPES.h"
#include "BIT_MATH.h"
#include "Timer_int.h"
#include "Timer_priv.h"
#include "Timer_config.h"

void (*TIMER2_OV_CallBack) (void) ;
void (*TIMER2_CTC_CallBack) (void) ;

void TIMER2_void_Init(void)
{
		/*Disable Interrupts*/
		CLEAR_BIT(TIMSK , 6);
		CLEAR_BIT(TIMSK , 7);
		/*CLEAR FLAGS*/
		SET_BIT(TIFR , 6);
		SET_BIT(TIFR , 7);
		/*Clear register*/
		TCNT2 = 0 ;
		OCR2 = 0 ;
		
	#if(TIMER2_MODE == TIMER2_NORMAL)
		CLEAR_BIT(TCCR2 , 6);
		CLEAR_BIT(TCCR2 , 3);
	
	#elif(TIMER2_MODE == TIMER2_CTC)
		CLEAR_BIT(TCCR2 , 6);
		SET_BIT(TCCR2 , 3);
		
	#elif(TIMER2_MODE == TIMER2_FAST_PWM )
		SET_BIT(TCCR2 , 6);
		SET_BIT(TCCR2 , 3);
		
	#elif(TIMER2_MODE == TIMER2_PHASE_PWM )
		SET_BIT(TCCR2 , 6);
		CLEAR_BIT(TCCR2 , 3);
		
	#endif
	
	#if(TIMER2_COM_EVENT == TIMER2_NO_ACTION)
		CLEAR_BIT(TCCR2 , 4);
		CLEAR_BIT(TCCR2 , 5);
		
	
	#elif(TIMER2_COM_EVENT == TIMER2_TOGGLE)
		SET_BIT(TCCR2 , 4)
		CLEAR_BIT(TCCR2 , 5);
	#elif(TIMER2_COM_EVENT == (TIMER2_NON_INVERTED))
		CLEAR_BIT(TCCR2 , 4);
		SET_BIT(TCCR2 , 5);
	#elif(TIMER2_COM_EVENT == (TIMER2_INVERTED))
		SET_BIT(TCCR2 , 4);
		SET_BIT(TCCR2 , 5);

		
	#endif
	
	
		#if(TIMER2_PRESCALER == TIMER2_DIV_BY_1)
		SET_BIT(TCCR2 , 0);
		CLEAR_BIT(TCCR2 , 1);
		CLEAR_BIT(TCCR2 , 2);
		
		#elif(TIMER2_PRESCALER == TIMER2_DIV_BY_8)
		CLEAR_BIT(TCCR2 , 0);
		SET_BIT(TCCR2 , 1);
		CLEAR_BIT(TCCR2 , 2);
		#elif(TIMER2_PRESCALER == TIMER2_DIV_BY_64 )
		SET_BIT(TCCR2 , 0);
		SET_BIT(TCCR2 , 1);
		CLEAR_BIT(TCCR2 , 2);
		#elif(TIMER2_PRESCALER == TIMER2_DIV_BY_256 )
		CLEAR_BIT(TCCR2 , 0);
		SET_BIT(TCCR2 , 1);
		SET_BIT(TCCR2 , 2);
		#elif(TIMER2_PRESCALER == TIMER2_DIV_BY_1024 )
		SET_BIT(TCCR2 , 0);
		SET_BIT(TCCR2 , 1);
		SET_BIT(TCCR2 , 2);
		
		#endif
		
}

void TIMER2_void_SetTimerReg(u8 Copy_u8Val)
{
	TCNT2 = Copy_u8Val ;
}

void TIMER2_void_SetCompareVal(u8 Copy_u8Val)
{
	OCR2 = Copy_u8Val ;
}

void TIMER2_void_EnableOVInt(void)
{
	SET_BIT(TIMSK , 6);
}

void TIMER2_void_DisableOVInt(void)
{
	CLEAR_BIT(TIMSK , 6);
}

void TIMER2_void_EnableCTCInt(void)
{
	SET_BIT(TIMSK , 7);
}

void TIMER2_void_DisableCTCInt(void)
{
	CLEAR_BIT(TIMSK , 7);
}

void TIMER2_void_SetOVCallBack(void (*Copy_ptr) (void) ) 
{
	TIMER2_OV_CallBack = Copy_ptr ;
}

void TIMER2_void_SetCTCCallBack(void (*Copy_ptr) (void) ) 
{
	TIMER2_CTC_CallBack = Copy_ptr ;
	
}

/*void __vector_6(void) __attribute__((signal , used)); // for avr gcc
void __vector_6(void)
{
	
	TIMER2_OV_CallBack();
}*/

/*void __vector_5(void) __attribute__((signal , used));

void __vector_5(void)
{
	TIMER2_CTC_CallBack();
}*/
