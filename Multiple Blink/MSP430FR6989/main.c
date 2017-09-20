#include <msp430.h> 


/**
 * main.c
 */
int main(void)
{
    WDTCTL = WDTPW | WDTHOLD;   // stop watchdog timer
    PM5CTL0 &= ~LOCKLPM5;  // Disable the GPIO power-on default high-impedance mode

    P1DIR=0x01;//sets p1 bit 0 as an output
    P1SEL0=0x00;//sets p1 bit 0 for I/O
    P1SEL1=0x00;//sets p1 bit 0 for I/O

    P9DIR=BIT7;//sets p9 bit 7 as an output
    P9SEL0=0x00;//sets p9 bit 7 for I/O
    P9SEL1=0x00;//sets p9 bit 7 for I/O


    P1OUT=0x00;//clears p1 before use
    P9OUT=0x00;//clears p9 before use

    while(1){
                P9OUT&=~BIT7;// turns led 2 off
            _delay_cycles(50000);//delays 100000 cycles
                P1OUT&=~0x01;// turns led 1 off
            _delay_cycles(50000);//delays 100000 cycles
                P9OUT|=BIT7;// turns led 2 on
            _delay_cycles(50000);//delays 100000 cycles
                P1OUT|=0x01;// turns led 1 on
            _delay_cycles(50000);//delays 100000 cycles
        }

}
