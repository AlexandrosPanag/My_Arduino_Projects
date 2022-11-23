// CHRISTMAS CAROLS


// YOU CAN CHECK OUT THIS PROJECT HERE: https://create.arduino.cc/projecthub/ronbentley1/christmas-carols-on-arduino-7bc262

//
// Ron D Bentley, Stafford, UK, September 2021
// Modified:
//   Oct 2022 to remove compliler warning re redfinition
//   of macros for some macro locally defined notes, eg B0, B1, etc.
//   Local naming convention for notes now prefixed with "note_".
//
// Christmas Carols with Arduino - based on 'let's make music' Arduino sketch
// by same author.
//
// Uses a simple circuit connecting an 8 ohm speaker on digital pin 11...that's all!
// Merry Christmas!!
//
// This example and code is in the public domain and
// may be used without restriction and without warranty.
//
// %%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
// % Music/tone data and functions... %
// %%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%

//
// Tempos, by common musical names
//
#define  grave          40
#define  largo          46
#define  lento          52
#define  adagio         56
#define  larghetto      60
#define  adagietto      66
#define  andante        72
#define  andantino      80
#define  maestroso      88
#define  moderato      100
#define  allegretto    104
#define  animato       120
#define  allegro       132
#define  allegro_assai 144
#define  vivace        160
#define  presto        184
#define  prestissimo   208

//
// Public constants - reflects the 'pitches.h' file,
// but with a different (shortened) note naming convention.
// The values are the frequencies (hz) of the notes.
//
#define note_B0  31
#define note_C1  33
#define note_CS1 35
#define note_DF1 35
#define note_D1  37
#define note_DS1 39
#define note_EF1 39
#define note_E1  41
#define note_F1  44
#define note_FS1 46
#define note_GF1 46
#define note_G1  49
#define note_GS1 52
#define note_AF1 52
#define note_A1  55
#define note_AS1 58
#define note_BF1 58
#define note_b1  62
#define note_C2  65
#define note_CS2 69
#define note_DF2 69
#define note_D2  73
#define note_DS2 78
#define note_EF2 78
#define note_E2  82
#define note_F2  87
#define note_FS2 93
#define note_GF2 93
#define note_G2  98
#define note_GS2 104
#define note_AF2 104
#define note_A2  110
#define note_as2 117
#define note_BF2 117
#define note_B2  123
#define note_C3  131
#define note_CS3 139
#define note_DF3 139
#define note_D3  147
#define note_DS3 156
#define note_EF3 156
#define note_E3  165
#define note_F3  175
#define note_FS3 185
#define note_GF3 185
#define note_G3  196
#define note_GS3 208
#define note_AF3 208
#define note_A3  220
#define note_AS3 233
#define note_BF3 233
#define note_B3  247
#define note_C4  262 // <--------- middle C
#define note_CS4 277
#define note_DF4 277
#define note_D4  294
#define note_DS4 311
#define note_EF4 311
#define note_E4  330
#define note_F4  349
#define note_FS4 370
#define note_GF4 370
#define note_G4  392
#define note_GS4 415
#define note_AF4 415
#define note_A4  440
#define note_AS4 466
#define note_BF4 466
#define note_B4  494
#define note_C5  523
#define note_CS5 554
#define note_DF5 554
#define note_D5  587
#define note_DS5 622
#define note_EF5 622
#define note_E5  659
#define note_F5  698
#define note_FS5 740
#define note_GF5 740
#define note_G5  784
#define note_GS5 831
#define note_AF5 831
#define note_A5  880
#define note_AS5 932
#define note_BF5 932
#define note_B5  988
#define note_C6  1047
#define note_CS6 1109
#define note_DF6 1109
#define note_D6  1175
#define note_DS6 1245
#define note_EF6 1245
#define note_E6  1319
#define note_F6  1397
#define note_FS6 1480
#define note_GF6 1480
#define note_G6  1568
#define note_GS6 1661
#define note_AF6 1661
#define note_A6  1760
#define note_AS6 1865
#define note_BF6 1865
#define note_B6  1976
#define note_C7  2093
#define note_CS7 2217
#define note_DF7 2217
#define note_D7  2349
#define note_DS7 2489
#define note_EF7 2489
#define note_E7  2637
#define note_F7  2794
#define note_FS7 2960
#define note_GF7 2960
#define note_G7  3136
#define note_GS7 3322
#define note_AF7 3322
#define note_A7  3520
#define note_AS7 3729
#define note_BF7 3729
#define note_B7  3951
#define note_C8  4186
#define note_CS8 4435
#define note_DF8 4435
#define note_D8  4699
#define note_DS8 4978
#define note_EF8 4978

