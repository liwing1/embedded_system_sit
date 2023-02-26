// LCD1602 to Arduino Uno connection example

#include <LiquidCrystal.h>

#define TIMEOUT_LED_MS  1000
#define TIMEOUT_LCD_MS  1000

#define ARRAY_SIZE(array) (sizeof(array)/sizeof(array[0]))
#define NLEDS	(6)
#define	LED_0	(2)

LiquidCrystal lcd(13, 12, 11, 10, 9, 8);

const char *led_pattern[] = {
  "010101",
  "101010",
  "111100",
  "000011"
};

const char *lcd_pattern[] = {
  "Hello, world",
  "Test string",
  "3rd string",
  "The last line"
};

void setLed(const char *pat)
{
  int gpio_num = 7;

  while(*pat){
    digitalWrite(gpio_num, (*pat - '0'));

    gpio_num--;
    *pat++;
  }
}

void setLcd(const char *pat)
{
  lcd.clear();
  lcd.setCursor(0, 0);
  lcd.print(pat);
}

void setup() {
  Serial.begin(9600);

  lcd.begin(16, 2); // Set up the number of columns and rows on the LCD.
  lcd.clear();
  lcd.setCursor(0, 0);
  lcd.print("START");
  
  
  for(int i = LED_0; i < (LED_0 + NLEDS); i++){
    pinMode(i, OUTPUT);
    digitalWrite(i, LOW);
  }
}

void loop() {

  static int led_timer = 0;
  static int led_idx = 0;

  static int lcd_timer = 0;
  static int lcd_idx = 0;

  if((millis() - led_timer) >= TIMEOUT_LED_MS){
    led_timer = millis();
    setLed(led_pattern[led_idx]);
    led_idx = led_idx++ >= (ARRAY_SIZE(led_pattern)-1) ? 0:led_idx;
  }

  if((millis() - lcd_timer) >= TIMEOUT_LCD_MS){
    lcd_timer = millis();
    setLcd(lcd_pattern[lcd_idx]);
    lcd_idx = lcd_idx++ >= (ARRAY_SIZE(lcd_pattern)-1) ? 0:lcd_idx;
  }

  // int i = 0;

  // for(i = 0; i < sizeof(led_pattern)/sizeof(led_pattern[0]); i++){
  //   setLed(led_pattern[i]);
  //   delay(1000);
  // }

  // for(i = 0; i < sizeof(lcd_pattern)/sizeof(lcd_pattern[0]); i++){
  //   setLcd(lcd_pattern[i]);
  //   delay(1000);
  // }

}
