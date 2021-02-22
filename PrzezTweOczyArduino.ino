#include "pitches.h"

// notes in the melody:
int melody[] = {
  NOTE_AS4, NOTE_C5, NOTE_CS5, NOTE_CS5, NOTE_C5, NOTE_CS5, NOTE_CS5, NOTE_C5, NOTE_CS5, NOTE_C5, NOTE_AS4, 0, NOTE_DS5, NOTE_F5, NOTE_FS5, NOTE_AS4, NOTE_AS4, 0, NOTE_AS4, NOTE_AS4, NOTE_C5, NOTE_C5, NOTE_AS4, NOTE_C5, NOTE_C5, NOTE_AS4, NOTE_C5, NOTE_AS4, NOTE_GS4, 0, NOTE_FS5, NOTE_DS5, NOTE_DS5, NOTE_F5, NOTE_DS5, NOTE_CS5, NOTE_C5, 0, NOTE_AS4, NOTE_C5, NOTE_CS5, NOTE_CS5, NOTE_C5, NOTE_CS5, NOTE_CS5, NOTE_C5, NOTE_CS5, NOTE_C5, NOTE_AS4, 0, NOTE_DS5, NOTE_F5, NOTE_FS5, NOTE_AS4, NOTE_AS4, 0, NOTE_DS5, NOTE_CS5, NOTE_C5, NOTE_C5, NOTE_CS5, NOTE_C5, NOTE_C5, NOTE_C5, NOTE_CS5, NOTE_C5, NOTE_AS4, NOTE_A4, NOTE_C5, NOTE_AS4  
};

// note durations: 4 = quarter note, 8 = eighth note, etc.:
int noteDurations[] = {
  4, 4, 8, 8, 8, 4, 8, 8, 8, 8, 4, 8, 4, 4, 8, 4, 2, 2, 4, 4, 8, 8, 8, 4, 8, 8, 8, 8, 4, 8, 8, 4, 4, 2, 8, 8, 3, 4, 4, 4, 8, 8, 8, 4, 8, 8, 8, 8, 4, 8, 4, 4, 8, 4, 1, 4, 4, 4, 8, 8, 8, 4, 8, 8, 4, 4, 4, 8, 4, 2
};

void setup() {
  pinMode(8, OUTPUT);
  
  pinMode(2, OUTPUT);
  pinMode(3, OUTPUT);
  pinMode(4, OUTPUT);
  pinMode(5, OUTPUT);
  pinMode(6, OUTPUT);
  pinMode(7, OUTPUT);
  pinMode(9, OUTPUT);
  // iterate over the notes of the melody:
  
}

void loop() {
  int i=1;
  for (int thisNote = 0; thisNote < 71; thisNote++) {

    // to calculate the note duration, take one second divided by the note type.
    //e.g. quarter note = 1000 / 4, eighth note = 1000/8, etc.
    int noteDuration = 1000 / noteDurations[thisNote];
    tone(8, melody[thisNote], noteDuration);

    // to distinguish the notes, set a minimum time between them.
    // the note's duration + 30% seems to work well:
    int pauseBetweenNotes = noteDuration * 1.30;
    if(i==1){
      digitalWrite(2, HIGH);
      digitalWrite(3, LOW);
      digitalWrite(4, HIGH);
      digitalWrite(5, LOW);
      digitalWrite(6, HIGH);
      digitalWrite(7, LOW);
      digitalWrite(9, HIGH);
      i=0;
    } else {
      digitalWrite(2, LOW);
      digitalWrite(3, HIGH);
      digitalWrite(4, LOW);
      digitalWrite(5, HIGH);
      digitalWrite(6, LOW);
      digitalWrite(7, HIGH);
      digitalWrite(9, LOW);
      i=1;     
    }
    delay(pauseBetweenNotes);
    // stop the tone playing:
    noTone(8);
  }
}
