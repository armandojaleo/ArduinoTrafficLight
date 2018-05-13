#include "SR04.h"
#include <Servo.h>

#define TRIG_PIN 12
#define ECHO_PIN 11
#define BLUE 3
#define GREEN 5
#define RED 6

SR04 sr04 = SR04(ECHO_PIN, TRIG_PIN);
Servo myservo;

long a;
int redValue;
int greenValue;
int blueValue;
int pos = 0;
int red = 1;

void setup() {
  Serial.begin(9600);
  pinMode(RED, OUTPUT);
  pinMode(GREEN, OUTPUT);
  pinMode(BLUE, OUTPUT);
  digitalWrite(RED, HIGH);
  digitalWrite(GREEN, LOW);
  digitalWrite(BLUE, LOW);
  myservo.attach(9);
}

void loop() {
  a = sr04.Distance();
  if (a < 10)
  {
    redValue = 0;
    greenValue = 255;
    blueValue = 0;
    pos = 65;
    analogWrite(BLUE, blueValue);
    analogWrite(RED, redValue);
    analogWrite(GREEN, greenValue);
    myservo.write(pos);
    delay(5000);
    red = 1;
  }
  else
  {
    if (red == 1)
    {
      redValue = 255;
      greenValue = 140;
      blueValue = 0;
      analogWrite(BLUE, blueValue);
      analogWrite(RED, redValue);
      analogWrite(GREEN, greenValue);
      delay(2000);
    }
    redValue = 255;
    greenValue = 0;
    blueValue = 0;
    pos = 10;
    analogWrite(BLUE, blueValue);
    analogWrite(RED, redValue);
    analogWrite(GREEN, greenValue);
    myservo.write(pos);
    delay(3000);
    red = 0;
  }
  delay(100);
}
