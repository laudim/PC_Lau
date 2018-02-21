/*
Adafruit Arduino - Lesson 14. Knob
*/
 
#include <Servo.h> 
 
int potPin = 0;  
int servoPin = 9;
int angle = 0;
int reading = 0;
Servo servo; 
 
void setup() 
{ 
  Serial.begin(9600);
  servo.attach(servoPin);  
} 
 
void loop() 
{ 
  reading = analogRead(potPin);     // 0 to 1023
  angle = reading / 6;              // 0 to 180-ish
  servo.write(angle);
  delay(100);
  Serial.println(angle);  
} 
