# Simple Blink
The function first stop the watch dog timer, exits low power mode 5 (if it is a FR series chip), initializes LED 1 out, then runs in an infinite loop. This loop delays 50000 cycles, then turns the led on, then waits 50000 leds and turns the led off. This then loops continuously. 
