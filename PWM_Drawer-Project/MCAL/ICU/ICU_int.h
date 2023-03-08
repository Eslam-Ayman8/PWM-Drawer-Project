/*
 * ICU_int.h
 *
 * Created: 23/02/2023 01:44:09 ص
 *  Author: Eslam
 */ 


#ifndef ICU_INT_H_
#define ICU_INT_H_



void ICU_voidInit(void);
void ICU_voidSetICUCallBack(void (*Copy_ptr) (void) ) ;
void ICU_IntEnable(void);
void ICU_IntDisable(void);



#endif /* ICU_INT_H_ */