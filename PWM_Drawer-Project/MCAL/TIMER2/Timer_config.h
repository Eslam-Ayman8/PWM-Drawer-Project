/*
 * Timer_config.h
 *
 * Created: 23/02/2023 01:47:00 ص
 *  Author: Eslam
 */ 


#ifndef TIMER_CONFIG_H_
#define TIMER_CONFIG_H_



/*Range
#define TIMER2_NORMAL
#define TIMER2_CTC
#define TIMER2_FAST_PWM
#define TIMER2_PHASE_PWM
*/

#define TIMER2_MODE TIMER2_FAST_PWM
/*Range
#define TIMER2_DIV_BY_1
#define TIMER2_DIV_BY_8
#define TIMER2_DIV_BY_64
#define TIMER2_DIV_BY_256
#define TIMER2_DIV_BY_1024
*/
#define TIMER2_PRESCALER  TIMER2_DIV_BY_8

/*Range for Non-PWM mode
#define TIMER2_NO_ACTION
#define TIMER2_TOGGLE
#define TIMER2_SET
#define TIMER2_CLEAR
*/

/*
PWM modes
#define TIMER2_INVERTED
#define TIMER2_NON_INVERTED
*/

#define TIMER2_COM_EVENT   TIMER2_NON_INVERTED




#endif /* TIMER_CONFIG_H_ */