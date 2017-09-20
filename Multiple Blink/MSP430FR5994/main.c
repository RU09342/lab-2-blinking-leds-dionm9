#include <msp430.h> 


/**
 * main.c
 */
int main(void)
{

    WDTCTL = WDTPW | WDTHOLD;   // stop watchdog timer
    PM5CTL0 &= ~LOCKLPM5; // Disable the GPIO power-on default high-impedance mode


    P1DIR|=0x03;//sets p1 bit 0 as an output
    P1SEL1|=0x00;//sets p1 bit 0 for I/O
    P1SEL0|=0x00;//sets p1 bit 0 for I/O

    P1OUT=0x00;//clears p4 before use

    while(1){
        P1OUT&=~0x02;// turns led 2 off
        _delay_cycles(50000);//delays 100000 cycles
            P1OUT&=~0x01;// turns led 1 of
        _delay_cycles(50000);//delays 100000 cycles
            P1OUT|=0x02;// turns led 2 on
        _delay_cycles(50000);//delays 100000 cycles
            P1OUT|=0x01;// turns led 1 on
        _delay_cycles(50000);//delays 100000 cycles
    }
};
