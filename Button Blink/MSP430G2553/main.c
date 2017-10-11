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
//initialize LED 1
    P1DIR|= 0x01; //sets P1.0 to 1 for output
    P1SEL2|=0x00; //sets P1.0 to 0 for I/O
    P1SEL|=0x00; //sets P1.0 to 0 for I/O
    P1OUT|=0x00; //clears P1.0 before use
//configure button 1
    P1DIR&=~BIT3; //sets P1.3 to 0 for button Input
    P1SEL&=~BIT3; //sets P1.3 to 0 for I/O
    P1SEL2&=~BIT3; //sets P1.3 to 0 for I/O
    P1REN|=BIT3; //enables P1.3 resistor for use
    P1OUT|=BIT3; //sets P1.3 resistor to pull up resistor

    while(1){//infinite loop
      if(debounce(~P1IN,BIT3)&~press) //turns on LED if button is pressed
          {
                P1OUT^=BIT0; //switches led on or off
                press=1; //indicates button is in on position
          }
      if(debounce(P1IN,BIT3)) { //checks if button is released
                press=0;//indicates button is in off position

            }

    }
};
