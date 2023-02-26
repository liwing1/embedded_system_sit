#include <LiquidCrystal.h>

#define PIN_MISO	10
#define PIN_MOSI	11
#define	PIN_CLCK	2
#define PIN_CSEL	3

#define BIT(a)	1<<a
#define SIZE_ARRAY(a)	sizeof(a)/sizeof(a[0])
LiquidCrystal lcd_1(9, 8, 7, 6, 5, 4);
uint8_t tx_data[] = "0123456789012345";
void setup()
{ 
  pinMode(PIN_MISO, INPUT_PULLUP);
  pinMode(PIN_MOSI, OUTPUT);
  pinMode(PIN_CSEL, OUTPUT);
  pinMode(PIN_CLCK, OUTPUT);
  digitalWrite(PIN_CLCK, HIGH);
  
  TCCR1A = 0;
  TCCR1B = (1<<WGM12 | 1<<CS12);
  OCR1A = (31250*2) -1 ;
  TIMSK1 |= (1 << OCIE1A);
  
  lcd_1.begin(16, 2);
  lcd_1.clear();
  
  Serial.begin(9600);
}

void loop()
{
  lcd_1.clear();
  lcd_1.setCursor(0, 0);
  lcd_1.print((char*)tx_data);
  delay(500); // Wait for 1000 millisecond(s)
}

inline void rotate_buffer(uint8_t* buff, uint8_t insert){
  for(uint8_t i = 15; i > 0; i--){
    buff[i] = buff[i-1];
  }
  buff[0] = insert;
}

ISR(TIMER1_COMPA_vect){
  uint8_t rx_byte = 0;
  digitalWrite(PIN_CSEL, LOW);
  for(uint8_t i = 0; i < 8; i++){
	// Set bit on data wire
    digitalWrite(PIN_MOSI, tx_data[15] & BIT(i));

    // Generate Pulse
    digitalWrite(PIN_CLCK, LOW);
    delay(1);
    digitalWrite(PIN_CLCK, HIGH);

    // Received Data
    rx_byte |= digitalRead(PIN_MISO)<<i;
  }
  
  rotate_buffer(tx_data, rx_byte);
    
  digitalWrite(PIN_CSEL, HIGH);
}