#define speaker                2     // digital pin number for speaker/buzzer

float default_tempo = float(animato); // default tempo - beats per minute
float current_tempo = default_tempo;
float timings[7];                     // holds timings for each defined note/rest time value

//
// Standard note/rest duration definitions, set by the set_tempo function
//
#define semib       timings[0] // semi briev       - 4 beats
#define dot_minim   timings[1] // dotted mini      - 3 beats
#define minim       timings[2] // minim            - 2 beats
#define crot        timings[3] // crotchet         - 1 beat
#define quav        timings[4] // quaver           - 1/2 beat
#define semiq       timings[5] // semi quaver      - 1/4 beat
#define demi_semiq  timings[6] // demi semi quaver - 1/8 beat

// %%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
// Carols data...
// Setup play list data
//

#define num_carols  10

// Forward references for music score functions
// which are defined at end of the sketch to avoid clutter...
void we_wish_you_a_merry_christmas();
void o_come_all_ye_faithful();
void away_in_a_manger();
void ding_dong_merrily();
void good_king_wenceslas();
void the_first_nowell();
void the_holly_and_the_ivy();
void we_three_kings();
void silent_night();
void jingle_bells();

//
// Declare pointer array and preset with addresses
// of each of the carol score functions.
// Note that the oder of the presets is not important
// as the play_list array is constantly randomised
// by the shuffle_play_list function.

void (*play_list[num_carols])() = {
  we_wish_you_a_merry_christmas,
  o_come_all_ye_faithful,
  away_in_a_manger,
  ding_dong_merrily,
  good_king_wenceslas,
  the_first_nowell,
  the_holly_and_the_ivy,
  we_three_kings,
  silent_night,
  jingle_bells
};
// End of carols data
// %%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%

//
// Shuffle the play_list randomly
//
void shuffle_play_list() {
  uint8_t swap_with;
  void (* swap)(); // same data type as the play_list
  // Keep changing the random seed for shuffling the play_list.
  // If the reads of A0 and A5 yield 0 then we will have a prime
  // number as the base for the random seeding
  randomSeed(analogRead(A0) + analogRead(A5) + 1031);
  for (uint8_t carol = 0; carol < num_carols; carol++) {
    // play_list entry to be swapped out with that in entry '[carol]'
    swap_with = random(num_carols); // 0 to (num_carols - 1)
    swap      = play_list[carol];
    play_list[carol]     = play_list[swap_with];
    play_list[swap_with] = swap;
  }
}

//
// Function waits for the given time in seconds, or part thereof.
//
void wait(float duration) {
  uint32_t start;
  start    = millis();
  duration = duration * 1000; // convert to milliseconds
  do {
  } while (millis() - start <= duration);
}

//
// Set tempo by adjusting durations of note/rest timings
//
void set_tempo(float new_tempo) {
  float crotchet_duration;
  current_tempo = new_tempo;           // keep current tempo up to date in case it needs to be queried
  crotchet_duration = 60 / new_tempo;  // timing in seconds for 1 beat
  semib      = crotchet_duration * 4;  // semibrieve, 4 beats
  dot_minim  = crotchet_duration * 3;  // dotted mimin, 3 beats
  minim      = crotchet_duration * 2;  // minim, 2 beats
  crot       = crotchet_duration;      // crotchet, 1 beat
  quav       = crotchet_duration / 2;  // quaver, 1/2 beat
  semiq      = crotchet_duration / 4;  // semiquaver, 1/4 beat
  demi_semiq = crotchet_duration / 8;  // demi-semi-quaver, 1/8 beat
}

