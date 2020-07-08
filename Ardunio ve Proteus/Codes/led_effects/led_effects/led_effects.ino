
byte ledPin[]={4,5,6,7,8,9,10,11,12,13}; //pinlerin numaralari tek seferde yazmak icin
int ledDelay(100);
int direction=1;
int currentLED=0;
unsigned long changeTime;
void setup() {
 for(int x=0; x<10; x++){
  pinMode(ledPin[x],OUTPUT);
  changeTime=millis();
 }
}

void loop() {
if((millis()-changeTime)>ledDelay){
  changeLed();
  changeTime=millis();  
  }
}

void changeLed(){
  for(int x=x; x<10; x++){
    digitalWrite(ledPin[x],LOW);
  }
  digitalWrite(ledPin[currentLED],HIGH);
  currentLED=currentLED+direction;
  if(currentLED==9){
    direction=-1;
  }
  if(currentLED==0){
    direction=1;
  }
}
