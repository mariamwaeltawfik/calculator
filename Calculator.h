/*
 * calculator.h
 *
 * Created: 2/3/2024 11:53:36 PM
 *  Author: NOTEBOOK
 */ 


#ifndef CALCULATOR_H_
#define CALCULATOR_H_
#include "StdTypes.h"
typedef enum {
	SUM,
	SUB,
	MULTI,
	DIV
	
}flags_t;
void Delete_Elements(u8 *str,u8 pos);
//u8* New_With_Calc(u8 *str,u8 res,u8 pre ,u8 next);
u16 KEYPAD_CALC(u16*arr);
void reset(void);
u16 Store_Equation(void);
u16 Multibly(u8* str);
void Calculator_Init(void);
void Calculator(void);
u8 count(u32 num);
#endif /* CALCULATOR_H_ */