//
// Play given note for given duration in seconds, or part thereof.
// Observe that this function is 'blocking', although the tone
// function is 'non-blocking', ie control stays with the function
// until note has completed.
//
void play(int note, float note_duration) {
  tone(speaker, note, note_duration * 1000); // play the given note for the given duration
  wait(note_duration);                       // wait for note to complete
}

//
// Rest for given duration in seconds, or part thereof.
//
void rest(float rest_duration) {
  noTone(speaker);      // ensure no tone is currently playing
  wait(rest_duration);  // wait for given rest to complete
}

void setup() {
  // Set up speaker
  pinMode(speaker, OUTPUT);
  // Set up note/rest timings, based on the default unit beat time (default_tempo)
  set_tempo(default_tempo);
  shuffle_play_list(); // start with a randomised play_list
}

void loop() {
  do {
    // Process the play_list by selecting each of its preset and randomsised
    // elements, and execute each respective music score funcion.
    for (uint8_t carol = 0; carol < num_carols; carol++) {
      play_list[carol](); // execute this ([carol]) music score function
      wait(3);            // wait a short time between carols
    }
    shuffle_play_list();  // randomise the play_list for the next play_list pass
    wait(3);              // wait a short time before playing the new playlist
  } while (true);
}

//
// %%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
// % Out-of-the-box 'shrink-wrapped' Christmas Carol music scores %
// %%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
//

void we_wish_you_a_merry_christmas() {
  set_tempo(default_tempo);
  // 3/4time
  for (uint8_t repeat = 1; repeat <= 2; repeat++) {
    // intro bar
    play(note_D4, crot);
    // bar 1
    play(note_G4, crot);
    play(note_G4, quav);
    play(note_A4, quav);
    play(note_G4, quav);
    play(note_FS4, quav);
    // bar 2
    play(note_E4, crot);
    play(note_E4, crot);
    play(note_E4, crot);
    // bar 3
    play(note_A4, crot);
    play(note_A4, quav);
    play(note_B4, quav);
    play(note_A4, quav);
    play(note_G4, quav);
    // bar 4
    play(note_FS4, crot);
    play(note_D4, crot);
    play(note_D4, crot);
    // bar 5
    play(note_B4, crot);
    play(note_B4, quav);
    play(note_C5, quav);
    play(note_B4, quav);
    play(note_A4, quav);
    // bar 6
    play(note_G4, crot);
    play(note_E4, crot);
    play(note_D4, quav);
    play(note_D4, quav);
    // bar 7
    play(note_E4, crot);
    play(note_A4, crot);
    play(note_FS4, crot);
    // bar 8
    play(note_G4, minim);
    play(note_D4, crot);
    // bar 9
    play(note_G4, crot);
    play(note_G4, crot);
    play(note_G4, crot);
    // bar 10
    play(note_FS4, minim);
    play(note_FS4, crot);
    // bar 11
    play(note_G4, crot);
    play(note_FS4, crot);
    play(note_E4, crot);
    // bar 12
    play(note_D4, minim);
    play(note_A4, crot);
    // bar 13
    play(note_B4, crot);
    play(note_A4, crot);
    play(note_G4, crot);
    // bar 14
    play(note_D5, crot);
    play(note_D4, crot);
    play(note_D4, quav);
    play(note_D4, quav);
    // bar 15
    play(note_E4, crot);
    play(note_A4, crot);
    play(note_FS4, crot);
    // bar 16
    play(note_G4, minim);
    rest(crot);
  }
}

