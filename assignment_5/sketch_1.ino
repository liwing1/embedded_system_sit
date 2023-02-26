
#define PIN_SW1	8
#define PIN_LD0	2
#define NUM_LED	6

#define ARRAY_SIZE(array) (sizeof(array)/sizeof(array[0]))

const char *pattern[] = {
  "010101",
  "101010",
  "111100",
  "000011"
};

void setLed(const char *pat)
{
  int gpio_num = (PIN_LD0 + NUM_LED) - 1;

  while(*pat){
    digitalWrite(gpio_num, (*pat - '0'));

    gpio_num--;
    *pat++;
  }
}

void setup()
{
  Serial.begin(9600);
  
  for(int i = PIN_LD0; i < (NUM_LED + PIN_LD0); i++){
    pinMode(i, OUTPUT);
    digitalWrite(i, LOW);
  }
  
  pinMode(PIN_SW1, INPUT_PULLUP);
}

void loop()
{
  float voltage = 0;
  float temp = 0;
  
  for(int i = 0; i < ARRAY_SIZE(pattern); i++){
    setLed(pattern[i]);
    while(digitalRead(PIN_SW1) == HIGH){
      delay(500);
      
      voltage = analogRead(A5) * (5.0/1024);
      temp = (voltage-0.5)*100;
      
      Serial.println(voltage);
      Serial.println(temp);
      
    }
  }
}
