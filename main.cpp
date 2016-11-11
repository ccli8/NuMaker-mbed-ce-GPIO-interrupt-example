// NuMaker-PFM-NUC472 : GPIO interrupt to set led on/off
#include "mbed.h"

InterruptIn button(SW1);    // Button SW1
DigitalOut led(LED1);       // flashing LED1(rgbled1)

void flip() {
    led = !led;
}

int main() {
    button.rise(&flip);
}
