#include <msp430.h> 


/**
 * main.c
 */
int main(void)
{
    WDTCTL = WDTPW | WDTHOLD;   // stop watchdog timer
    PM5CTL0 &= ~LOCKLPM5;  // Disable the GPIO power-on default high-impedance mode


    P1DIR|=0x01; //sets p1 bit 0 as output
    P1SEL0|=0x00; //sets p1 bit 0 as I/O
    P1SEL1|=0x00; //sets p1 bit 0 as I/O

    P1OUT=0x00; //clears p1out before use

    P1DIR&=~BIT1; //sets p1 bit 1 as input
    P1SEL0&=~BIT1; //sets p1 bit 1 for I/O
    P1SEL1&=~BIT1;//sets p1 bit 1 for I/O
    P1REN=BIT1;//enables p1 bit 1 resistor

    P1OUT|=BIT1; //sets p1 bit 1 resistor as pull up




    while(1){
              if(~P1IN&BIT1) //checks if button is pressed
                  {
                        P1OUT^=BIT0; //switches led if button is pressed
                  }

        }
}
