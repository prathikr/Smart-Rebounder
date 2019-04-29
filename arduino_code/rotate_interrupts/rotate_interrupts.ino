const int stepPin = A1; 
const int dirPin = A0; 
const int pulseLen = 900;
const int manualDelay = 600;
const int rightPin = 10;
const int leftPin = 12;


union stuff{
  long val;
  char buf[4];
};

long current = 0;
long goal = 0;
stuff received;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  delay(100);
  pinMode(stepPin, OUTPUT);
  pinMode(dirPin, OUTPUT);
  pinMode(rightPin, INPUT_PULLUP); // Set as input with pull up resistor
  pinMode(leftPin, INPUT_PULLUP);  // Set as input with pull up resistor
}



void loop() {
  // put your main code here, to run repeatedly:
//  long diff = goal - current;
//
//  if(diff < 5 ) { // move right
//    digitalWrite(dirPin,LOW);
//    digitalWrite(stepPin,HIGH);
//    delayMicroseconds(pulseLen);
//    digitalWrite(stepPin,LOW);
//    delayMicroseconds(pulseLen);
//    current += 1;
//  } 
//  else if (diff < -5 ) { // move left 
//    digitalWrite(dirPin,HIGH);
//    digitalWrite(stepPin,HIGH);
//    delayMicroseconds(pulseLen);
//    digitalWrite(stepPin,LOW);
//    delayMicroseconds(pulseLen);
//    current -= 1;
//  }

  if(digitalRead(rightPin) == LOW){ // move with push button
    digitalWrite(dirPin,HIGH);
    
    for(int x = 0; x < 100; x++){
      digitalWrite(stepPin,HIGH);
      delayMicroseconds(manualDelay);
      digitalWrite(stepPin,LOW);
      delayMicroseconds(manualDelay);
    }
  }
  else if(digitalRead(leftPin) == LOW){ // move with push button
    digitalWrite(dirPin,LOW);

    for(int x = 0; x < 100; x++){
      digitalWrite(stepPin,HIGH);
      delayMicroseconds(manualDelay);
      digitalWrite(stepPin,LOW);
      delayMicroseconds(manualDelay);
    }
  }
  
}

void serialEvent() {
  while (Serial.available()) {
    Serial.readBytes(received.buf, 4);
    goal += received.val;
  }
}
