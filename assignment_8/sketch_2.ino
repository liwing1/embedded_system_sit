#include <LiquidCrystal.h>

#define PIN_MISO	10
#define PIN_MOSI	11
#define	PIN_CLCK	2
#define PIN_CSEL	3

#define BIT(a)	1<<a

LiquidCrystal lcd_1(9, 8, 7, 6, 5, 4);
uint8_t count = 0;
uint8_t rx_byte = 0;
uint8_t tx_data[] = "ABCDEFGHIJKLMNOP";

void setup()
{
  pinMode(PIN_MISO, OUTPUT);
  pinMode(PIN_MOSI, INPUT_PULLUP);
  pinMode(PIN_CSEL, INPUT_PULLUP);
  pinMode(PIN_CLCK, INPUT_PULLUP);
  attachInterrupt(digitalPinToInterrupt(PIN_CLCK), on_push, FALLING);
  
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

void on_push()
{
  if(digitalRead(PIN_CSEL) == LOW){
    digitalWrite(PIN_MISO, tx_data[15] & BIT(count));
    
    rx_byte |= digitalRead(PIN_MOSI)<<count;

    if(count++ == 7){
      count = 0;
      //Serial.println(rx_byte);
      rotate_buffer(tx_data, rx_byte);
      rx_byte = 0;
    }
  }
}
