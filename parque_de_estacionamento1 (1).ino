// C++ code
//
#include <Servo.h>

long readUltrasonicDistance(int triggerPin, int echoPin)
{
  pinMode(triggerPin, OUTPUT);  // Clear the trigger
  digitalWrite(triggerPin, LOW);
  delayMicroseconds(2);
  // Sets the trigger pin to HIGH state for 10 microseconds
  digitalWrite(triggerPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(triggerPin, LOW);
  pinMode(echoPin, INPUT);
  // Reads the echo pin, and returns the sound wave travel time in microseconds
  return pulseIn(echoPin, HIGH);
}

Servo servo_13;

Servo servo_12;

void setup()
{
  pinMode(LED_BUILTIN, OUTPUT);
  servo_13.attach(13, 500, 2500);
  pinMode(11, OUTPUT);
  servo_12.attach(12, 500, 2500);
}

void loop()
{
  digitalWrite(LED_BUILTIN, HIGH);
  delay(1000); // Wait for 1000 millisecond(s)
  digitalWrite(LED_BUILTIN, LOW);
  delay(1000); // Wait for 1000 millisecond(s)

  if (0.01723 * readUltrasonicDistance(7, 7) < 70) {
    servo_13.write(90);
  } else {
    servo_13.write(0);
  }
  if (0.01723 * readUltrasonicDistance(7, 7) < 70) {
    tone(11, 523, 1000); // play tone 60 (C5 = 523 Hz)
  }

  digitalWrite(LED_BUILTIN, HIGH);

  if (0.01723 * readUltrasonicDistance(8, 8) < 90) {
    servo_12.write(90);
  } else {
    servo_12.write(0);
  }
}