void o_come_all_ye_faithful() {
  set_tempo(default_tempo);
  // 4/4 time
  // intro bar
  for (uint8_t repeat = 1; repeat <= 2; repeat++) {
    play(note_G4, crot);
    // bar 1
    play(note_G4, minim);
    play(note_D4, crot);
    play(note_G4, crot);
    // bar 2
    play(note_A4, minim);
    play(note_D4, minim);
    // bar 3
    play(note_B4, crot);
    play(note_A4, crot);
    play(note_B4, crot);
    play(note_C5, crot);
    // bar 4
    play(note_B4, minim);
    play(note_A4, crot);
    play(note_G4, crot);
    // bar 5
    play(note_G4, minim);
    play(note_FS4, crot);
    play(note_E4, crot);
    // bar 6
    play(note_FS4, crot);
    play(note_G4, crot);
    play(note_A4, crot);
    play(note_B4, crot);
    // bar 7
    play(note_FS4, minim);
    play(note_E4, crot + quav);
    play(note_D4, quav);
    // bar 8
    play(note_D4, dot_minim);
    rest(crot);
    // bar 9
    play(note_D5, minim);
    play(note_C5, crot);
    play(note_B4, crot);
    // bar 10
    play(note_C5, minim);
    play(note_B4, minim);
    //  bar 11
    play(note_A4, crot);
    play(note_B4, crot);
    play(note_G4, crot);
    play(note_A4, crot);
    // bar 12
    play(note_FS4, crot + quav);
    play(note_E4, quav);
    play(note_D4, crot);
    play(note_G4, crot);
    // bar 13
    play(note_G4, crot);
    play(note_FS4, crot);
    play(note_G4, crot);
    play(note_A4, crot);
    // bar 15
    play(note_G4, minim);
    play(note_D4, crot);
    play(note_B4, crot);
    // bar 16
    play(note_B4, crot);
    play(note_A4, crot);
    play(note_B4, crot);
    play(note_C5, crot);
    // bar 17
    play(note_B4, minim);
    play(note_A4, crot);
    play(note_B4, crot);
    // bar 18
    play(note_C5, crot);
    play(note_B4, crot);
    play(note_A4, crot);
    play(note_G4, crot);
    // bar 19
    play(note_FS4, minim);
    play(note_G4, crot);
    play(note_C5, crot);
    // bar 20
    play(note_B4, minim);
    play(note_A4, crot + quav);
    play(note_G4, quav);
    // bar 21
    play(note_G4, dot_minim);
    rest(crot);
  }
}

void away_in_a_manger() {
  set_tempo(moderato);
  // 3/4 time
  for (uint8_t repeat = 1; repeat <= 2; repeat++) {
    // intro bar
    play(note_C4, crot);
    // bar 1
    play(note_F4, crot);
    play(note_F4, crot);
    play(note_G4, quav);
    play(note_A4, quav);
    // bar 2
    play(note_F4, crot);
    play(note_F4, crot);
    play(note_A4, quav);
    play(note_BF4, quav);
    // bar 3
    play(note_C5, crot);
    play(note_C5, crot);
    play(note_D5, crot);
    // bar 4
    play(note_BF4, minim);
    play(note_G4, quav);
    play(note_A4, quav);
    // bar 5
    play(note_BF4, crot);
    play(note_BF4, crot);
    play(note_C5, crot);
    // bar 6
    play(note_A4, crot);
    play(note_A4, crot);
    play(note_F4, quav);
    play(note_A4, quav);
    // bar 7
    play(note_G4, crot);
    play(note_D4, crot);
    play(note_F4, crot);
    // bar 8
    play(note_E4, minim);
    play(note_C4, crot);
    // bar 9
    play(note_F4, crot);
    play(note_F4, crot);
    play(note_G4, quav);
    play(note_A4, quav);
    // bar 10
    play(note_F4, crot);
    play(note_F4, crot);
    play(note_A4, quav);
    play(note_BF4, quav);
    // bar 11
    play(note_C5, crot);
    play(note_C5, crot);
    play(note_D5, crot);
    // bar 12
    play(note_BF4, minim);
    play(note_G4, quav);
    play(note_A4, quav);
    // bar 13
    play(note_BF4, crot);
    play(note_BF4, crot);
    play(note_C5, crot);
    // bar 14
    play(note_A4, crot);
    play(note_A4, crot);
    play(note_F4, quav);
    play(note_A4, quav);
    // bar 15
    play(note_G4, crot);
    play(note_D4, crot);
    play(note_E4, crot);
    // bar 16
    play(note_F4, minim);
    rest(crot);
  }
}

