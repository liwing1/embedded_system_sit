
// C++ code
//
#define PIN_LED1	13
#define PIN_LED2	12
#define PIN_DATA0	5
#define PIN_DATA1	6
#define	PIN_CLCK	7

#define BIT(a)	1<<a

uint8_t tx_data = (BIT(1));

void setup()
{ 
  pinMode(PIN_LED1, OUTPUT);
  pinMode(PIN_LED2, OUTPUT);
  
  pinMode(PIN_DATA0, INPUT_PULLUP);
  pinMode(PIN_DATA1, OUTPUT);
  
  pinMode(PIN_CLCK, OUTPUT);
  digitalWrite(PIN_CLCK, HIGH);
  
  TCCR1A = 0;
  TCCR1B = (1<<WGM12 | 1<<CS12);
  OCR1A = (31250*16) -1 ;
  TIMSK1 |= (1 << OCIE1A);
  
}

void loop()
{
  delay(1000); // Wait for 1000 millisecond(s)
}

void set_led(uint8_t* buffer){
  digitalWrite(PIN_LED1, (buffer[0] & BIT(1)));
  digitalWrite(PIN_LED2, (buffer[0] & BIT(0)));
}

ISR(TIMER1_COMPA_vect){
  // Set bit on data wire
  digitalWrite(PIN_DATA1, tx_data & BIT(0));
  
  // Generate Pulse
  digitalWrite(PIN_CLCK, LOW);
  digitalWrite(PIN_CLCK, LOW);
  digitalWrite(PIN_CLCK, LOW);
  digitalWrite(PIN_CLCK, HIGH);
  
  // Shift Register
  tx_data = tx_data>>1;
  tx_data |= digitalRead(PIN_DATA0)<<1;
  
  set_led(&tx_data);
}


