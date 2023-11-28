/*
 * Task1.c
 *
 * Created: 11/27/2023 5:38:32 PM
 * Author : main
 */ 

/************************************************************************/
/* This the task for toggling two leds using a custom delay function implemented in the Delay.h                                                                     */
/************************************************************************/

#include "..\..\01-MCAL\00-DIO\DIO.h"

int main(void)
{
	DIO_enumSetPinConfig(DIO_enumPortA, DIO_enumPin0, DIO_enumOutput);
	DIO_enumSetPinConfig(DIO_enumPortA, DIO_enumPin1, DIO_enumOutput);
	DIO_enumSetPin(DIO_enumPortA, DIO_enumPin0 ,DIO_enumLogicHigh);
	DIO_enumSetPin(DIO_enumPortA, DIO_enumPin1 ,DIO_enumLogicLow);
	
    /* Replace with your application code */
    while (1) 
    { 
		DIO_enumTogglePin(DIO_enumPortA, DIO_enumPin0);
		DIO_enumTogglePin(DIO_enumPortA, DIO_enumPin1);
		DIO_DelayTimeMS(500);
		
		
    }
}

