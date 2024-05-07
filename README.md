# Ambrosia
This repo holds the code to operate a haptic driver for vibrations and lighting simultaneously depending on the setting of a sliding potentiometer
as well as the code for the website that documents our design process. The source of the website is Bootstrap.

**Detailed description of the code:**
The code works by taking input of the potentiometer on the A0 analog pin of the arduino. In the setup section, the haptic driver is set up to work and library 1 for controls. We configure pin 9 on the Arduino UNO to be our output pin which controls the lights and vibrations. The values from slider potentiometer (0-1024) are mapped to pwm value (0-255) and this is what is read by the external led's on the vest directly. For the vibrations though, we configured 4 modes of vibrations based on which bucket the value from the potentiometer fell into. We did this since if we just used the original values from the potentiometer the vibrations were either too feeble or too strong. The way we vary the vibrations is by decreasing the delay between the waveforms as the slider is moved up.
