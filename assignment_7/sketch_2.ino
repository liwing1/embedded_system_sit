// C++ code
//
#define PIN_LED1	13
#define PIN_LED2	12
#define PIN_DATA0	4
#define PIN_DATA1	3
#define	PIN_CLCK	2

#define BIT(a)	1<<a

uint8_t rx_data = {BIT(6)};

void setup()
{ 
  delay(500);
  pinMode(PIN_LED1, OUTPUT);
  pinMode(PIN_LED2, OUTPUT);

  pinMode(PIN_DATA0, OUTPUT);
  pinMode(PIN_DATA1, INPUT_PULLUP);
  
  pinMode(PIN_CLCK, INPUT_PULLUP);
  attachInterrupt(digitalPinToInterrupt(2), on_push, FALLING);
  
  Serial.begin(9600);
  
}

void loop()
{
  delay(1000); // Wait for 1000 millisecond(s)
}

void set_led(uint8_t* buffer){
  digitalWrite(PIN_LED1, (buffer[0] & BIT(7)));
  digitalWrite(PIN_LED2, (buffer[0] & BIT(6)));
}

void on_push()
{
  digitalWrite(PIN_DATA0, rx_data & BIT(6));
  rx_data = rx_data>>1;
  rx_data |= digitalRead(PIN_DATA1)<<7;
  
  set_led(&rx_data);
}
