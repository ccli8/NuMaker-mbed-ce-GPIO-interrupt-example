# Example for GPIO interrupt with debounce on Nuvoton's Mbed CE enabled boards

This is an example for GPIO IRQ with debounce enabled.

## Support development tools

Use cmake-based build system.
Check out [hello world example](https://github.com/mbed-ce/mbed-ce-hello-world) for getting started.

> **⚠️ Warning**
>
> Legacy development tools below are not supported anymore.
> - [Arm's Mbed Studio](https://os.mbed.com/docs/mbed-os/v6.15/build-tools/mbed-studio.html)
> - [Arm's Mbed CLI 2](https://os.mbed.com/docs/mbed-os/v6.15/build-tools/mbed-cli-2.html)
> - [Arm's Mbed CLI 1](https://os.mbed.com/docs/mbed-os/v6.15/tools/developing-mbed-cli.html)

For [VS Code development](https://github.com/mbed-ce/mbed-os/wiki/Project-Setup:-VS-Code)
or [OpenOCD as upload method](https://github.com/mbed-ce/mbed-os/wiki/Upload-Methods#openocd),
install below additionally:

-   [NuEclipse](https://github.com/OpenNuvoton/Nuvoton_Tools#numicro-software-development-tools): Nuvoton's fork of Eclipse
-   Nuvoton forked OpenOCD: Shipped with NuEclipse installation package above.
    Checking openocd version `openocd --version`, it should fix to `0.10.022`.

## Enable GPIO IRQ debounce

Add a file *mbed_app.json5* with the following configuration

-   gpio-irq-debounce-enable. Enable/disable GPIO IRQ debounce
    -   0: disable debounce
    -   1: enable debounce
-   gpio-irq-debounce-clock-source. Select clock source as GPIO IRQ debounce is enabled.
    -   GPIO_DBCTL_DBCLKSRC_IRC10K (NuMaker-PFM-NUC472)
    -   GPIO_DBCTL_DBCLKSRC_HCLK (NuMaker-PFM-NUC472/M453)
    -   GPIO_DBCTL_DBCLKSRC_LIRC (NuMaker-PFM-M453)
-   gpio-irq-debounce-sample-rate. Select delay as GPIO IRQ debounce is enabled.
    -   GPIO_DBCTL_DBCLKSEL_1
    -   GPIO_DBCTL_DBCLKSEL_2
    -   GPIO_DBCTL_DBCLKSEL_4
    -   ...
    -   GPIO_DBCTL_DBCLKSEL_32768

### Example: enable GPIO IRQ debounce for NuMaker-PFM-NUC472 board

```json5
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

### Example: Eenable GPIO IRQ debounce for NuMaker-PFM-M453 board

```json5
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

## Developer guide

In the following, we take **NuMaker-IoT-M467** board as an example for Mbed CE support.

### Build the example

1.  Clone the example and navigate into it
    ```
    $ git clone https://github.com/mbed-nuvoton/NuMaker-mbed-ce-GPIO-interrupt-example
    $ cd NuMaker-mbed-ce-GPIO-interrupt-example
    $ git checkout -f master
    ```

1.  Deploy necessary libraries
    ```
    $ git submodule update --init
    ```
    Or for fast install:
    ```
    $ git submodule update --init --filter=blob:none
    ```

1.  Compile with cmake/ninja
    ```
    $ mkdir build; cd build
    $ cmake .. -GNinja -DCMAKE_BUILD_TYPE=Develop -DMBED_TARGET=NUMAKER_IOT_M467
    $ ninja
    $ cd ..
    ```

### Flash the image

Flash by drag-n-drop built image `NuMaker-mbed-ce-GPIO-interrupt-example.bin` or `NuMaker-mbed-ce-GPIO-interrupt-example.hex` onto **NuMaker-IoT-M467** board

### Verify the result

Press device's reset button to execute, press the SW1 button to flash LED.
      
## Known issues

-   GPIO IRQ debounce defaults to disabled. If enabled, communication with GPIO pin as interrupt pin won't fit 
    or even fail due to the debounce delay.
