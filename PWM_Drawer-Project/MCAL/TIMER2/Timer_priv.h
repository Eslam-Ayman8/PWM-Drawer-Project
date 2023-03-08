/*
 * Timer_priv.h
 *
 * Created: 23/02/2023 01:46:01 ص
 *  Author: Eslam
 */ 


#ifndef TIMER_PRIV_H_
#define TIMER_PRIV_H_



#define TIMSK (*(volatile u8 * )0x59)
#define OCR2 (*(volatile u8 * )0x43)
#define TCCR2 (*(volatile u8 * )0x45)
#define TCNT2 (*(volatile u8 * )0x44)
#define TIFR (*(volatile u8 * )0x58)



#define TIMER2_NORMAL 		1
#define TIMER2_CTC 			2
#define TIMER2_FAST_PWM 	3
#define TIMER2_PHASE_PWM 	4

#define TIMER2_DIV_BY_1			1
#define TIMER2_DIV_BY_8			5
#define TIMER2_DIV_BY_64		8
#define TIMER2_DIV_BY_256		10
#define TIMER2_DIV_BY_1024		15


#define TIMER2_NO_ACTION	100
#define TIMER2_TOGGLE		12
#define TIMER2_SET			20
#define TIMER2_CLEAR		25

#define TIMER2_INVERTED      1
#define TIMER2_NON_INVERTED  2


#endif /* TIMER_PRIV_H_ */