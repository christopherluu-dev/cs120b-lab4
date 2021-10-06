/*	Author: christopherluu
 *  Partner(s) Name: 
 *	Lab Section: 22
 *	Assignment: Lab #4  Exercise #2
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
    NOTHING,
    ADD,
    MINUS,
    RESET
} state;

void Tick() {
    switch(state){
        case START:
            state = NOTHING;
            break;
        case NOTHING:
            if(PINA == 0x01){
                state = ADD;
            }
            else if(PINA == 0x02){
                state = MINUS;
            }
            else if(PINA == 0x03){
                state = RESET;
            }
            else{
                state = NOTHING;
            }
            break;
        case ADD:
            if(PINA == 0x01){
                state = ADD;
            }
            else if(PINA == 0x02){
                state = MINUS;
            }
            else if(PINA == 0x03){
                state = RESET;
            }
            else{
                state = NOTHING;
            }
            break;
        case MINUS:
            if(PINA == 0x01){
                state = ADD;
            }
            else if(PINA == 0x02){
                state = MINUS;
            }
            else if(PINA == 0x03){
                state = RESET;
            }
            else{
                state = NOTHING;
            }
            break;
        case RESET:
            if(PINA == 0x01){
                state = ADD;
            }
            else if(PINA == 0x02){
                state = MINUS;
            }
            else if(PINA == 0x03){
                state = RESET;
            }
            else{
                state = NOTHING;
            }
            break;
        default:
            state = NOTHING;
            break;
    }
    
    switch(state){
        case START:
            PORTC = 0x07;
            break;
        case NOTHING:
            break;
        case ADD:
            if(PORTC < 9){
                PORTC++;
            }
            break;
        case MINUS:
            if(PORTC > 0){
                PORTC--;
            }
            break;
        case RESET:
            {
                PORTC = 0;
            }
            break;
        default:
            PORTC = 0x07;
            break;
    }
}

int main(void) {
    /* Insert DDR and PORT initializations */
    DDRA = 0x00; PORTA = 0xFF;
    DDRC = 0xFF; PORTC = 0x00;

    /* Insert your solution below */
    while (1) {
        Tick();
    }
    return 1;
}
