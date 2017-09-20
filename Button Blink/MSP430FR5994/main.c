#include <msp430.h> 


/**
 * main.c
 */
int main(void)
{

    WDTCTL = WDTPW | WDTHOLD;   // stop watchdog timer
    PM5CTL0 &= ~LOCKLPM5;                   // Disable the GPIO power-on default high-impedance mode


    P1DIR |= 0x01; // sets p1 bit 0 for output
    P1SEL1=0x00;// sets p1 bit 0 to I/O
    P1SEL0=0x00;//sets p1 bit 0 to I/O

    P5REN|=BIT5; //enables resistor for p1 bit 5
    P5DIR&=~BIT5; // sets p1 bit 5 for input
    P5SEL1&=~BIT5; //sets p1 bit 5 for I/O
    P5SEL0&=~BIT5; //sets p1 bit 5 for I/O
    P5OUT|=BIT5; // sets p1 bit 5 resistor for pull up

    P1OUT=0x00; //clears p1 out before use

    while(1){
        if(~P5IN&BIT5) //determines if button was pressed
              {
                    P1OUT^=BIT0; //switches led if button was pressed
              }

    }
};
