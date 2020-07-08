int kirmizi=10;
int sari=9;
int yesil=8;
void setup() {
pinMode(kirmizi,OUTPUT);
pinMode(sari,OUTPUT);
pinMode(yesil,OUTPUT);
}

void loop() {
digitalWrite(kirmizi,HIGH);
digitalWrite(sari,LOW);
digitalWrite(yesil,LOW);
delay(1000);
digitalWrite(kirmizi,LOW);
digitalWrite(sari,HIGH);
digitalWrite(yesil,LOW);
delay(1000);
digitalWrite(kirmizi,LOW);
digitalWrite(sari,LOW);
digitalWrite(yesil,HIGH);
delay(2000);
}
