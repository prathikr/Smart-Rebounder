const int stepPin = 3; 
const int dirPin = 4; 

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
}



void loop() {
  // put your main code here, to run repeatedly:
  long diff = goal - current;
  if(diff > 5) { // move right
    digitalWrite(dirPin,LOW);
    digitalWrite(stepPin,HIGH);
    delayMicroseconds(500);
    digitalWrite(stepPin,LOW);
    delayMicroseconds(500);
    current += 1;
  } else if (diff < -5) { // move left
    digitalWrite(dirPin,HIGH);
    digitalWrite(stepPin,HIGH);
    delayMicroseconds(500);
    digitalWrite(stepPin,LOW);
    delayMicroseconds(500);
    current -= 1;
  }
}

void serialEvent() {
  while (Serial.available()) {
    Serial.readBytes(received.buf, 4);
    goal += received.val*2;
  }
}
