#include <msp430.h> 


/**
 * main.c
 */
int main(void)
{

    WDTCTL = WDTPW | WDTHOLD;   // stop watchdog timer
    PM5CTL0 &= ~LOCKLPM5;                   // Disable the GPIO power-on default high-impedance mode


    P1DIR |= 0x01;//sets p1 bit 0 as output
    P1SEL1=0x00;//sets p1 bit 0 as I/0
    P1SEL0=0x00;//sets p1 bit 0 as I/0

    P1OUT=0x00;//clears p1 before use

    while(1){

        _delay_cycles(50000);//delay 50000 cycles
            P1OUT=0x00;//turns led off
        _delay_cycles(50000);//delay 50000 cycles
            P1OUT=0x01;//turns led on
    }
};
