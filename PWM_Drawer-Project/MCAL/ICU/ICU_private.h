/*
 * ICU_private.h
 *
 * Created: 23/02/2023 01:44:20 ص
 *  Author: Eslam
 */ 


#ifndef ICU_PRIVATE_H_
#define ICU_PRIVATE_H_


#define TIMSK  *((volatile u8 *)0x59)
#define ACSR   *((volatile u8 *)0x28)
#define TCCR1A *((volatile u8 *)0x4F)
#define TCCR1B *((volatile u8 *)0x4E)
#define ICRL *((volatile u8 *)0x46)
#define ICRH *((volatile u8 *)0x47)




#endif /* ICU_PRIVATE_H_ */