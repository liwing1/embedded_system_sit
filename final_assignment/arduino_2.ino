// This Arduino Handles the Buzzer
#define NOTE_B0  31
#define NOTE_C1  33
#define NOTE_CS1 35
#define NOTE_D1  37
#define NOTE_DS1 39
#define NOTE_E1  41
#define NOTE_F1  44
#define NOTE_FS1 46
#define NOTE_G1  49
#define NOTE_GS1 52
#define NOTE_A1  55
#define NOTE_AS1 58
#define NOTE_B1  62
#define NOTE_C2  65
#define NOTE_CS2 69
#define NOTE_D2  73
#define NOTE_DS2 78
#define NOTE_E2  82
#define NOTE_F2  87
#define NOTE_FS2 93
#define NOTE_G2  98
#define NOTE_GS2 104
#define NOTE_A2  110
#define NOTE_AS2 117
#define NOTE_B2  123
#define NOTE_C3  131
#define NOTE_CS3 139
#define NOTE_D3  147
#define NOTE_DS3 156
#define NOTE_E3  165
#define NOTE_F3  175
#define NOTE_FS3 185
#define NOTE_G3  196
#define NOTE_GS3 208
#define NOTE_A3  220
#define NOTE_AS3 233
#define NOTE_B3  247
#define NOTE_C4  262
#define NOTE_CS4 277
#define NOTE_D4  294
#define NOTE_DS4 311
#define NOTE_E4  330
#define NOTE_F4  349
#define NOTE_FS4 370
#define NOTE_G4  392
#define NOTE_GS4 415
#define NOTE_A4  440
#define NOTE_AS4 466
#define NOTE_B4  494
#define NOTE_C5  523
#define NOTE_CS5 554
#define NOTE_D5  587
#define NOTE_DS5 622
#define NOTE_E5  659
#define NOTE_F5	 698
#define NOTE_FS5 740
#define NOTE_G5  784
#define NOTE_GS5 831
#define NOTE_A5  880
#define NOTE_AS5 932
#define NOTE_B5  988
#define NOTE_C6  1047
#define NOTE_CS6 1109
#define NOTE_D6  1175
#define NOTE_DS6 1245
#define NOTE_E6  1319
#define NOTE_F6  1397
#define NOTE_FS6 1480
#define NOTE_G6  1568
#define NOTE_GS6 1661
#define NOTE_A6  1760
#define NOTE_AS6 1865
#define NOTE_B6  1976
#define NOTE_C7  2093
#define NOTE_CS7 2217
#define NOTE_D7  2349
#define NOTE_DS7 2489
#define NOTE_E7  2637
#define NOTE_F7  2794
#define NOTE_FS7 2960
#define NOTE_G7  3136
#define NOTE_GS7 3322
#define NOTE_A7  3520
#define NOTE_AS7 3729
#define NOTE_B7  3951
#define NOTE_C8  4186
#define NOTE_CS8 4435
#define NOTE_D8  4699
#define NOTE_DS8 4978
#define REST	 0

#define SS	2
#define BUZZ_PIN	3
#define SIZE_ARRAY(a)	sizeof(a)/sizeof(a[0])

const int mario_melody[] = {
  NOTE_E7, NOTE_E7,   0, NOTE_E7,
  0, NOTE_C7, NOTE_E7, 0,
  NOTE_G7, 0, 0,  0,
  NOTE_G6, 0,   0, 0,
 
  NOTE_C7, 0, 0, NOTE_G6,
  0, 0, NOTE_E6, 0,
  0, NOTE_A6,   0, NOTE_B6,
  0, NOTE_AS6, NOTE_A6, 0,
 
  NOTE_G6, NOTE_E7, NOTE_G7,
   NOTE_A7, 0, NOTE_F7, NOTE_G7,
  0, NOTE_E7, 0, NOTE_C7,
  NOTE_D7, NOTE_B6,   0, 0,
 
  NOTE_C7, 0, 0, NOTE_G6,
  0, 0, NOTE_E6, 0,
  0, NOTE_A6,   0, NOTE_B6,
  0, NOTE_AS6, NOTE_A6, 0,
 
  NOTE_G6, NOTE_E7, NOTE_G7,
   NOTE_A7, 0, NOTE_F7, NOTE_G7,
  0, NOTE_E7, 0, NOTE_C7,
  NOTE_D7, NOTE_B6,   0, 0
};
//Mario main theme tempo
const int mario_tempo[] = {
  12, 12, 12, 12,
  12, 12, 12, 12,
  12, 12, 12, 12,
  12, 12, 12, 12,
 
  12, 12, 12, 12,
  12, 12, 12, 12,
  12, 12, 12, 12,
  12, 12, 12, 12,
 
  9, 9, 9,
  12, 12, 12, 12,
  12, 12, 12, 12,
  12, 12, 12, 12,
 
  12, 12, 12, 12,
  12, 12, 12, 12,
  12, 12, 12, 12,
  12, 12, 12, 12,
 
  9, 9, 9,
  12, 12, 12, 12,
  12, 12, 12, 12,
  12, 12, 12, 12,
};

