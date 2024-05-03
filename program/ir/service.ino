void searchAndSend () {
  if(IrReceiver.decode()){
      if(compare(IrReceiver.decodedIRData, last)){
        IrSender.sendSamsung(last.destination.address, last.destination.command, 3);
        blinkLED(1, 10);
        IrReceiver.resume();
        return;
      }
      current = lookup(IrReceiver.decodedIRData);
      last = current;
      if(current.source.address != 0){
        IrSender.sendSamsung(current.destination.address, current.destination.command, 3);
      }
    }
    IrReceiver.resume();
}

void changeMode() {
  if(mode == 0){
    mode = 1;
   
  } else {
    mode = 0;

  }
}

int compare (IRData data, command two) {
  if(data.command == two.source.command && data.address == two.source.address){
    return 1;
  } else {
    return 0;
  }
}


void choseFunction () {
  int pressTime = millis();
    int releaseTime = millis();
    while(digitalRead(INT_PIN) == LOW){
      releaseTime = millis();
    }
    if((releaseTime - pressTime)  <= 2000){
       program();
    } else {
      erase();
    }
}

 


void program() {
  digitalWrite(4, HIGH);
  
  command instance;
  IrReceiver.resume();
  while(1){
    if(IrReceiver.decode() && IrReceiver.decodedIRData.address != 0 && !(IrReceiver.decodedIRData.protocol == 0) && !(IrReceiver.decodedIRData.command == 0) ){
        //Serial.println("if 1");
        instance.source = IrReceiver.decodedIRData;
        IrReceiver.resume();
        break; 
    }
    if(mode == 0){
      digitalWrite(4, LOW);
      return(0);
    }
  }
  IrReceiver.resume();
  blinkLEDrev(2, 250);
  

  while(1){
        if(IrReceiver.decode()  && !(IrReceiver.decodedIRData.command == instance.source.command) && IrReceiver.decodedIRData.address != 0 && !(IrReceiver.decodedIRData.protocol == 0) && !(IrReceiver.decodedIRData.command == 0)){
        //Serial.println("if 2");
        instance.destination = IrReceiver.decodedIRData;
        IrReceiver.resume();
        break;
    } 
    IrReceiver.resume();
    
  }
  mode = 1;
  delay(1000);
  writeCommand(instance);
  //listEEPROM(10);
}

void blinkLED (int n, int del) {
  for(int i = 0; i < n; i++){
    digitalWrite(4, HIGH);
    delay(del);
    digitalWrite(4, LOW);
    delay(del);
  }
}

void blinkLEDrev (int n, int del) {
  for(int i = 0; i < n; i++){
    digitalWrite(4, LOW);
    delay(del);
    digitalWrite(4, HIGH);
    delay(del);
  }
}
