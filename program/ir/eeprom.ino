void writeCommand(command data){
  command current;
  for(int address = 0; address < (EEPROM.length() - sizeof(command)); address=address+sizeof(command)){
    EEPROM.get(address, current);
    if (current.source.address == 0x00){
      EEPROM.put(address, data);
      blinkLED(2, 100);
      return;
    }
  }
  blinkLED(10, 100);
}


void erase () {
  for (int i = 0 ; i < EEPROM.length() ; i++) {
    EEPROM.update(i, 0);
  }
  blinkLED(10, 100);
}

command lookup (IRData data) {
  command current;
  for(int address = 0; address < (EEPROM.length() - sizeof(command)); address=address+sizeof(command)){
    EEPROM.get(address, current);
    if(compare(data, current)){
      //Serial.println("found");
      blinkLED(1, 100);
      return current;
    } else {
      current.source.address == 0;
    }
  }
}
