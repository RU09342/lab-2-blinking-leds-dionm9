#include <msp430.h> 


/**
 * main.c
 */
int main(void)
{

    WDTCTL = WDTPW | WDTHOLD;   // stop watchdog timer
    PM5CTL0 &= ~LOCKLPM5;                   // Disable the GPIO power-on default high-impedance mode


    P1DIR|=0x03;
    P1SEL1|=0x00;
    P1SEL0|=0x00;

    P1OUT=0x00;

    while(1){
        P1OUT&=~0x01;
        P1OUT&=~0x02;
        _delay_cycles(50000);
            P1OUT|=0x01;
        _delay_cycles(50000);
            P1OUT=0x02;
        _delay_cycles(50000);
            P1OUT|=0x01;
        _delay_cycles(50000);
    }
};
