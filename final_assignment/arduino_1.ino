// This Arduino Handles Front End
#include <Adafruit_LiquidCrystal.h>
#include <IRremote.h>

#define PIN_IR	3
#define CMD_PLAY	16621663
#define CMD_NEXT	16605343
#define CMD_BACK	16589023
#define CMD_ONOFF	16580863

#define SPI_READ	0x00
#define SPI_PLAY	0x01
#define SPI_NEXT	0x02
#define SPI_BACK	0x03

#define SS	2

// Initialize IR
IRrecv irrecv(PIN_IR);
decode_results results;

// Initialize LCD
Adafruit_LiquidCrystal lcd_1(0);

const char* song_names[] = {
  "Mario Theme",
  "Star Wars",
  "Happy Birthday"
};

const char* song_status[] = {
  "PLAYING",
  "PAUSED"
};

int song_idx = 0;
bool is_paused = true;

void setup()
{
  lcd_1.begin(16, 2);
  lcd_1.setCursor(1, 0);
  lcd_1.print("PAUSED");
  lcd_1.setCursor(0, 1);
  lcd_1.print(song_names[0]);
  
  irrecv.enableIRIn();
  
  pinMode(SS, OUTPUT);
  pinMode(MOSI, OUTPUT);
  pinMode(MISO, INPUT);
  pinMode(SCK, OUTPUT);
}

void loop()
{
  uint8_t rx_byte = 0;;
  
  if (irrecv.decode(&results)){
    switch(results.value){
      case CMD_PLAY:{
        rx_byte = spi_transfer_master(SPI_PLAY);
        is_paused = !is_paused;
      }
      break;
      
      case CMD_NEXT:{
        rx_byte = spi_transfer_master(SPI_NEXT);
        is_paused = false;
        if(++song_idx > 3) song_idx = 0;
      }
      break;
      
      case CMD_BACK:{
        rx_byte = spi_transfer_master(SPI_BACK);
        is_paused = false;
        if(--song_idx < 0) song_idx = 2;
      }
      break;
      
    }
    lcd_1.clear();
    lcd_1.setCursor(0, 0);
    lcd_1.print(song_status[is_paused]);
    lcd_1.setCursor(0, 1);
    lcd_1.print(song_names[song_idx]);
    
	irrecv.resume(); // Receive the next value
  }
  
  delay(1000);
}

uint8_t spi_transfer_master(uint8_t tx_data){
  uint8_t rx_byte = 0;
  
  digitalWrite(SS, HIGH);
  
  for(word mask = 0b10000000; mask > 0; mask >>= 1){
    digitalWrite(MOSI, (tx_data & mask));
    
    digitalWrite(SCK, HIGH);
    delay(1);
    digitalWrite(SCK, LOW);
    
    rx_byte = rx_byte << 1 | digitalRead(MISO);
  }
  
  digitalWrite(SS, LOW);
  
  return rx_byte;
}
