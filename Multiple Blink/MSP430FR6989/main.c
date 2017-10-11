#include <msp430.h> 


/**
 * main.c
 */
int main(void)
{
    WDTCTL = WDTPW | WDTHOLD;   // stop watchdog timer
    PM5CTL0 &= ~LOCKLPM5;  // Disable the GPIO power-on default high-impedance mode

    P1DIR=0x01;//sets p1 bit 0 as an output
    P1SEL0=0x00;//sets p1 bit 0 for I/O
    P1SEL1=0x00;//sets p1 bit 0 for I/O

    P9DIR=BIT7;//sets p9 bit 7 as an output
    P9SEL0=0x00;//sets p9 bit 7 for I/O
    P9SEL1=0x00;//sets p9 bit 7 for I/O


    P1OUT=0x00;//clears p1 before use
    P9OUT=0x00;//clears p9 before use

    int count =0; //initialize count to 0
    while(1){
            count+=1;//increments count
            if (count%2500==0)//checks if count is divisable by 5000
                P1OUT^=BIT0;//toggles LED 1
            if (count%5000==0)//checks if count is divisable by 2500
                P9OUT^=BIT7;//toggles LED 2
            if(count==5000)//checks if count is 50000
                count=0;//sets count back to 0
        }

}
