/*
 * Timer_int.h
 *
 * Created: 23/02/2023 01:45:31 ص
 *  Author: Eslam
 */ 


#ifndef TIMER_INT_H_
#define TIMER_INT_H_


void TIMER2_void_Init(void);

void TIMER2_void_SetTimerReg(u8 Copy_u8Val);

void TIMER2_void_SetCompareVal(u8 Copy_u8Val);

void TIMER2_void_EnableOVInt(void);

void TIMER2_void_DisableOVInt(void);

void TIMER2_void_EnableCTCInt(void);

void TIMER2_void_DisableCTCInt(void);

void TIMER2_void_SetOVCallBack(void (*Copy_ptr) (void) );

void TIMER2_void_SetCTCCallBack(void (*Copy_ptr) (void) );





#endif /* TIMER_INT_H_ */