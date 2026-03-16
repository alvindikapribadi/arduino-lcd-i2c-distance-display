/*
  Arduino LCD I2C Distance Display
  --------------------------------
  Display distance from HC-SR04 sensor on LCD 16x2 I2C

  Components:
  - Arduino UNO/Nano
  - HC-SR04 Ultrasonic Sensor
  - LCD 16x2 I2C

  Wiring:

  HC-SR04
  VCC  -> 5V
  GND  -> GND
  TRIG -> D9
  ECHO -> D10

  LCD I2C
  VCC -> 5V
  GND -> GND
  SDA -> A4
  SCL -> A5
*/

#include <Wire.h>
#include <LiquidCrystal_I2C.h>

#define TRIG_PIN 9
#define ECHO_PIN 10

LiquidCrystal_I2C lcd(0x27, 16, 2);

long duration;
float distance;

void setup() {

  pinMode(TRIG_PIN, OUTPUT);
  pinMode(ECHO_PIN, INPUT);

  lcd.init();
  lcd.backlight();

  lcd.setCursor(0,0);
  lcd.print("Distance Meter");
  delay(2000);
  lcd.clear();
}

void loop() {

  digitalWrite(TRIG_PIN, LOW);
  delayMicroseconds(2);

  digitalWrite(TRIG_PIN, HIGH);
  delayMicroseconds(10);
  digitalWrite(TRIG_PIN, LOW);

  duration = pulseIn(ECHO_PIN, HIGH);

  distance = duration * 0.034 / 2;

  lcd.setCursor(0,0);
  lcd.print("Distance:");

  lcd.setCursor(0,1);
  lcd.print(distance);
  lcd.print(" cm   ");

  delay(300);
}