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
#include <stdlib.h>
#ifdef _SIMULATE_
#include "simAVRHeader.h"
#endif

int main(void) {
    /* Insert DDR and PORT initializations */
    DDRA = 0x00; PORTA = 0xff;
    DDRB = 0x00; PORTB = 0xff;
    DDRC = 0x00; PORTC = 0xff;
    DDRD = 0xff; PORTD = 0x00;

    /* Insert your solution below */
    
    uint8_t a_in, b_in, c_in, d_out;
    uint16_t gross;
    uint8_t diff;
    while (1) {
        a_in = PINA;
        b_in = PINB;
	c_in = PINC;
	d_out = 0x00;
	gross = ((uint16_t) a_in) + b_in + c_in;
	if (gross > 140) d_out = 0x01;
	diff = abs(((int16_t)a_in) - c_in);
	if (diff > 80) d_out |= 0x02;
	if (gross > 252) d_out |= 0xfc;
	else d_out |= (gross & 0xfc);

	PORTD = d_out;;
    }
    
    return 1;
}
