/*
 * LCD_config.h
 *
 * Created: 23/02/2023 02:17:24 ص
 *  Author: Eslam
 */ 


#ifndef LCD_CONFIG_H_
#define LCD_CONFIG_H_





#define LCD_U8_D0     DIO_U8_PIN0
#define LCD_U8_D1     DIO_U8_PIN1
#define LCD_U8_D2     DIO_U8_PIN2
#define LCD_U8_D3     DIO_U8_PIN3
#define LCD_U8_D4     DIO_U8_PIN4
#define LCD_U8_D5     DIO_U8_PIN5
#define LCD_U8_D6     DIO_U8_PIN6
#define LCD_U8_D7     DIO_U8_PIN7


#define LCD_U8_RS     DIO_U8_PIN9
#define LCD_U8_RW     DIO_U8_PIN10
#define LCD_U8_E      DIO_U8_PIN11

/*
options:

LCD_U8_4_BIT
LCD_U8_8_BIT
*/
#define LCD_U8_DATA_LENGTH  LCD_U8_4_BIT



#endif /* LCD_CONFIG_H_ */