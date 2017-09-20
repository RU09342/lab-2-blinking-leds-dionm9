#include <msp430.h> 


/**
 * main.c
 */
int main(void)
{

    WDTCTL = WDTPW | WDTHOLD;   // stop watchdog timer
    PM5CTL0 &= ~LOCKLPM5;                   // Disable the GPIO power-on default high-impedance mode

    P1DIR |= 0x01; // set P1 bit 0 for output
    P1SEL1=0x00; //select p1 for I/O
    P1SEL0=0x00; //select p1 for I/O

    P1OUT=0x00; //clear p1 before use

    while(1){

        _delay_cycles(50000); //delay 50000 cycles
            P1OUT=0x00; //turn LED off
        _delay_cycles(50000); //delay 50000 cycles
            P1OUT=0x01; //turn LED on
    }
};
