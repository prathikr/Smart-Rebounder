
//#include <SR04.h>
//#include <SR04.h>

// defines pins numbers
const int stepPin = A1; 
const int dirPin = A0; 

union stuff{
  long val;
  char buf[4];
};

long goal = 0;
long curr = 0;

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

  if (goal - curr > 0) {
    digitalWrite(dirPin,LOW);
    digitalWrite(stepPin,HIGH);
    delayMicroseconds(500);
    digitalWrite(stepPin, LOW);
    delayMicroseconds(500);
    curr++;
  } else if (goal - curr < 0) {
    digitalWrite(dirPin,HIGH);
    digitalWrite(stepPin,HIGH);
    delayMicroseconds(500);
    digitalWrite(stepPin,LOW);
    delayMicroseconds(500);
    curr--;
  }

}

void read_distance(void) {
  if(Serial.available() == 1) {
    Serial.readBytes(a.buf, 4);
    goal += a.val;  
  }
}