void ding_dong_merrily() {
  set_tempo(default_tempo);
  // 4/4 time
  for (uint8_t repeat = 1; repeat <= 2; repeat++) {
    // bar 1
    play(note_G4, crot);
    play(note_G4, crot);
    play(note_A4, quav);
    play(note_G4, quav);
    play(note_FS4, quav);
    play(note_E4, quav);
    // bar 2
    play(note_D4, minim);
    rest(crot);
    play(note_D4, crot);
    // bar 3
    play(note_E4, crot);
    play(note_G4, crot);
    play(note_G4, crot);
    play(note_FS4, crot);
    // bar 4
    play(note_G4, minim);
    play(note_G4, crot);
    rest(crot);
    // bar 5
    play(note_G4, crot);
    play(note_G4, crot);
    play(note_A4, quav);
    play(note_G4, quav);
    play(note_FS4, quav);
    play(note_E4, quav);
    // bar 6
    play(note_D4, minim);
    rest(crot);
    play(note_D4, crot);
    // bar 7
    play(note_E4, crot);
    play(note_G4, crot);
    play(note_G4, crot);
    play(note_FS4, crot);
    // bar 8
    play(note_G4, minim);
    play(note_G4, crot);
    rest(crot);
    // bar 9
    play(note_D5, crot + quav);
    play(note_C5, quav);
    play(note_B4, quav);
    play(note_C5, quav);
    play(note_D5, quav);
    play(note_B4, quav);
    // bar 10
    play(note_C5, crot + quav);
    play(note_B4, quav);
    play(note_A4, quav);
    play(note_B4, quav);
    play(note_C5, quav);
    play(note_A4, quav);
    // bar 11
    play(note_B4, crot + quav);
    play(note_A4, quav);
    play(note_G4, quav);
    play(note_A4, quav);
    play(note_B4, quav);
    play(note_G4, quav);
    // bar 12
    play(note_A4, crot + quav);
    play(note_G4, quav);
    play(note_FS4, quav);
    play(note_G4, quav);
    play(note_A4, quav);
    play(note_FS4, quav);
    // bar 13
    play(note_G4, crot + quav);
    play(note_FS4, quav);
    play(note_E4, quav);
    play(note_FS4, quav);
    play(note_G4, quav);
    play(note_E4, quav);
    // bar 14
    play(note_FS4, crot + quav);
    play(note_E4, quav);
    play(note_D4, crot);
    play(note_D4, crot);
    // bar 15
    play(note_E4, crot);
    play(note_G4, crot);
    play(note_G4, crot);
    play(note_FS4, crot);
    // bar 16
    play(note_G4, minim);
    play(note_G4, crot);
    rest(crot);
  }
}

void good_king_wenceslas() {
  set_tempo(vivace);
  // 4/4 time
  for (uint8_t repeat = 1; repeat <= 2; repeat++) {
    // intro bar
    rest(minim);
    // bar 1
    play(note_G4, crot);
    play(note_G4, crot);
    play(note_G4, crot);
    play(note_A4, crot);
    // bar 2
    play(note_G4, crot);
    play(note_G4, crot);
    play(note_D4, minim);
    // bar 3
    play(note_E4, crot);
    play(note_D4, crot);
    play(note_E4, crot);
    play(note_FS4, crot);
    // bar 4
    play(note_G4, minim);
    play(note_G4, minim);
    // bar 5
    play(note_G4, crot);
    play(note_G4, crot);
    play(note_G4, crot);
    play(note_A4, crot);
    // bar 6
    play(note_G4, crot);
    play(note_G4, crot);
    play(note_D4, minim);
    // bar 7
    play(note_E4, crot);
    play(note_D4, crot);
    play(note_E4, crot);
    play(note_FS4, crot);
    // bar 8
    play(note_G4, minim);
    play(note_G4, minim);
    // bar 9
    play(note_D5, crot);
    play(note_C5, crot);
    play(note_B4, crot);
    play(note_A4, crot);
    // bar 10
    play(note_B4, crot);
    play(note_A4, crot);
    play(note_G4, minim);
    // bar 11
    play(note_E4, crot);
    play(note_D4, crot);
    play(note_E4, crot);
    play(note_FS4, crot);
    // bar 12
    play(note_G4, minim);
    play(note_G4, minim);
    // bar 13
    play(note_D4, crot);
    play(note_D4, crot);
    play(note_E4, crot);
    play(note_FS4, crot);
    // bar 14
    play(note_G4, crot);
    play(note_G4, crot);
    play(note_A4, minim);
    // bar 15
    play(note_D5, crot);
    play(note_C5, crot);
    play(note_B4, crot);
    play(note_A4, crot);
    // bar 16
    play(note_G4, minim);
    play(note_C5, minim);
    // bar 17
    play(note_G4, semib);
  }
}

