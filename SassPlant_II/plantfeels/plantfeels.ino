//test motors w serial.write'a' etc

//motor
#include <Servo.h> 

//FSR sensors
int sensorPin = 0; //sensors hooked up to analog pin #
int sensorPin1 = 1;
int sensorPin2 = 2;
int val = 0; //fsr values put into val
int val1 = 0;
int val2 = 0;

//motor inputs
int servoPin = 9; //motor hooked up to digital pin 9
Servo servo;
int angle = 0; //motor x position (degrees)
int stopangle = 90; //motor rest position (degrees)

void setup() {
  servo.attach(servoPin); //motor
Serial.begin(9600); // Start serial communication at 9600 bps
}

void loop() {
val = analogRead(sensorPin); //read sensor and assign to variable called val
val1 = analogRead(sensorPin1);
val2 = analogRead(sensorPin2);

if (val > 100){ //sweet spot, top leaf
  Serial.write('a');
  for(angle = 90; angle > 0; angle--){
  servo.write(angle); //motor moves fwd
  delay(10);//speed of motor
  }
  servo.write(stopangle); //then stops  
} else {
  Serial.write('z');
}


if (val2 > 100){ //middle leaf
  Serial.write('b');
  for(angle = 90; angle < 120; angle++){
  servo.write(angle); //motor moves fwd
  delay(6);//speed of motor
  }
  for(angle = 120; angle > 60; angle--){ //motor moves bwd                                
    servo.write(angle);           
    delay(6);     
  }
  for(angle = 60; angle < 120; angle++){
  servo.write(angle); //motor moves fwd
  delay(6);
  }
  for(angle = 120; angle > 0; angle--){ //motor moves bwd                                
    servo.write(angle);           
    delay(6);     
  }
  servo.write(stopangle); //then stops
} else {
  Serial.write('z');
}


if (val1 > 100){ //bottom leaf
  Serial.write('c');
  for(angle = 0; angle < 180; angle++){
  servo.write(angle); //motor moves fwd
  delay(3);//speed of motor
  }
  for(angle = 180; angle > 0; angle--){ //motor moves bwd                                
    servo.write(angle);           
    delay(7);     
  }
  for(angle = 0; angle < 180; angle++){
  servo.write(angle); //motor moves fwd
  delay(6);
  }
  servo.write(stopangle); //then stops
} else {
  Serial.write('z');
}


delay(100);
}
