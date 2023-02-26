#include <LiquidCrystal.h>
#include <string.h>

int seconds = 0;

LiquidCrystal lcd_1(12, 11, 5, 4, 3, 2);

void setup()
{
  lcd_1.begin(16, 2); // Set up the number of columns and rows on the LCD.

  // Print a message to the LCD.
  lcd_1.print("");
  Serial.begin(9600);
}

void loop()
{
  lcd_1.setCursor(0, 0);
  
  float voltage = analogRead(A0) * (5.0/1024);
  float temp = (voltage-0.5)*100;
  
  char* fbuff = (char*)malloc(10 * sizeof(char));
  
  dtostrf(temp, 4, 2, fbuff);
  strcat(fbuff, " C");
      
  Serial.println(fbuff);
  
  lcd_1.print(fbuff);
  
  free(fbuff);
  delay(1000); // Wait for 1000 millisecond(s)
}