void the_first_nowell() {
  set_tempo(default_tempo);
  // 3/4 time
  for (uint8_t repeat = 1; repeat <= 2; repeat++) {
    // intro bar
    rest(minim);
    play(note_FS4, quav);
    play(note_E4, quav);
    // bar 1
    play(note_D4, crot + quav);
    play(note_E4, quav);
    play(note_FS4, quav);
    play(note_G4, quav);
    // bar 2
    play(note_A4, minim);
    play(note_B4, quav);
    play(note_CS5, quav);
    // bar 3
    play(note_D5, crot);
    play(note_CS5, crot);
    play(note_B4, crot);
    // bar 4
    play(note_A4, minim);
    play(note_B4, quav);
    play(note_CS5, quav);
    // bar 5
    play(note_D5, crot);
    play(note_CS5, crot);
    play(note_B4, crot);
    // bar 6
    play(note_A4, crot);
    play(note_B4, crot);
    play(note_CS5, crot);
    // bar 7
    play(note_D5, crot);
    play(note_A4, crot);
    play(note_G4, crot);
    // bar 8
    play(note_FS4, minim);
    play(note_FS4, quav);
    play(note_E4, quav);
    // bar 9
    play(note_D4, crot + quav);
    play(note_E4, quav);
    play(note_FS4, quav);
    play(note_G4, quav);
    // bar 10
    play(note_A4, minim);
    play(note_B4, quav);
    play(note_CS5, quav);
    // bar 11
    play(note_D5, crot);
    play(note_CS5, crot);
    play(note_B4, crot);
    // bar 12
    play(note_A4, minim);
    play(note_B4, quav);
    play(note_CS5, quav);
    // bar 13
    play(note_D5, crot);
    play(note_CS5, crot);
    play(note_B4, crot);
    // bar 14
    play(note_A4, crot);
    play(note_B4, crot);
    play(note_CS5, crot);
    // bar 15
    play(note_D5, crot);
    play(note_A4, crot);
    play(note_G4, crot);
    // bar 16
    play(note_FS4, minim);
    play(note_FS4, quav);
    play(note_E4, quav);
    // bar 17
    play(note_D4, crot + quav);
    play(note_E4, quav);
    play(note_FS4, quav);
    play(note_G4, quav);
    // bar 18
    play(note_A4, minim);
    play(note_D5, quav);
    play(note_CS5, quav);
    // bar 19
    play(note_B4, minim);
    play(note_B4, crot);
    // bar 20
    play(note_A4, dot_minim);
    // bar 21
    play(note_D5, crot);
    play(note_CS5, crot);
    play(note_B4, crot);
    // bar 22
    play(note_A4, crot);
    play(note_B4, crot);
    play(note_CS5, crot);
    // bar 23
    play(note_D5, crot);
    play(note_A4, crot);
    play(note_G4, crot);
    // bar 24
    play(note_FS4, dot_minim);
  }


}

