#include <msp430.h> 


/**
 * main.c
 */
int main(void)
{

    WDTCTL = WDTPW | WDTHOLD;   // stop watchdog timer
    PM5CTL0 &= ~LOCKLPM5; // Disable the GPIO power-on default high-impedance mode


    P1DIR=0x01; //sets p1 bit 0 as an output
    P1SEL0=0x00; //sets p1 bit 0 as I/O

    P2DIR=0x01; //sets p2 bit 0 as an output
    P2SEL0=0x00; //sets p2 bit 0 as I/O

    P1OUT=0x00; //clears p1 before use
    P2OUT=0x00; //clears p1 before use

    while(1){
        P2OUT&=~0x01;//turns off led 2
        _delay_cycles(100000);//delays 100000 cycles
            P1OUT&=~0x01;//turns off led 1
        _delay_cycles(100000);//delays 100000 cycles
            P2OUT|=0x01; //turns led 2 on
        _delay_cycles(100000);//delays 100000 cycles
            P1OUT|=0x01;//turns led 1 on
        _delay_cycles(100000);//delays 100000 cycles
    }
};
