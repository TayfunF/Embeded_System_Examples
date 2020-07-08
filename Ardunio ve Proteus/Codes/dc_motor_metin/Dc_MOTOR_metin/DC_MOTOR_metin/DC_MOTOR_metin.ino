String gelenveri,yon,thiz;
int hiz=150;
void setup() {
  Serial.begin(9600);
  pinMode(11,OUTPUT);
  pinMode(10,OUTPUT);
  pinMode(9,OUTPUT);
  pinMode(8,OUTPUT);
  pinMode(7,OUTPUT);
  pinMode(6,OUTPUT);
  
  digitalWrite(9,LOW);
  digitalWrite(8,LOW);
  digitalWrite(7,LOW);
  digitalWrite(6,LOW);
}

void loop() {
  if(Serial.available()>0){
    gelenveri = Serial.readString();
    yon = gelenveri.substring(0,3);
    //hiz = Serial.parseInt();
    if(yon.equals("sag")){
      sag(hiz);
      Serial.write("Motor saga donuyor....");
    }
    else{
      ileri(hiz);
    }
  }
}
void sag(int hizm){
  Serial.write("Motor saga donuyor....");
  analogWrite(11,255);
  analogWrite(10,255);
  digitalWrite(9,HIGH);
  digitalWrite(8,LOW);
  digitalWrite(7,LOW);
  digitalWrite(6,HIGH);
  delay(3000);
}
void ileri(int hizm){
  analogWrite(11,255);
  analogWrite(10,255);
  digitalWrite(9,HIGH);
  digitalWrite(8,LOW);
  digitalWrite(7,HIGH);
  digitalWrite(6,LOW);
  delay(3000);
}
