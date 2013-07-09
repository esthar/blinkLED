/*
 * blinkLED.c
 *
 * Created: 9/28/2012 14:02:19
 *  Author: Andre Lucas
 
 For this board, PIN B0 is connected to an LED
 */ 

#define F_CPU 20000000  //Define the clock rate of the uC, which is needed by some dependencies like delay.h 
   
#include <avr/io.h>		//Include Input Output pins library e.g. DDRB and PORTB and PINB registers
#include <avr/delay.h>	//Delay functions "_delay_ms(miliseconds)" and "_delay_(microseconds)" which puts the IC into an idle calculation for that specific amount of time. (It is basically a FOR loop counting nothing relevant)

int main(void){
	DDRD = 1<<1;	//Define the pin B0 to be an output. See datasheet to understand DDRx, PORTx and PINx registers.  1<<0 is same as 0b0000001
	
    while(1){
		PORTD|= 1<<1;	// Makes pin B0 turn on (high level, 5V).
		_delay_ms(500);
		
		PORTD &= ~(1<<1);	//Turns off that same pin (low level, 0V).
		_delay_ms(500);
	   	   
    }
}