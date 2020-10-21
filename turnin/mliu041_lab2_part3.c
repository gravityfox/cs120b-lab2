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
    
    unsigned char t_in = 0x00;
    unsigned char cntavail;
    while (1) {
        t_in = PINA;
	
	cntavail = (t_in & 1) + ((t_in & 2) >> 1) + ((t_in & 4) >> 2) + ((t_in & 8) >> 3);
	cntavail |= (cntavail & 0x04) << 5; 
	PORTC ^= (PORTC & 0x8f) ^ cntavail;
    }
    
    return 1;
}