void the_holly_and_the_ivy() {
  set_tempo(default_tempo);
  // 3/4 time
  for (uint8_t repeat = 1; repeat <= 2; repeat++) {
    // intro bar
    rest(minim);
    play(note_G4, crot);
    // bar 1
    play(note_G4, quav);
    play(note_G4, quav);
    play(note_G4, crot);
    play(note_E5, crot);
    // bar 2
    play(note_D5, crot);
    play(note_B4, crot + quav);
    play(note_G4, quav);
    // bar 3
    play(note_G4, quav);
    play(note_G4, quav);
    play(note_G4, crot);
    play(note_E5, crot);
    // bar 4
    play(note_D5, minim);
    play(note_D5, quav);
    play(note_C5, quav);
    // bar 5
    play(note_B4, quav);
    play(note_A4, quav);
    play(note_G4, crot);
    play(note_B4, quav);
    play(note_B4, quav);
    // bar 6
    play(note_E4, quav);
    play(note_E4, quav);
    play(note_D4, crot);
    play(note_G4, quav);
    play(note_A4, quav);
    // bar 7
    play(note_B4, quav);
    play(note_C5, quav);
    play(note_B4, crot);
    play(note_A4, quav);
    play(note_A4, quav);
    // bar 8
    play(note_G4, minim);
    play(note_G4, quav);
    play(note_G4, quav);
    // bar 9
    play(note_G4, quav);
    play(note_G4, quav);
    play(note_G4, crot);
    play(note_E5, crot);
    // bar 10
    play(note_D5, crot);
    play(note_B4, crot);
    play(note_G4, quav);
    play(note_G4, quav);
    // bar 11
    play(note_G4, quav);
    play(note_G4, quav);
    play(note_G4, crot);
    play(note_E5, crot);
    // bar 12
    play(note_D5, minim);
    play(note_D5, quav);
    play(note_C5, quav);
    // bar 13
    play(note_B4, quav);
    play(note_A4, quav);
    play(note_G4, crot);
    play(note_B4, crot);
    //  bar 14
    play(note_E4, quav);
    play(note_E4, quav);
    play(note_D4, crot);
    play(note_G4, quav);
    play(note_A4, quav);
    // bar 15
    play(note_B4, quav);
    play(note_C5, quav);
    play(note_B4, crot);
    play(note_A4, crot);
    // bar 16
    play(note_G4, minim);
    rest(crot);
  }
}

void we_three_kings() {
  set_tempo(default_tempo);
  // 3/8 time
  for (uint8_t repeat = 1; repeat <= 2; repeat++) {
    // bar 1
    play(note_B4, crot);
    play(note_A4, quav);
    // bar 2
    play(note_G4, crot);
    play(note_E4, quav);
    // bar 3
    play(note_FS4, quav);
    play(note_G4, quav);
    play(note_FS4, quav);
    // bar 4
    play(note_E4, crot + quav);
    // bar 5
    play(note_B4, crot);
    play(note_A4, quav);
    // bar 6
    play(note_G4, crot);
    play(note_E4, quav);
    // bar 7
    play(note_FS4, quav);
    play(note_G4, quav);
    play(note_FS4, quav);
    // bar 8
    play(note_E4, crot + quav);
    // bar 9
    play(note_G4, quav + quav);
    play(note_G4, quav);
    // bar 10
    play(note_A4, crot);
    play(note_A4, quav);
    // bar 11
    play(note_B4, crot);
    play(note_B4, quav);
    // bar 12
    play(note_D5, quav);
    play(note_C5, quav);
    play(note_B4, quav);
    // bar 13
    play(note_A4, quav);
    play(note_B4, quav);
    play(note_A4, quav);
    // bar 14
    play(note_G4, crot);
    play(note_FS4, quav);
    // bar 15
    play(note_E4, crot + quav);
    // bar 16
    play(note_FS4, crot + quav);
    // bar 17
    play(note_A4, crot + quav);
    // bar 18
    play(note_G4, crot);
    play(note_G4, quav);
    // bar 19
    play(note_G4, crot);
    play(note_D4, quav);
    // bar 20
    play(note_G4, crot);
    play(note_E4, quav);
    // bar 21
    play(note_G4, crot + quav);
    // bar 22
    play(note_G4, crot);
    play(note_G4, quav);
    // bar 23
    play(note_G4, crot);
    play(note_D4, quav);
    // bar 24
    play(note_G4, crot);
    play(note_E4, quav);
    // bar 25
    play(note_G4, crot + quav);
    // bar 26
    play(note_G4, crot);
    play(note_G4, quav);
    // bar 27
    play(note_A4, crot);
    play(note_B4, quav);
    // bar 28
    play(note_C5, crot);
    play(note_B4, quav);
    // bar 29
    play(note_A4, crot);
    play(note_B4, quav);
    // bar 30
    play(note_G4, crot);
    play(note_G4, quav);
    // bar 31
    play(note_G4, crot);
    play(note_D4, quav);
    // bar 32
    play(note_G4, crot);
    play(note_E4, quav);
    // bar 33
    play(note_G4, crot + quav);
    // bar 34
    rest(crot + quav);
  }
}

