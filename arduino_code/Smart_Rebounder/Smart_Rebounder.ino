
//#include <SR04.h>
#include <SR04.h>

// defines pins numbers
const int stepPin = 3; 
const int dirPin = 4; 

//#include "SR04.h"                         //Values
#define TRIG_PIN 12                       //for
#define ECHO_PIN 11                       //Sensor
SR04 sr04 = SR04(ECHO_PIN,TRIG_PIN);      //Subject for
long a;                                   //Removal
 
void setup() {
  // Sets the two pins as Outputs
  Serial.begin(9600);
  delay(100);
  pinMode(stepPin,OUTPUT); 
  pinMode(dirPin,OUTPUT);
}
void loop() {
  
  read_distance();
   
  digitalWrite(dirPin,HIGH); // Enables the motor to move in a particular direction
  // Makes 200 pulses for making one full cycle rotation
  for(int x = 0; x < a*5; x++) {
    digitalWrite(stepPin,HIGH); 
    delayMicroseconds(500); 
    digitalWrite(stepPin,LOW); 
    delayMicroseconds(500); 
  }
  delay(100); // One second delay

  a = a*-1;
  if (a < 0) {
    digitalWrite(dirPin,LOW); //Changes the rotations direction
    // Makes 400 pulses for making two full cycle rotation
    for(int x = 0; x < a*-5; x++) {
      digitalWrite(stepPin,HIGH);
      delayMicroseconds(500);
      digitalWrite(stepPin,LOW);
      delayMicroseconds(500);
    } 
  }
}

void read_distance(void) {
 a=sr04.Distance();                //Code for
  Serial.print(a);                 //Determining
  Serial.println("cm");            //and printing
  delay(1000);                     //Distance from Sesnor
}