#define ledPin 13
#define interruptPin 2 // тільки пін 2 (INT0) або 3 (INT1) для Arduiono Uno
volatile byte state = LOW;

void setup() {
  pinMode(ledPin, OUTPUT);
  pinMode(interruptPin, INPUT_PULLUP); 
  // ISC11 = 0, ISC10 = 0, ISC01 = 0, ISC00 = 1
  EICRA = 0b00000011; // RISING - режим переривання зміна сигналу з 1 в 0
  EIMSK = 0b00000011; // INT1=1(on), INT0=1(on) 
  // те саме, але по іншому записано:
  //EICRA = 1 << ISC00; 
  //EIMSK = 1 << INT0; 

  Serial.begin(9600);
  while(1){}
}

void loop() {

}

ISR(INT0_vect) {
  state = !state;
    digitalWrite(ledPin, state);
     Serial.println("ISR " + String(state)); 
}

ISR(INT1_vect) {
  state = !state;
    digitalWrite(ledPin, state);
     Serial.println("ISR " + String(state)); 
}
