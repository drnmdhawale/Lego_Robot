// Wire Slave Sender
// by Nicholas Zambetti <http://www.zambetti.com>

// Demonstrates use of the Wire library
// Sends data as an I2C/TWI slave device
// Refer to the "Wire Master Reader" example for use with this

// Created 29 March 2006

// This example code is in the public domain.

// This code was written by Nandkishor Motiram Dhawale, On June 22nd 2012.
// This code is written to read a data from a customised load cell sensor developed using Arduino platform and 
// intefaced with Lego NXT Robotic Platform
// The problem statement was given by the my doctoral advisor Dr. V.I. Adamchuk from Department of
// Bioresource Engineering at McGill University, Macdonalds Campus. Ste-Anne-de-Bellevue, QC. Canada


#include <Wire.h>

int sensorPin = A0;    // select the input pin for the potentiometer
int sensorValue = 0;  // variable to store the value coming from the sensor
byte sendbuffer[] = {0};

void setup()
{
  Wire.begin(2);                // join i2c bus with address #2
  Wire.onRequest(requestEvent); // register event
}

void loop()
{
  sensorValue = analogRead(sensorPin)/2;  
  delay(500);
}

// function that executes whenever data is requested by master
// this function is registered as an event, see setup()
void requestEvent()
{
  sendbuffer[0] = sensorValue;
  Wire.write(sendbuffer, 1);  // respond with message of 6 bytes
}                           // as expected by master
