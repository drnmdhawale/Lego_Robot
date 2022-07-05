// Wire Master Reader
// by Nicholas Zambetti <http://www.zambetti.com>

// Demonstrates use of the Wire library
// Reads data from an I2C/TWI slave device
// Refer to the "Wire Slave Sender" example for use with this

// Created 29 March 2006

// This example code is in the public domain.
// This code was written by Nandkishor Motiram Dhawale, On June 22nd 2012.
// This code is written to read a data from a customised load cell sensor developed using Arduino platform and 
// intefaced with Lego NXT Robotic Platform
// The problem statement was given by the my doctoral advisor Dr. V.I. Adamchuk from Department of
// Bioresource Engineering at McGill University, Macdonalds Campus. Ste-Anne-de-Bellevue, QC. Canada


#include <Wire.h>

void setup()
{
  Wire.begin();        // join i2c bus (address optional for master)
  Serial.begin(9600);  // start serial for output
}

void loop()
{
  Wire.requestFrom(2, 1);    // request 6 bytes from slave device #2

  while(Wire.available())    // slave may send less than requested
  { 
    byte c = Wire.read(); // receive a byte as character
    Serial.print(c);         // print the character
  }

  delay(500);
}
