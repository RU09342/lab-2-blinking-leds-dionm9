#include <msp430.h> 


/**
 * main.c
 */
int main(void)
{

    WDTCTL = WDTPW | WDTHOLD;   // stop watchdog timer
//initialize LED
    P1DIR|=0x01; // set P1 bit 0 for output
    P1SEL2=0x00; //select p1 for I/O
    P1SEL=0x00; //select p1 for I/O
    P1OUT=0x00; //clear p1 before use

    while(1){//infinite loop
//cycle LED
        _delay_cycles(50000); //delay 50000 cycles
            P1OUT^=BIT0; //toggle LED
        _delay_cycles(50000); //delay 50000 cycles
            P1OUT^=BIT0; //toggle LED
    }
};
