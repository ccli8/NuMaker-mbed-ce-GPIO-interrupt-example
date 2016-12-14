# Getting started with GPIO interrupt to flash LED on mbed OS


### Import NuMaker-mbed-GPIO_Interrupt from on-line IDE
1. Please choose Nuvoton NuMaker-PFM-XXX as your target platform.
2. Please press the left-up icon "New", then choose "NuMaker GPIO interrupt to flash led1" from the template list.
3. Your NuMaker-mbed-GPIO_Interrupt program is existed.

#### Now compile
Please press compile icon.

#### Burn Code & Execute
1. Connect the board NuMaker-PFM-XXX with your PC by USB cable, then there will be one "mbed" disk.
2. Copy the built binary file into "mbed" disk on you PC.
3. Press device's reset button to execute, press the SW1 button to flash LED.
      
# Example for GPIO IRQ

This is an example for GPIO IRQ with de-bounce enabled.

## Enable GPIO IRQ de-bounce

Add a file *mbed_app.json* with the following configuration

- gpio-irq-debounce-enable. Enable/disable GPIO IRQ de-bounce
    - 0: disable de-bounce
    - 1: enable de-bounce
- gpio-irq-debounce-clock-source. Select clock source as GPIO IRQ de-bounce is enabled.
    - GPIO_DBCTL_DBCLKSRC_IRC10K (NuMaker-PFM-NUC472)
    - GPIO_DBCTL_DBCLKSRC_HCLK (NuMaker-PFM-NUC472/M453)
    - GPIO_DBCTL_DBCLKSRC_LIRC (NuMaker-PFM-M453)
- gpio-irq-debounce-sample-rate. Select delay as GPIO IRQ de-bounce is enabled.
    - GPIO_DBCTL_DBCLKSEL_1
    - GPIO_DBCTL_DBCLKSEL_2
    - GPIO_DBCTL_DBCLKSEL_4
    - ...
    - GPIO_DBCTL_DBCLKSEL_32768
    
### Example: enable GPIO IRQ de-bounce for NuMaker-PFM-NUC472 target
```
{
    "target_overrides": {
        "NUMAKER_PFM_NUC472": {
            "NUC472.gpio-irq-debounce-enable": 1,
            "NUC472.gpio-irq-debounce-clock-source": "GPIO_DBCTL_DBCLKSRC_IRC10K",
            "NUC472.gpio-irq-debounce-sample-rate": "GPIO_DBCTL_DBCLKSEL_16"
        }
    }
}
```

### Example: enable GPIO IRQ de-bounce for NuMaker-PFM-M453 target
```
{
    "target_overrides": {
        "NUMAKER_PFM_M453": {
            "M451.gpio-irq-debounce-enable": 1,
            "M451.gpio-irq-debounce-clock-source": "GPIO_DBCTL_DBCLKSRC_LIRC",
            "M451.gpio-irq-debounce-sample-rate": "GPIO_DBCTL_DBCLKSEL_16"
        }
    }
}
```

## Known issues
- GPIO IRQ de-bounce defaults to disabled. If enabled, communication with GPIO pin as interrupt pin won't fit 
or even fail due to the de-bounce delay.