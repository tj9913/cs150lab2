/*	Author: terry
 *  Partner(s) Name: 
 *	Lab Section:
 *	Assignment: Lab #  Exercise #
 *	Exercise Description: [optional - include for your own benefit]
 *
 *	I acknowledge all content contained herein, excluding template or example
 *	code, is my own original work.
 */
#include <avr/io.h>
#ifdef _SIMULATE_
#include "simAVRHeader.h"
#endif

int main(void) {
    /* Insert DDR and PORT initializations */
    DDRA = 0x00; PORTA = 0xFF;			//Configure port A's 8 pins as inputs
    DDRC = 0xFF; PORTC = 0x00;			//Configure port C's 8 pins as outputs, initialize to 0s
    unsigned char cntavail = 0x00;			//Temporary variable to hold the value of C
    unsigned char tmpA = 0x00;			//Temporary variable to hold the value of A
    /* Insert your solution below */
    while (1) {
	tmpA = PINA;				
	if(tmpA == 0x0F){			//0 spaces available
		cntavail = 0x00;
	}
	else if((tmpA == 0x07) || (tmpA == 0x0B) || (tmpA == 0x0D) || (tmpA == 0x0E)){//1 space available
		cntavail = 0x01;
	}
	else if((tmpA == 0x03) || (tmpA == 0x05) || (tmpA == 0x06) || (tmpA == 0x09) || (tmpA == 0x0A) || (tmpA == 0x0C)){ //2 spaces available
                cntavail = 0x02;
        }
	else if((tmpA == 0x01) || (tmpA == 0x02) || (tmpA == 0x04) || (tmpA == 0x08)){//3 spaces available
                cntavail = 0x03;
        }
	else if(tmpA == 0x00){			//4 spaces available
		cntavail = 0x04;
	}
	PORTC = cntavail;

    }
    return 0;
}
