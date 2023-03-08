/*
 * ICU_prog.c
 *
 * Created: 23/02/2023 01:43:54 ص
 *  Author: Eslam
 */ 


#include "STD_types.h"
#include "BIT_math.h"
#include "ICU_int.h"
#include "ICU_private.h"


void (*ICU_CallBack) (void) ;
void ICU_voidInit(void)
{
	/*  mode normal */
	CLEAR_BIT(TCCR1A,0);
	CLEAR_BIT(TCCR1A,1);
	CLEAR_BIT(TCCR1B,3);
	CLEAR_BIT(TCCR1B,4);
	
	/*  input source ICP1 */
	CLEAR_BIT(ACSR,2);
	
	/*  first edge Rising */
	SET_BIT(TCCR1B,6);
	
	/* prescaler 1024 */
	SET_BIT(TCCR1B,0);
	CLEAR_BIT(TCCR1B,1);
	SET_BIT(TCCR1B,2);
}
void ICU_voidSetICUCallBack(void (*Copy_ptr) (void) ) 
{
	ICU_CallBack = Copy_ptr ;
}

/*void __vector_7(void) __attribute__((signal , used)); // for avr gcc
void __vector_7(void)
{
	
	ICU_CallBack();
} */

void ICU_IntEnable(void)
{
  SET_BIT(TIMSK,5);
}


void ICU_IntDisable(void)
{
   CLEAR_BIT(TIMSK,5);
}