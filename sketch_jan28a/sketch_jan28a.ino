#include <SoftwareSerial.h>
  
void setup()
{
  Serial.begin(9600);
}

void loop()
{
  if (Serial.available()) {
    int inByte = (int)Serial.read();
    Serial.write(inByte);
  }
}
