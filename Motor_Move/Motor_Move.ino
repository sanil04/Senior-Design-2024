#include <Wire.h>
#include <Adafruit_MotorShield.h>
#include "Adafruit_TCS34725.h"

// Motor control pins
#define ENA 5   // PWM for Motor1 speed
#define ENB 6   // PWM for Motor2 speed
#define IN1 9   // Motor1 forward
#define IN2 10  // Motor1 backward
#define IN3 11  // Motor2 forward
#define IN4 12  // Motor2 backward

void setup() {
  // Set motor control pins as outputs
  pinMode(ENA, OUTPUT);
  pinMode(ENB, OUTPUT);
  pinMode(IN1, OUTPUT);
  pinMode(IN2, OUTPUT);
  pinMode(IN3, OUTPUT);
  pinMode(IN4, OUTPUT);
}

void loop() {
  // Example 1: Motor1 Forward, Motor2 Backward
  analogWrite(ENA, 200); // Motor1 speed (0-255)
  digitalWrite(IN1, HIGH);
  digitalWrite(IN2, LOW);

  analogWrite(ENB, 150); // Motor2 speed (0-255)
  digitalWrite(IN3, LOW);
  digitalWrite(IN4, HIGH);

  delay(3000); // Run for 3 seconds

  // Example 2: Both Motors Stop
  analogWrite(ENA, 0); // Motor1 stop
  analogWrite(ENB, 0); // Motor2 stop
  delay(1000); // Wait for 1 second

  // Example 3: Motor1 Backward, Motor2 Forward
  analogWrite(ENA, 128); // Motor1 speed (0-255)
  digitalWrite(IN1, LOW);
  digitalWrite(IN2, HIGH);

  analogWrite(ENB, 255); // Motor2 speed (0-255)
  digitalWrite(IN3, HIGH);
  digitalWrite(IN4, LOW);

  delay(3000); // Run for 3 seconds

  // Example 4: Stop both motors
  analogWrite(ENA, 0); // Stop Motor1
  analogWrite(ENB, 0); // Stop Motor2
  delay(1000); // Wait for 1 second
}
