/******************************************************************************
servo-sketch.ino
Example sketch for connecting a servo to a SparkFun RedBoard
  Servo Motor: (https://www.sparkfun.com/products/11965)
  SparkFun RedBoard: (https://www.sparkfun.com/products/13975)
Byron Jacquot@ SparkFun Electronics
May 17, 2016

**SparkFun code, firmware, and software is released under the MIT License(http://opensource.org/licenses/MIT).**

Development environment specifics:
Arduino 1.6.5
******************************************************************************/

#include <Servo.h>

Servo Servo1;  // Servo for water lily plant
Servo Servo2;  // Servo for orchid plant
Servo Servo3;  // Servo for thale cress plant

int servoPosition = 10;  // Variable to store servo position

void setup() {
    pinMode(8, INPUT_PULLUP);  // Button with pin 8 as the input (for the low frequency range 0 - 300 Hz)
    Servo1.attach(9);  // Attach the servo to pin 9
    Servo1.write(10); // Start the Servo at position 0
    Serial.begin(9600); // Set up our Serial Monitor on baud 9600 to display and receive data if needed

    pinMode(12, INPUT_PULLUP);
    Servo2.attach(11);
    Servo2.write(10);

    pinMode(2, INPUT_PULLUP);
    Servo3.attach(3);
    Servo3.write(10);
}

void loop() {
    if (digitalRead(8) == LOW) {  // If button (connected to pin 8) is pressed
        Servo1.write(175);  // Move servo to 175 degrees
        Servo2.write(175);
        Servo3.write(175);
    }
    if (digitalRead(12) == LOW) {
        Servo1.write(90);  // Move servo to 175 degrees
        Servo2.write(90);
        Servo3.write(90);
    }
    if (digitalRead(2) == LOW) {
        Servo1.write(5);  // Move servo to 175 degrees
        Servo2.write(5);
        Servo3.write(5);
    }
    Serial.println("servoPosition " + String(servoPosition));
}