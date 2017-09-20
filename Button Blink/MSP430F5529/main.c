#include <msp430.h> 


/**
 * main.c
 */
int main(void)
{
	WDTCTL = WDTPW | WDTHOLD;	// stop watchdog timer
	
    P1DIR=0x01; //sets p1 bit 0 to 1 for output
    P1SEL=0x00; //sets p1 bit 0 to 0 for I/O

    P1OUT=0x00; // clears p1 out before use

    P2REN|=BIT1; //enables p2 bit 1 resistor for use
    P2DIR&=~BIT1; //sets p2 bit 1 for input
    P2SEL&=~BIT1; //sets p2 bit 1 for I/O
    P2OUT|=BIT1; //sets p2 bit 1 resistor as a pullup resistor

	while(1){
	          if(~P2IN&BIT1) //true if button (bit 1) is pressed
	              {
	                    P1OUT^=BIT0; //switches led on or off
	              }

	    }
	};
