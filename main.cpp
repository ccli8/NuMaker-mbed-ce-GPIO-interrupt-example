// NuMaker-PFM-NUC472 : GPIO interrupt to set led on/off
#include "mbed.h"
#if defined(TARGET_NUMAKER_PFM_NUC472)
InterruptIn button(SW1);    // Button SW1
DigitalOut led(LED1);       // flashing LED1(rgbled1)
#elif defined(TARGET_NUMAKER_PFM_M453)
InterruptIn button(SW1);    // Button SW1
DigitalOut led(LED1);       // flashing LED1(rgbled1)
#endif

void flip() {
    led = !led;
}

int main() {
    button.rise(&flip);
}
