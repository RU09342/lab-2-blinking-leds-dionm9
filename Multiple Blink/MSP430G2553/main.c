#include <msp430.h> 


/**
 * main.c
 */
int main(void)
{

    WDTCTL = WDTPW | WDTHOLD;   // stop watchdog timer

    P1DIR |= 0x01; //sets p1 bit 0 as an output
    P1SEL2|=0x00; //sets p1 bit 0 for I/O
    P1SEL|=0x00;//sets p1 bit 0 for I/O

    P1DIR |= BIT6;//sets p1 bit 6 as an output
    P1SEL2&=~BIT6;//sets p1 bit 6 for I/O
    P1SEL&=~BIT6;//sets p1 bit 6 for I/O

    P1OUT=0x00;//clears p1 before use

    while(1){
             P1OUT|=BIT0;//turns on led 1
             _delay_cycles(100000);//delays 100000 cycles
                 P1OUT|=BIT6;//turns on led 2
             _delay_cycles(100000);//delays 100000 cycles
                 P1OUT&=~BIT0;//turns off led 1
             _delay_cycles(100000);//delays 100000 cycles
                 P1OUT&=~BIT6;//turns off led 2
             _delay_cycles(100000);//delays 100000 cycles
         }
};
