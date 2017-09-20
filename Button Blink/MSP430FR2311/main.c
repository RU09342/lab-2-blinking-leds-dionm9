#include <msp430.h> 


/**
 * main.c
 */
int main(void)
{
	WDTCTL = WDTPW | WDTHOLD;	// stop watchdog timer
	PM5CTL0 &= ~LOCKLPM5;                   // Disable the GPIO power-on default high-impedance mode


    P1DIR|=0x01; //set p1 bit 0 for output
    P1SEL0|=0x00; //set p1 bit 0 for I/O

    P1OUT|=BIT1; //selected Vcc for pull up resistor on bit 1
    P1REN|=BIT1; //enabled pull up resistor on bit 1
    P1DIR&=~BIT1; //set p1 for input on bit 1
    P1SEL1|=0x00; //sets p1 for I/O

    while(1){
              if(~P1IN&BIT1) //turns on LED if button is pressed
                  {
                        P1OUT^=BIT0; //switches led on or off
                  }

        }
}
