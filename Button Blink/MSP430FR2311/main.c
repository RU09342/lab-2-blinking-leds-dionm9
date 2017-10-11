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
	PM5CTL0 &= ~LOCKLPM5; // Disable the GPIO power-on default high-impedance mode
//initialize LED 1
    P1DIR|=BIT0; //set P1.0 for output
    P1SEL0&=~BIT0; //set P1.0 for I/O

//configure button 1
    P1OUT|=BIT1; //selected P1.1 to Vcc for pull up resistor
    P1REN|=BIT1; //enabled P1.1 pull up resistor
    P1DIR&=~BIT1; //set P1.1 for input on bit 1
    P1SEL1&=~BIT1; //sets P1.1 for I/O
    P1SEL0&=~BIT1; //set P1.1 for I/O

    while(1){//infinite loop
           if((debounce(~P1IN,BIT1)&~press)) //checks if button is pressed
                  {
                        P1OUT^=BIT0; //switches led on or off
                        press=1; //indicates button is in on position
                  }
           if(debounce(P1IN,BIT1)) { //checks if button is released
                  press=0;//indicates button is in off position

              }


        }
}

