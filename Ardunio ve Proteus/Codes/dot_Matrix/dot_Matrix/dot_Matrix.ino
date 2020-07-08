#include <TimerOne.h>
int latchPin=8;
int clockPin=12;
int dataPin=11;
byte led[8];

void setup(){
  pinMode(latchPin,OUTPUT);
  pinMode(clockPin,OUTPUT);
  pinMode(dataPin,OUTPUT);
  led[0]=B11111111;
  led[1]=B01000010;
  led[2]=B10100101;
  led[3]=B10000001;
  led[4]=B10100101;
  led[5]=B10011001;
  led[6]=B01000010;
  led[7]=B00111100; 
  Timer1.initialize(10000);
  Timer1.attachInterrupt(ekran);
}
void loop(){
for(int i=0; i<8; i++){
    led[i]=~led[i];
}
delay(500);
}
void ekran(){
  byte row=B11111111;
  for(byte k=0; k<9; k++){
    digitalWrite(latchPin,LOW);
    kaydir(~led[k]);
    kaydir(row);  
    digitalWrite(latchPin,HIGH);
    row = row<<1;
  }
}
void kaydir(byte veri){
  boolean pinDurumu;
  digitalWrite(dataPin,LOW);
  for(int i=0; i<8; i++){
    digitalWrite(clockPin,LOW);
    if(veri&(1<<i)){
      pinDurumu=HIGH;
    }
    else{
      pinDurumu=LOW;
    }
    digitalWrite(dataPin,pinDurumu);
    digitalWrite(clockPin,HIGH);
    digitalWrite(dataPin,LOW);
  }
  digitalWrite(clockPin,LOW);
}


























/*#include <TimerOne.h>
int latchPin = 8;   //U1 = 12. Pin
int dataPin = 11;  //U1 = 14. Pin
int clockPin = 12;   //U1 = 11. Pin
byte noktalar [8];  

void setup() {
 pinMode(latchPin,OUTPUT);
 pinMode(clockPin,OUTPUT);
 pinMode(dataPin,OUTPUT);  
 noktalar[0] = B11111111;
 noktalar[1] = B10000001;
 noktalar[2] = B10111101;
 noktalar[3] = B10100101;
 noktalar[4] = B10100101;
 noktalar[5] = B10111101;
 noktalar[6] = B10000001;
 noktalar[7] = B11111111; 
 Timer1.initialize(10000);
 Timer1.attachInterrupt(ekran);
}

void loop() {
 for(int i=0; i<8; i++){
  noktalar[i]=~noktalar[i];
 }
 delay(500);
}
void ekran(){
  byte row=B10000000;
  for(byte k=0; k<9; k++){
    digitalWrite(latchPin,LOW);
    shiftIt(~noktalar[k]);
    shiftIt(row);
    digitalWrite(latchPin,HIGH);
    row=row<<1;
  }
}
void shiftIt(byte dataOut){
  boolean pinState;
  digitalWrite(dataPin,LOW);
  for(int i=0; i<8; i++){
    digitalWrite(clockPin,LOW);
    if(dataOut & (1<<i)){
      pinState=HIGH;
    }
    else{
      pinState =LOW;
    }
  digitalWrite(dataPin,pinState);
  digitalWrite(clockPin,HIGH);
  digitalWrite(dataPin,LOW);
  }
  digitalWrite(clockPin,LOW);
}*/
