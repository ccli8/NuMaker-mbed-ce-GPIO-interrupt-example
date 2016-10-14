// NuMaker-PFM-NUC472 : GPIO interrupt to set led on/off
#include "mbed.h"

InterruptIn button(PG_1); // D0 
DigitalOut led(LED1);     // flashing LED1(rgbled1)

void flip() {
    led = !led;
}

int main() {
    button.rise(&flip); // if D0 is floating, then rgbled will be flashing
}
