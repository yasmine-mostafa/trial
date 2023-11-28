/*
 * Task2.c
 *
 * Created: 11/27/2023 7:27:28 PM
 * Author : main
 */ 

/************************************************************************/
/* Task 2: Task to change leds from 1 to 15 by using a push button                                                                     */
/************************************************************************/
#include "..\..\01-MCAL\00-DIO\DIO.h"

int main(void)
{
  
	//Pull up Input configuration
	DIO_enumSetPinConfig(DIO_enumPortB, DIO_enumPin0, DIO_enumInputInternalPU);
	
	//Output configuration
	DIO_enumSetPinConfig(DIO_enumPortA, DIO_enumPin0, DIO_enumOutput);
	DIO_enumSetPinConfig(DIO_enumPortA, DIO_enumPin1, DIO_enumOutput);
	DIO_enumSetPinConfig(DIO_enumPortA, DIO_enumPin2, DIO_enumOutput);
	DIO_enumSetPinConfig(DIO_enumPortA, DIO_enumPin3, DIO_enumOutput);
	
	//Variables
	u8 Loc_u8Counter =0;
	u8 Loc_u8PinB0State;
	u8 * Loc_pu8PinB0State= &Loc_u8PinB0State;
	
    while (1) 
    {
		DIO_enumReadState(DIO_enumPortB, DIO_enumPin0,Loc_pu8PinB0State);
		if(*Loc_pu8PinB0State==0)
		{
			DIO_DelayTimeMS(200);
			DIO_enumReadState(DIO_enumPortB, DIO_enumPin0,Loc_pu8PinB0State);
			if(*Loc_pu8PinB0State==0)
			{
				Loc_u8Counter++;
				if(Loc_u8Counter > 15)
				{
					Loc_u8Counter=0;
				}
				DIO_enumSetPortValue(DIO_enumPortA,Loc_u8Counter);
			}	
		}
    }
}

