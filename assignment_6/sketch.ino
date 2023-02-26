// C++ code
//
void setup()
{
  pinMode(12, OUTPUT);
  pinMode(2, INPUT_PULLUP);
  
  Serial.begin(9600);
  attachInterrupt(digitalPinToInterrupt(2), on_push, FALLING);
  
  TCCR1A = 0;
  TCCR1B = (1<<WGM12 | 1<<CS12);
  OCR1A = (31250*2) -1 ;
  TIMSK1 |= (1 << OCIE1A);
  
  
}

void loop()
{
  delay(1000);
}

void on_push(){
  digitalWrite(LED_BUILTIN, !digitalRead(LED_BUILTIN));
}

ISR(TIMER1_COMPA_vect){
  digitalWrite(12, !digitalRead(12));
}
