#include <msp430.h> 


/**
 * main.c
 */
int debounce(int port, int bit){ //function to stop button from bouncing (turning on and off rapidly)
    int count; //number that is used to determine if button is pressed
    count =25;//sets it to 25

    while(1){ //stays in loop while button status is being calculated
        if((count==50)){ //check if button is pressed
                count=0;//resets count
                return 1;//return 1 to indicate button is pressed and exits program
                }
        if ((count==0)){ //checks if button is pressed
                count=0; //resets count variable
                return 0; //returns 0 to indicate button is not pressed
                }
        if(port&bit){//checks if button is pressed at a specific moment
            count++;//adds one to count
        }
        else{ //checks if button is not pressed
            count--; //subtracts one from count
        }

    }
}
int main(void)
{
//configure press variable
    int press; //integer to indicate if button is switched on
        press=0; //sets button to "off" position
//initialize device
    WDTCTL = WDTPW | WDTHOLD;   // stop watchdog timer
    PM5CTL0 &= ~LOCKLPM5;// Disable the GPIO power-on default high-impedance mode
//initialize LED 1
    P1DIR |= 0x01; // sets P1.0 for output
    P1SEL1=0x00;// sets P1.0 to I/O
    P1SEL0=0x00;//sets P1.0 to I/O
    P1OUT=0x00; //clears P1.0 out before use
//configure button 1
    P5REN|=BIT5; //enables resistor for P1.5
    P5DIR&=~BIT5; // sets P1.5 for input
    P5SEL1&=~BIT5; //sets P1.5 for I/O
    P5SEL0&=~BIT5; //sets P1.5 for I/O
    P5OUT|=BIT5; // sets P1.5 resistor for pull up

    while(1){//infinite loop
        if(debounce(~P5IN,BIT5)&~press) //determines if button was pressed
              {
                    P1OUT^=BIT0; //switches led if button was pressed
                    press=1; //indicates button is pressed so the program does not go into a loop
              }
        if(debounce(P5IN,BIT5)) { //checks if button is released
                      press=0;//indicates button is in off position

                      }

    }
};