const int star_melody[] = {
  NOTE_AS4, NOTE_AS4, NOTE_AS4,
  NOTE_F5, NOTE_C6,
  NOTE_AS5, NOTE_A5, NOTE_G5, NOTE_F6, NOTE_C6,
  NOTE_AS5, NOTE_A5, NOTE_G5, NOTE_F6, NOTE_C6,
  NOTE_AS5, NOTE_A5, NOTE_AS5, NOTE_G5, NOTE_C5, NOTE_C5, NOTE_C5,
  NOTE_F5, NOTE_C6,
  NOTE_AS5, NOTE_A5, NOTE_G5, NOTE_F6, NOTE_C6,

  NOTE_AS5, NOTE_A5, NOTE_G5, NOTE_F6, NOTE_C6,
  NOTE_AS5, NOTE_A5, NOTE_AS5, NOTE_G5, NOTE_C5, NOTE_C5,
  NOTE_D5, NOTE_D5, NOTE_AS5, NOTE_A5, NOTE_G5, NOTE_F5,
  NOTE_F5, NOTE_G5, NOTE_A5, NOTE_G5, NOTE_D5, NOTE_E5, NOTE_C5, NOTE_C5,
  NOTE_D5, NOTE_D5, NOTE_AS5, NOTE_A5, NOTE_G5, NOTE_F5,

  NOTE_C6, NOTE_G5, NOTE_G5, REST, NOTE_C5,
  NOTE_D5, NOTE_D5, NOTE_AS5, NOTE_A5, NOTE_G5, NOTE_F5,
  NOTE_F5, NOTE_G5, NOTE_A5, NOTE_G5, NOTE_D5, NOTE_E5, NOTE_C6, NOTE_C6,
  NOTE_F6, NOTE_DS6, NOTE_CS6, NOTE_C6, NOTE_AS5, NOTE_GS5, NOTE_G5, NOTE_F5,
  NOTE_C6
};

const int star_tempo[] = {
  8, 8, 8,
  2, 2,
  8, 8, 8, 2, 4,
  8, 8, 8, 2, 4,
  8, 8, 8, 2, 8, 8, 8,
  2, 2,
  8, 8, 8, 2, 4,

  8, 8, 8, 2, 4,
  8, 8, 8, 2, 8, 16,
  4, 8, 8, 8, 8, 8,
  8, 8, 8, 4, 8, 4, 8, 16,
  4, 8, 8, 8, 8, 8,

  8, 16, 2, 8, 8,
  4, 8, 8, 8, 8, 8,
  8, 8, 8, 4, 8, 4, 8, 16,
  4, 8, 4, 8, 4, 8, 4, 8,
  1
};

const int birth_melody[] = {
  NOTE_C4, NOTE_C4, 
  NOTE_D4, NOTE_C4, NOTE_F4,
  NOTE_E4, NOTE_C4, NOTE_C4, 
  NOTE_D4, NOTE_C4, NOTE_G4,
  NOTE_F4, NOTE_C4, NOTE_C4,
  
  NOTE_C5, NOTE_A4, NOTE_F4, 
  NOTE_E4, NOTE_D4, NOTE_AS4, NOTE_AS4,
  NOTE_A4, NOTE_F4, NOTE_G4,
  NOTE_F4
};

const int birth_tempo[] = {
  4, 8, 
  4, 4, 4,
  2, 4, 8, 
  4, 4, 4,
  2, 4, 8,
  
  4, 4, 4, 
  4, 4, 4, 8,
  4, 4, 4,
  2
};

typedef struct SONG{
  const int* melody;
  const int* tempo;
  const size_t size;
} song_t;

song_t song_list[] = {
  [0] = {mario_melody, mario_tempo, SIZE_ARRAY(mario_melody)},
  [1] = {star_melody, star_tempo, SIZE_ARRAY(star_melody)},
  [2] = {birth_melody, birth_tempo, SIZE_ARRAY(birth_melody)},
};

