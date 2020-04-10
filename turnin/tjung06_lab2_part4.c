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

unsigned char subtract(unsigned char a, unsigned char b){
	while(b != 0){
		unsigned char x = (~a) & b;
		a = a ^ b;
		b = x << 1;
	}
	return a;
}

unsigned char add(unsigned char a, unsigned char b){
	while(b != 0){
		unsigned char x = a & b;
		a = a ^ b;
		b = x << 1;
	}
	return a;
}
int main(void) {
    /* Insert DDR and PORT initializations */
    DDRA = 0x00; PORTA = 0xFF;			//Configure port A's 8 pins as inputs
    DDRB = 0x00; PORTB = 0xFF;                  //Configure port B's 8 pins as inputs
    DDRC = 0x00; PORTC = 0xFF;                  //Configure port C's 8 pins as inputs
    DDRD = 0xFF; PORTD = 0x00;			//Configure port D's 8 pins as outputs, initialize to 0s

    unsigned char tmpA = 0x00;			//Temporary variable to hold the value of A
    unsigned char tmpB = 0x00;                  //Temporary variable to hold the value of B
    unsigned char tmpC = 0x00;                  //Temporary variable to hold the value of C
    unsigned char tmpD = 0x00;                  //Temporary variable to hold the value of D
    unsigned char sum = 0x00;
    unsigned char difference = 0x00;
    /* Insert your solution below */
    while (1) {
	tmpA = PINA;
	tmpB = PINB;
	tmpC = PINC;	
	sum = add(tmpC,add(tmpA,tmpB));
	difference = subtract(tmpA,tmpC);
	tmpD = sum; 			
	if(sum > 0x8C){
		tmpD = tmpD | (0x01 << 0);
	}

	if(difference > 0x50){
		tmpD = tmpD | (0x01 << 1);
	}
	
	PORTD = tmpD;
    }
    return 0;
}
