/******************************************************************************
ambient-data-display-project-sketch.ino
Sketch for connecting 3 sets of servos and arcade buttons to a SparkFun RedBoard and breadboard

Adalia Lee and Isabella Pan
Due Friday, 02/28/2025

Development environment specifics:
Arduino 1.6.5
******************************************************************************/

#include <Servo.h>

Servo Servo1;   // Servo for water lily plant
Servo Servo2;   // Servo for orchid plant
Servo Servo3;   // Servo for thale cress plant

void setup() {
  pinMode(8, INPUT_PULLUP);   // Button attached to pin 8 (for the low frequency range 0 - 333 Hz)
  Servo1.attach(9);   // Servo attached to pin 9
  Servo1.write(5);   // Start servo at position 5 degrees

  pinMode(12, INPUT_PULLUP);   // Button attached to pin 12 (for the middle frequency range 334 - 667 Hz)
  Servo2.attach(11);   // Servo attached to pin 11
  Servo2.write(5);   // Start servo at position 5 degrees

  pinMode(2, INPUT_PULLUP);   // Button attached to pin 2 (for the high frequency range 668 - 1,000+ Hz)
  Servo3.attach(3);   // Servo attached to pin 3
  Servo3.write(5);   // Start servo at position 5 degrees
}

void loop() {
  if (digitalRead(8) == LOW) {   // If low frequency button is pressed
    // Rotate servo to position 175 degrees
    Servo1.write(175);
    Servo2.write(175);
    Servo3.write(175);
  }
  if (digitalRead(12) == LOW) {   // If middle frequency button is pressed
    // Rotate servo to position 90 degrees
    Servo1.write(90);
    Servo2.write(90);
    Servo3.write(90);
  }
  if (digitalRead(2) == LOW) {   // If high frequency button is pressed
    // Rotate servo to position 5 degrees
    Servo1.write(5);
    Servo2.write(5);
    Servo3.write(5);
  }
}