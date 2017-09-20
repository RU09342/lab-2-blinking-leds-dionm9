#include <msp430.h> 


/**
 * main.c
 */
int main(void)
{
    WDTCTL = WDTPW | WDTHOLD;   // stop watchdog timer

    P1DIR=0x01;//sets p1 bit 0 as an output
    P1SEL=0x00;//sets p1 bit 0 for I/O

    P4DIR=BIT7;//sets p4 bit 7 for output
    P4SEL=0x00;//sets p4 bit 7 for I/O

    P1OUT=0x00;//clears p1 before use
    P4OUT=0x00;//clears p4 before use
	while(1){
	            P1OUT|=BIT0;// turns led 1 on
	        _delay_cycles(100000);//delays 100000 cycles
	            P4OUT|=BIT7;//turns led 2 on
	        _delay_cycles(100000);//delays 100000 cycles
	            P1OUT&=~BIT0;//turns led 1 off
	        _delay_cycles(100000);//delays 100000 cycles
	            P4OUT&=~BIT7;
	        _delay_cycles(100000);//delays 100000 cycles
	    }
}
