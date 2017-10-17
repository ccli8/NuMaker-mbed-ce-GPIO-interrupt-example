// GPIO interrupt to set led on/off
#include "mbed.h"

#if defined(TARGET_NUMAKER_PFM_NUC472)
InterruptIn button(SW1);
DigitalOut led(LED1);
#elif defined(TARGET_NUMAKER_PFM_M453)
InterruptIn button(SW2);
DigitalOut led(LED1);
#elif defined(TARGET_NUMAKER_PFM_M487)
InterruptIn button(SW2);
DigitalOut led(LED1);
#elif defined(TARGET_NUMAKER_PFM_NANO130)
InterruptIn button(SW2);
DigitalOut led(LED1);
#endif

void flip() {
    led = !led;
}

int main() {
    button.rise(&flip);
}
