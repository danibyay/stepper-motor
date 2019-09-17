# stepper-motor

Firmware project using HAL architecture to control a stepper motor with multiple interfaces.

The microcontroller used in this project is the 8-bit NXP S08QG8. ([view datasheet](https://www.nxp.com/docs/en/data-sheet/MC9S08QG8.pdf))

## Modules used

* **UART serial interface**: Used to receive commands via a terminal emulator on a PC
* **GPIO**: to output the sequence of the stepper motor
* **ADC**: To act on the temperature sensor's readings
* **Timer**: To control the speed of the motor.

## Commands
Via the serial terminal, the user can control the motor to:

* Turn it ON/OFF
* Modify the speed in RPM
* Set to a certain position measured in degrees
* Set a temperature limit upon which the motor will shut down
* Set the direction of the motor (clockwise or counter clockwise)

## Demo video

Watch the video [here](https://www.youtube.com/watch?v=S4Q5rdi_D0w)
