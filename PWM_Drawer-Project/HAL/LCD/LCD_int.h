/*
 * LCD_int.h
 *
 * Created: 23/02/2023 02:16:47 ص
 *  Author: Eslam
 */ 


#ifndef LCD_INT_H_
#define LCD_INT_H_



#define LCD_U8_ROW_1  0
#define LCD_U8_ROW_2  1

#define LCD_U8_COL1   0
#define LCD_U8_COL2   1
#define LCD_U8_COL3   2
#define LCD_U8_COL4   3
#define LCD_U8_COL5   4
#define LCD_U8_COL6   5
#define LCD_U8_COL7   6
#define LCD_U8_COL8   7
#define LCD_U8_COL9   8
#define LCD_U8_COL10  9
#define LCD_U8_COL11  10
#define LCD_U8_COL12  11
#define LCD_U8_COL13  12
#define LCD_U8_COL14  13
#define LCD_U8_COL15  14
#define LCD_U8_COL16  15

void LCD_voidInit(void);
void LCD_voidSendData(u8 Copy_u8Data);
void LCD_voidSendCommand(u8 Copy_u8Command);
void LCD_voidSendString(s8* P_s8String);
void LCD_voidSetCursor(u8 Copy_u8Row , u8 Copy_u8Column);
void LCD_voidCustomChar(u8 Copy_u8Location , s8* Copy_u8Char);



#endif /* LCD_INT_H_ */