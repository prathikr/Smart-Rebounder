const int stepPin = 3; 
const int dirPin = 4; 
const int pulseLen = 900;
const int manualDelay = 600;
const int rightPin = 11;
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
  pinMode(rightPin, INPUT);
  pinMode(leftPin, INPUT);
}



void loop() {
  // put your main code here, to run repeatedly:
  long diff = goal - current;


  if(diff > 5 ) { // move right, OR push button 
    digitalWrite(dirPin,LOW);
    digitalWrite(stepPin,HIGH);
    delayMicroseconds(pulseLen);
    digitalWrite(stepPin,LOW);
    delayMicroseconds(pulseLen);
    current += 1;
  } else if (diff < -5 ) { // move left OR push button
    digitalWrite(dirPin,HIGH);
    digitalWrite(stepPin,HIGH);
    delayMicroseconds(pulseLen);
    digitalWrite(stepPin,LOW);
    delayMicroseconds(pulseLen);
    current -= 1;
  }
  else if(digitalRead(rightPin) == LOW && digitalRead(leftPin) != LOW){
    digitalWrite(dirPin,HIGH);
    
    for(int x = 0; x < 100; x++){
      digitalWrite(stepPin,HIGH);
      delayMicroseconds(manualDelay);
      digitalWrite(stepPin,LOW);
      delayMicroseconds(manualDelay);
    }
  }
  else if(digitalRead(leftPin) == LOW && digitalRead(rightPin) != LOW){
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
    goal += received.val*2;
  }
}
