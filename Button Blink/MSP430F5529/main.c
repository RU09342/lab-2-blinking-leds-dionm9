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
    WDTCTL = WDTPW | WDTHOLD;	// stop watchdog timer
//initialize LED 1
    P1DIR=0x01; //sets P1.0 to 1 for output
    P1SEL=0x00; //sets P1.0 to 0 for I/O
    P1OUT=0x00; // clears P1.0 out before use
//configure button 1
    P2REN|=BIT1; //enables P2.1 resistor for use
    P2DIR&=~BIT1; //sets P2.1 for input
    P2SEL&=~BIT1; //sets P2.1 for I/O
    P2OUT|=BIT1; //sets P2.1 resistor as a pullup resistor

	while(1){//infinite loop
	          if(debounce(~P2IN,BIT1)&~press) //true if button (bit 1) is pressed
	              {
	                    P1OUT^=BIT0; //switches led on or off
	                    press=1; //indicates button is in on position
	              }
	          if(debounce(P2IN,BIT1)) { //checks if button is released
                       press=0;//indicates button is in off position

               }

	    }
	};
