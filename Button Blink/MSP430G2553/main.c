#include <msp430.h> 


/**
 * main.c
 */
int main(void)
{

    WDTCTL = WDTPW | WDTHOLD;   // stop watchdog timer

    P1DIR |= 0x01; //sets p1 bit 0 to 1 for output
    P1SEL2|=0x00; //sets p1 bit 0 to 0 for I/O
    P1SEL|=0x00; //sets p1 bit 0 to 0 for I/O

    P1OUT|=0x00; //clears p1 before use

    P1DIR&=~BIT3; //sets p1 bit 3 to 0 for button Input
    P1SEL&=~BIT3; //sets p1 bit 3 to 0 for I/O
    P1SEL2&=~BIT3; //sets p1 bit 3 to 0 for I/O
    P1REN|=BIT3; //enables p1 bit 3 resistor for use
    P1OUT|=BIT3; //sets p1 bit 3 resistor to pull up resistor

    while(1){
      if(~P1IN&BIT3) //turns on LED if button is pressed
          {
                P1OUT^=BIT0; //switches led on or off
          }

    }
};
