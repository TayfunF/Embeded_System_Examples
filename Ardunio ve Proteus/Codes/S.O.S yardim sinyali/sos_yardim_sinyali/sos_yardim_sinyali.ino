int pin=2;
void setup() {
  pinMode(pin,OUTPUT);
}

void loop() {
  //S icin
  for(int x=0; x<3; x++){
    digitalWrite(pin,HIGH);
    delay(150);
    digitalWrite(pin,LOW);
    delay(500);
  }
  delay(500);
  for(int x=0; x<3; x++){
    digitalWrite(pin,HIGH);
    delay(400);
    digitalWrite(pin,LOW);
    delay(100);
  }
  delay(500);
  for(int x=0; x<3; x++){
    digitalWrite(pin,HIGH);
    delay(150);
    digitalWrite(pin,LOW);
    delay(100);
  }
  delay(3000);

}
