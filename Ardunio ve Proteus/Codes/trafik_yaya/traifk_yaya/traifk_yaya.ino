int araba_kirmizi=12;
int araba_sari=11;
int araba_yesil=10;
int yaya_kirmizi=9;
int yaya_yesil=8;
int push_button=2;
int crossTime=5000;
unsigned long changeTime;
  void setup() {
pinMode(araba_kirmizi,OUTPUT);
pinMode(araba_sari,OUTPUT);
pinMode(araba_yesil,OUTPUT);
pinMode(yaya_kirmizi,OUTPUT);
pinMode(yaya_kirmizi,OUTPUT);
pinMode(push_button,INPUT);
digitalWrite(araba_yesil,HIGH);
digitalWrite(yaya_kirmizi,HIGH);
}

  void loop() {
int durum=digitalRead(push_button);
if(durum==HIGH && (millis()-changeTime)>5000){
  isiklariDegis();     
  }
}

  void isiklariDegis(){
digitalWrite(araba_yesil,LOW);
digitalWrite(araba_sari,HIGH);
delay(2000);
digitalWrite(araba_sari,LOW);
digitalWrite(araba_kirmizi,HIGH);
delay(1000);
digitalWrite(yaya_kirmizi,LOW);
digitalWrite(yaya_yesil,LOW);
delay(crossTime);

for(int x=0; x<10; x++){ //Yayaya ikaz veriyoruz. Sure dolmak uzere karsiya gec.
  digitalWrite(yaya_yesil,HIGH);
  delay(250);
  digitalWrite(yaya_yesil,LOW);
  delay(250);
}
digitalWrite(yaya_kirmizi,HIGH);
delay(500);
digitalWrite(araba_sari,HIGH);
digitalWrite(araba_kirmizi,LOW);
delay(1000);
digitalWrite(araba_yesil,HIGH);
digitalWrite(araba_sari,LOW);
changeTime=millis();

}
  
