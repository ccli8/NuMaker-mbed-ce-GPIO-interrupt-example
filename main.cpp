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
#elif defined(TARGET_NUMAKER_IOT_M487)
InterruptIn button(SW2);
DigitalOut led(LED1);
#elif defined(TARGET_NUMAKER_PFM_NANO130)
InterruptIn button(SW2);
DigitalOut led(LED1);
#elif defined(TARGET_NUMAKER_PFM_M2351)
InterruptIn button(SW2);
DigitalOut led(LED1);
#elif defined(TARGET_NUMAKER_IOT_M263A)
InterruptIn button(PG_4); // Button1 (SW10)
DigitalOut led(LED1);
#elif defined(TARGET_NUMAKER_IOT_M467)
InterruptIn button(BUTTON1);
DigitalOut led(LED1);
#endif

void flip() {
    led = !led;
}

int main() {
#ifdef MBED_MAJOR_VERSION
    printf("Mbed OS version %d.%d.%d\r\n\n", MBED_MAJOR_VERSION, MBED_MINOR_VERSION, MBED_PATCH_VERSION);
#endif
    button.rise(&flip);
}
