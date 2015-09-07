int gLeftLedId;
int gLeftSwId;
int gRightLedId;
int gRightSwId;

void setup() {

  gLeftSwId = 1;
  gRightSwId = 2;
  gLeftLedId = 13;
  gRightLedId = 11;
  
  pinMode(gLeftSwId, INPUT);
  pinMode(gRightSwId, INPUT);
  
  pinMode(gRightLedId, OUTPUT);
  pinMode(gLeftLedId, OUTPUT);
}

void loop() {

  //スイッチ動作確認
  //if(digitalRead(gLeftSwId)==HIGH){
  //  digitalWrite(gLeftLedId, LOW);
  //}else{
  //  digitalWrite(gLeftLedId, HIGH);
  //}

  //if(digitalRead(gRightSwId)==HIGH){
  //  digitalWrite(gRightLedId, LOW);
  //}else{
  //  digitalWrite(gRightLedId, HIGH);
  //}

  //LED動作確認
  //digitalWrite(gLeftLedId, HIGH);
  //digitalWrite(gRightLedId, HIGH);
  
  if(digitalRead(gLeftSwId)==HIGH){
    FlashLed(gLeftLedId);
  }else{
    digitalWrite(gLeftLedId, LOW);
  }

  if(digitalRead(gRightSwId)==HIGH){
    FlashLed(gRightLedId);
  }else{
    digitalWrite(gRightLedId, LOW);
  }

}

void FlashLed(int ledId){

  int i;

  for(i=0; i<3; i=i+1){
    analogOn(14, ledId);
    analogOff(14, ledId);
  }

  for(i=0; i<3; i=i+1){
    analogOn(11, ledId);
    analogOff(11, ledId);
  }
  
  for(i=0; i<3; i=i+1){
    analogOn(8, ledId);
    analogOff(8, ledId);
  }

  for(i=0; i<10; i=i+1){
    analogOn(5, ledId);
    analogOff(5, ledId);
  }

  for(i=0; i<10; i=i+1){
    analogOn(2, ledId);
    analogOff(2, ledId);
  }

  for(i=0; i<10; i=i+1){
    analogOn(5, ledId);
    analogOff(5, ledId);
  }

  for(i=0; i<3; i=i+1){
    analogOn(8, ledId);
    analogOff(8, ledId);
  }

  for(i=0; i<3; i=i+1){
    analogOn(11, ledId);
    analogOff(11, ledId);
  }
  
  for(i=0; i<3; i=i+1){
    analogOn(14, ledId);
    analogOff(14, ledId);
  }
  
}

void analogOn(int delayTime, int ledId){
    int i;
    for(i=0; i<256; i=i+10) {
       analogWrite(ledId, i);
       delay(delayTime);
     }
}

void analogOff(int delayTime, int ledId){
  int i;
  for(i=255; i>0; i=i-10) {
    analogWrite(ledId, i);
    delay(delayTime);
  }
}

