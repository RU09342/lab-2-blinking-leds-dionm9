#include <msp430.h> 


/**
 * main.c
 */
int main(void)
{

    WDTCTL = WDTPW | WDTHOLD;   // stop watchdog timer
    PM5CTL0 &= ~LOCKLPM5;                   // Disable the GPIO power-on default high-impedance mode


    P1DIR |= 0x01;
    P1SEL1=0x00;
    P1SEL0=0x00;

    P5REN|=BIT5;
    P5DIR&=~BIT5;
    P5SEL1&=~BIT5;
    P5SEL0&=~BIT5;
    P5OUT|=BIT5;

    P1OUT=0x00;

    while(1){
          if(~P5IN&BIT5)
              {
                    P1OUT|=1;
              }

          else
              {
                  P1OUT=0;
              }

    }
};
