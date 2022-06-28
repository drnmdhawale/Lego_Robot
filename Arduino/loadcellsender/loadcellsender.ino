#include <NewSoftSerial.h>
#include <Wire.h>
#include <string.h>
#include <ctype.h>
#include <SoftwareSerial.h>
#include <WString.h>
#include <math.h>
#include <stdlib.h>
// Enable/disable debug modes
boolean debug_gps = true;
boolean debug_nxt = true;



#define ADDRESS 0x43

char SensorVersion[15] = "V0.1        /";
char SensorName[15] =    "Load_Cell  /";
char SensorType[15] =    "Digital     /";
char message_2_NXT [15] ="             ";
char message_from_NXT [15] ="             ";
int sensorPin = A0;    // select the input pin for the potentiometer
float V = 0;  
float V1 = 0; 
float  V2 = 0; 
float V3 = 0; 
float V4 = 0; 
float  V5 = 0; 
float  V6 = 0; 
float  V7 = 0; 
float  V8 = 0; 
float  V9 = 0; 
float  V10 = 0; 
float  M = 0;
int W=0;
byte sendbuffer[] = {0};
int ledPin = 5; //LED test pin
int ledPin2 = 6; //LED test pin
char OK1[5]        =    "";
char x;

void setup() {  
 pinMode(ledPin,OUTPUT);
 pinMode(ledPin2,OUTPUT);
 digitalWrite(ledPin, LOW);
 digitalWrite(ledPin2, LOW);
 Wire.begin(ADDRESS);                
 Wire.onReceive(receiveEvent);
 Wire.onRequest(requestEvent);
 Serial.begin(9600);

}

void loop()
{

V1 = analogRead(sensorPin)/2*10+25; 
V2 = analogRead(sensorPin)/2*10+25; 
V3 = analogRead(sensorPin)/2*10+25; 
V4 = analogRead(sensorPin)/2*10+25; 
V5 = analogRead(sensorPin)/2*10+25; 
V6 = analogRead(sensorPin)/2*10+25; 
V7 = analogRead(sensorPin)/2*10+25; 
V8 = analogRead(sensorPin)/2*10+25; 
V9 = analogRead(sensorPin)/2*10+25; 
V10 = analogRead(sensorPin)/2*10+25; 
V=(V1+V2+V3+V4+V5+V6+V7+V8+V9+V10)/10;
M=0.156*V;
W=int(M);
delay(20);
}

//---------------------------------I2C Events-------------------------------//

void receiveEvent(int howMany){
  
  digitalWrite(ledPin2, LOW);
  
    
    if (Wire.available() >0 ) //&& index <15)
    {
    x= Wire.read(); // receive byte as an integer
    digitalWrite(ledPin2, HIGH);
  
    }

}

void requestEvent(){


  if (x == 0x00){
   Wire.write((uint8_t*)SensorVersion,15);
   digitalWrite(ledPin2, HIGH);
 }
 else if (x == 0x08){
   Wire.write((uint8_t*)SensorName,15);
   digitalWrite(ledPin2, HIGH);
 }
 else if (x == 0x10){
   Wire.write((uint8_t*)SensorType,15);
   digitalWrite(ledPin2, HIGH);
 }
 else if (x == 0x42) {
  
  itoa (W,OK1,10);
  Wire.write((uint8_t*)OK1, 4);
  Serial.println(W); 
  digitalWrite(ledPin2, HIGH);
 }
  digitalWrite(ledPin2, LOW);
}


 
