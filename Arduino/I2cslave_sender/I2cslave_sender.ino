/*
  * Adapted from Gatsu's post on Arduino's forums:
  * http://www.arduino.cc/cgi-bin/yabb2/YaBB.pl?num=1262353163
  */
#include <Wire.h>

int ADDRESS = 0x43;   // The Arduino's I2C Address

uint8_t SensorMode[9]  =    "RAWMODE ";
uint8_t SensorType[10] =    "NO_SENSOR";
uint8_t SensorName[9]  =    "Arduino ";

byte x = 0;
byte val = 0;
byte sendbuffer[] = {0};

void setup() {
    Wire.begin(ADDRESS);
    Wire.onReceive(receiveEvent); 
    Wire.onRequest(requestEvent);
    Serial.begin(9600); 
}

void loop() {
  // This could be any code used to read a sensor.
  // In this simple example, we just count up once a second
  val++;
  delay(1000);
}

void receiveEvent(int howMany) {
    if (Wire.available() >0 ) {
        x = Wire.read(); // receive register address (1 byte)
        Serial.print(x); 
    }
}

void requestEvent() { 
    if (x == 0x0A) {   
        Wire.write(SensorMode, 8); 
         Serial.print(x);  
    } 
    else if (x == 0x08) {   
        Wire.write(SensorName, 8); 
    }
    else if (x == 0x00) {
        Wire.write(SensorType, 9); 
         Serial.print(x); 
    }
    else if (x == 0x42) {
        sendbuffer[0] = val;
        Wire.write(sendbuffer, 1); 
         Serial.print(x); 
    }
}
