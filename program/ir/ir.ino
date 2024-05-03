#define DECODE_SONY
#define DECODE_SAMSUNG
#define DECODE_NEC


#include <stdlib.h>

#define LED_PIN PB4 

#include <IRremote.h>
#include <EEPROM.h>
#include <avr/io.h>

#define INT_PIN PB1 
#define INTERRUPT_PIN PCINT1
#include <avr/interrupt.h>
#define PCINT_VECTOR PCINT0_vect  

int mode = 1;
bool lastState = true;


typedef struct{
  IRData source;
  IRData destination;
} command;

command last;
command current;

void setup() {
  pinMode(4, OUTPUT);
  IrSender.begin(2);
  IrReceiver.begin(0, DISABLE_LED_FEEDBACK);
  
  cli();                            // Disable interrupts during setup
  PCMSK |= (1 << INTERRUPT_PIN);    // Enable interrupt handler (ISR) for our chosen interrupt pin (PCINT1/PB1/pin 6)
  GIMSK |= (1 << PCIE);             // Enable PCINT interrupt in the general interrupt mask
  pinMode(INT_PIN, INPUT_PULLUP);   // Set our interrupt pin as input with a pullup to keep it stable
  sei();  
}

void loop() {
  if(mode == 0){
    choseFunction();
  } else {
    if(IrReceiver.decode()){
      current = lookup(IrReceiver.decodedIRData);
      if(current.source.address != 0){
        IrSender.sendSamsung(current.destination.address, current.destination.command, 3);
      }
    }
    IrReceiver.resume();
  }
}

ISR(PCINT_VECTOR)
{
  if( digitalRead(INT_PIN) == LOW ) {
    changeMode();
  }
}
