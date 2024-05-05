#include <Wire.h>
#include "Adafruit_DRV2605.h"
/** This code drives the haptic motor and controls lights according to the value (0 to 1024) 
on a slider. The vibrations are divided into 4 modes  */
Adafruit_DRV2605 drv; //including the package for the haptic driver
int potPin = A0; //This is the pin that reads input from potentiometer
int ledPin = 9; // This is the pin that controls the output of the led depending on the input from potentiometer
int rawValue;// variable to record raw value from the potentiometer

void setup() {
  //setting up the haptic driver
  Serial.begin(9600); // Sets the data rate in bits per second (baud) for serial data transmission to be 9600
  Serial.println("DRV test");
  drv.begin();//begin driver operation
    
  // I2C trigger by sending 'go' command 
  drv.setMode(DRV2605_MODE_INTTRIG); // default, internal trigger when sending GO command

  drv.selectLibrary(1);// select 1 to be the library we use for the haptic motor 
 
}

void loop() {
    drv.go(); // start driving
  int rawValue = analogRead(potPin); // read raw value from slider pot
  int bucket = rawValue * 4 / 1000; // divide the raw value into 4 buckets for 4 modes of vibrations
 
  int outputValue = map(rawValue, 0, 1023, 0, 255); //Convert from 0-1023 proportional to the number of a number of from 0 to 255
  Serial.print("Output: "); 
  Serial.println(outputValue); 
  analogWrite(ledPin, outputValue); //turn the LED on depending on the output value (0 - 255)
/** Depending on the value of the bucket, we vary intensity of the vibrations by decreasing 
the delay in between waveforms as the slider is moved up */
  if (bucket > 0){
  drv.setWaveform(0, 16); 
      delay(1250); 
  }
if (bucket > 1){
   drv.setWaveform(0, 16); 
      delay(1000);   
  }
  if (bucket > 2){
   drv.setWaveform(0, 16); 
      delay(750);  
  }if (bucket > 3){
 
  drv.setWaveform(0, 16); 
      delay(500); 
 
  }
  

   
}
