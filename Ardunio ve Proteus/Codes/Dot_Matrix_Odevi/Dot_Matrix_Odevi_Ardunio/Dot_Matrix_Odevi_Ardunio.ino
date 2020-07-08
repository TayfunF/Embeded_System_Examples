#include <TimerOne.h>
int sayac=100;
int latchPin = 8;     //Row = 12;
int dataPin = 11;     //Row = 14;
int clockPin = 12;    //Row = 11;
boolean kontrol=0;
byte matrix_indis[8];
byte matrix_sutun[8];
byte sad[8];
                      
  void setup() {
Serial.begin(9600);
pinMode(latchPin,OUTPUT);
pinMode(dataPin,OUTPUT);
pinMode(clockPin,OUTPUT);  
//--------------------------
matrix_indis[0] = B11111110;
matrix_indis[1] = B11111101;
matrix_indis[2] = B11111011;
matrix_indis[3] = B11110111;
matrix_indis[4] = B11101111;
matrix_indis[5] = B11011111;
matrix_indis[6] = B10111111;
matrix_indis[7] = B01111111;
//------------------------------
matrix_sutun[0] = B00111100;
matrix_sutun[1] = B01000010;
matrix_sutun[2] = B10100101;
matrix_sutun[3] = B10000001;
matrix_sutun[4] = B10100101;
matrix_sutun[5] = B10011001;
matrix_sutun[6] = B01000010;
matrix_sutun[7] = B00111100;
//-------------------------------
sad[0] = B00111100;
sad[1] = B01000010;
sad[2] = B10100101;
sad[3] = B10000001;
sad[4] = B10011001;
sad[5] = B10100101;
sad[6] = B01000010;
sad[7] = B00111100;

Timer1.initialize(10000);
Timer1.attachInterrupt(hesapla);
}
void smileFace(){
  for(int x=0; x<8; x++){
    digitalWrite(latchPin,LOW);
    shiftOut(dataPin,clockPin,MSBFIRST,matrix_sutun[x]);
    shiftOut(dataPin,clockPin,MSBFIRST,matrix_indis[x]);
    digitalWrite(latchPin,HIGH);
  }
}
void sadFace(){
  for(int x=0; x<8; x++){
    digitalWrite(latchPin,LOW);
    shiftOut(dataPin,clockPin,MSBFIRST,sad[x]);
    shiftOut(dataPin,clockPin,MSBFIRST,matrix_indis[x]);
    digitalWrite(latchPin,HIGH);
  }
}
void hesapla(){
  sayac--;
  if(kontrol){
    sadFace();
  }
  else{
    smileFace();
  }
  if(sayac==0){
     if(kontrol){
      kontrol=0;
     }
     else{
      kontrol=1;
     }
     sayac=100;
  }
}
void loop() {
}