void silent_night() {
  set_tempo(default_tempo);
  // 3/4 time
  // intro bar
  rest(crot);
  for (uint8_t repeat = 1; repeat <= 2; repeat++) {
    // bar 1
    play(note_G4, crot + quav);
    play(note_A4, quav);
    play(note_G4, crot);
    // bar 2
    play(note_E4, dot_minim);
    // bar 3
    play(note_G4, crot + quav);
    play(note_A4, quav);
    play(note_G4, crot);
    // bar 4
    play(note_E4, dot_minim);
    // bar 5
    play(note_D5, minim);
    play(note_D5, crot);
    // bar 6
    play(note_B4, dot_minim);
    // bar 7
    play(note_C5, minim);
    play(note_C5, crot);
    // bar 8
    play(note_G4, dot_minim);
    // bars 9-12 and 13-16 are identical so repeat twice
    for (uint8_t pass = 1; pass <= 2; pass++) {
      // bar 9, bar 13
      play(note_A4, minim);
      play(note_A4, crot);
      // bar 10, bar 14
      play(note_C5, crot + quav);
      play(note_B4, quav);
      play(note_A4, crot);
      // bar 11, bar 15
      play(note_G4, crot + quav);
      play(note_A4, quav);
      play(note_G4, crot);
      // bar 12, bar 16
      play(note_E4, dot_minim);
    }
    // bar 17
    play(note_D5, minim);
    play(note_D5, crot);
    // bar 18
    play(note_F5, crot + quav);
    play(note_D5, quav);
    play(note_B4, crot);
    // bar 19
    play(note_C5, dot_minim);
    // bar 20
    play(note_E5, dot_minim);
    // bar 21
    play(note_C5, crot);
    play(note_G4, crot);
    play(note_E4, crot);
    // bar 22
    play(note_G4, crot + quav);
    play(note_F4, quav);
    play(note_D4, crot);
    // bars 23 & 24
    play(note_C4, dot_minim + dot_minim);
  }
}

void jingle_bells() {
  set_tempo(default_tempo * 2); // very lively
  // 4/4 time
  // intro bar
  rest(minim);
  for (uint8_t repeat = 1; repeat <= 2; repeat++) {
    // bar 1
    play(note_B3, crot);
    play(note_B3, crot);
    play(note_B3, minim);
    // bar 2
    play(note_B3, crot);
    play(note_B3, crot);
    play(note_B3, minim);
    // bar 3
    play(note_B3, crot);
    play(note_D4, crot);
    play(note_G3, crot);
    play(note_A3, crot);
    // bar 4
    play(note_B3, semib);
    // bar 5
    play(note_C4, crot);
    play(note_C4, crot);
    play(note_C4, crot);
    play(note_C4, crot);
    // bar 6
    play(note_C4, crot);
    play(note_B3, crot);
    play(note_B3, crot);
    play(note_B3, crot);
    // bar 7
    play(note_B3, crot);
    play(note_A3, crot);
    play(note_A3, crot);
    play(note_B3, crot);
    // bar 8
    play(note_A3, minim);
    play(note_D4, minim);
    // bar 9
    play(note_B3, crot);
    play(note_B3, crot);
    play(note_B3, minim);
    // bar 10
    play(note_B3, crot);
    play(note_B3, crot);
    play(note_B3, minim);
    // bar 11
    play(note_B3, crot);
    play(note_D4, crot);
    play(note_G3, crot);
    play(note_A3, crot);
    // bar 12
    play(note_B3, semib);
    // bar 13
    play(note_C4, crot);
    play(note_C4, crot);
    play(note_C4, crot);
    play(note_C4, crot);
    // bar 14
    play(note_C4, crot);
    play(note_B3, crot);
    play(note_B3, crot);
    play(note_B3, crot);
    // bar 15
    play(note_D4, crot);
    play(note_D4, crot);
    play(note_C4, crot);
    play(note_A3, crot);
    // bar 16
    play(note_G3, semib);
  }
}