typedef enum BUZZER_STATE_SET{
  BUZ_STATE_PAUSED,
  BUZ_STATE_PLAYING,
  BUZ_STATE_TRANSITION,
  BUZ_STATE_MAX
} buzzer_state_set_t;

typedef enum BUZZER_COMMAND{
  BUZ_COMMAND_NONE,
  BUZ_COMMAND_PLAY,
  BUZ_COMMAND_NEXT,
  BUZ_COMMAND_BACK,
  BUZ_COMMAND_MAX
} buzzer_command_t;

typedef struct BUZZER_STATE{
  buzzer_state_set_t set;
  void (*output)(const uint8_t);
} buzzer_state_t;

buzzer_state_t s_next[BUZ_STATE_MAX][BUZ_COMMAND_MAX] = {
  [BUZ_STATE_PAUSED] = {
    [BUZ_COMMAND_NONE] = {BUZ_STATE_PAUSED, do_nothing},
    [BUZ_COMMAND_PLAY] = {BUZ_STATE_PLAYING, play_song},
    [BUZ_COMMAND_NEXT] = {BUZ_STATE_TRANSITION, advance_song},
	[BUZ_COMMAND_BACK] = {BUZ_STATE_TRANSITION, return_song},
  },
    
  [BUZ_STATE_PLAYING] = {
    [BUZ_COMMAND_NONE] = {BUZ_STATE_PLAYING, play_song},
    [BUZ_COMMAND_PLAY] = {BUZ_STATE_PAUSED, do_nothing},
    [BUZ_COMMAND_NEXT] = {BUZ_STATE_TRANSITION, advance_song},
	[BUZ_COMMAND_BACK] = {BUZ_STATE_TRANSITION, return_song},
  },

  [BUZ_STATE_TRANSITION] = {
    [BUZ_COMMAND_NONE] = {BUZ_STATE_PAUSED, do_nothing},
    [BUZ_COMMAND_PLAY] = {BUZ_STATE_PLAYING, play_song},
    [BUZ_COMMAND_NEXT] = {BUZ_STATE_PLAYING, play_song},
	[BUZ_COMMAND_BACK] = {BUZ_STATE_PLAYING, play_song},
  }
};

buzzer_state_t buzzer_state = {BUZ_STATE_PAUSED, NULL};
buzzer_command_t buzzer_command = BUZ_COMMAND_NONE;

volatile uint8_t rx_byte, tx_byte;
volatile int song_idx = 0;
volatile bool flag_new_song = false;

void setup()
{ 
  // Init SPI
  pinMode(SS, INPUT_PULLUP);
  pinMode(MOSI, INPUT);
  pinMode(MISO, OUTPUT);
  pinMode(SCK, INPUT);
  attachInterrupt(digitalPinToInterrupt(SS), spi_transfer_slave, RISING);
}

void loop()
{
  if(flag_new_song){
    flag_new_song = false;
    
    (*buzzer_state.output)(rx_byte);
  }
  
  delay(1000);
}

void spi_transfer_slave(void){
  for(word mask = 0b10000000; mask > 0; mask >>= 1){
    while(!digitalRead(SCK));
    rx_byte = rx_byte << 1 | digitalRead(MOSI);
    digitalWrite(MISO, (tx_byte & mask));
    while(digitalRead(SCK));
  }
  tx_byte = 0;
  flag_new_song = true;
  
  buzzer_state = s_next[buzzer_state.set][rx_byte];
}

void do_nothing(const uint8_t input){
  delay(100);
  return;
}

void play_song(const uint8_t input){
  int noteDuration = 0;
  while(1){
    for (int thisNote = 0; thisNote < song_list[song_idx].size; thisNote++) {
      noteDuration = 1000/song_list[song_idx].tempo[thisNote];

      tone(BUZZ_PIN, song_list[song_idx].melody[thisNote], noteDuration);

      // to distinguish the notes, set a minimum time between them.
      //   the note's duration + 30% seems to work well:
      int pauseBetweenNotes = noteDuration   * 1.30;
      delay(pauseBetweenNotes);

      // stop the tone playing:
      noTone(BUZZ_PIN);
      
      if(buzzer_state.set != BUZ_STATE_PLAYING) return;
    }
  }
}

void advance_song(const uint8_t input){
  if(++song_idx > 2) song_idx = 0;
  buzzer_state = s_next[buzzer_state.set][input];
  flag_new_song = true;
}

void return_song(const uint8_t input){
  if(--song_idx < 0) song_idx = 2;
  buzzer_state = s_next[buzzer_state.set][input];
  flag_new_song = true;
}
