/*	Author: fox
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
    DDRA = 0x00; PORTA = 0xff;
    DDRB = 0xff; PORTB = 0x00;

    /* Insert your solution below */
    
    unsigned char temp_input = 0x00;
    while (1) {
        temp_input = PINA;
	
	if ((temp_input & 0x03) ^ 0x01){
	    PORTB = 0x00;
	} else {
	    PORTB = 0x01;
	}
    }
    
    return 1;
}
