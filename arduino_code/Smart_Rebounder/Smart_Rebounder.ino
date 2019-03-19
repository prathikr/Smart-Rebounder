
//#include <SR04.h>
//#include <SR04.h>

// defines pins numbers
const int stepPin = 3; 
const int dirPin = 4; 

union stuff{
  long val;
  char buf[4];
};

//#include "SR04.h"                         //Values
#define TRIG_PIN 12                       //for
#define ECHO_PIN 11                       //Sensor
//SR04 sr04 = SR04(ECHO_PIN,TRIG_PIN);      //Subject for
stuff a;                                   

void setup() {
  // Sets the two pins as Outputs
  Serial.begin(9600);
  delay(100);
  pinMode(stepPin, OUTPUT);
  pinMode(dirPin, OUTPUT);
}
void loop()
{

  read_distance();

  if (a.val > 0) {
    digitalWrite(dirPin,LOW);
    for(int i = 0; i < abs(a.val); i++) {
      digitalWrite(stepPin,HIGH);
      delayMicroseconds(500);
      digitalWrite(stepPin, LOW);
      delayMicroseconds(500);
    }
  } else {
    digitalWrite(dirPin,HIGH);
    for(int i = 0; i < abs(a.val); i++) {
      digitalWrite(stepPin,HIGH);
      delayMicroseconds(500);
      digitalWrite(stepPin,LOW);
      delayMicroseconds(500);
    }
  }

}

void read_distance(void) {
  while(Serial.available() == 0) {}
  Serial.readBytes(a.buf, 4);
}
