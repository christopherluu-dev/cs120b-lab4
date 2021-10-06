/*	Author: christopherluu
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

enum States{
    START,
    ON_PRESS,
    ON_RELEASE,
    OFF_PRESS,
    OFF_RELEASE
} state;

void Tick() {
    switch(state){
        case START:
            state = ON_PRESS;
            break;
        case ON_PRESS:
            state = (PINA) ? ON_PRESS : ON_RELEASE;
            break;
        case ON_RELEASE:
            state = (PINA) ? OFF_PRESS : ON_RELEASE;
            break;
        case OFF_PRESS:
            state = (PINA) ? OFF_PRESS : OFF_RELEASE;
            break;
        case OFF_RELEASE:
            state = (PINA) ? ON_PRESS : OFF_RELEASE;
            break;
        default:
            state = START;
            break;
    }
    
    swtich(state){
        case START:
            PORTB = 0x01;
            break;
        case ON_PRESS:
            PORTB = 0x01;
            break;
        case ON_RELEASE:
            break;
        case OFF_PRESS:
            PORTB = 0x02;
            break;
        case OFF_RELEASE:
            break;
        default:
            PORTB = 0x01;
            break;
    }
}

int main(void) {
    /* Insert DDR and PORT initializations */
    DDRA = 0x00; PORTA = 0xFF;
    DDRB = 0xFF; PORTB = 0x00;

    /* Insert your solution below */
    while (1) {
        Tick();
    }
    return 1;
}
