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

if (val > 200){
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
//} else { //if no val
  //servo.write(stopangle); //motor doesn't move
}


if (val1 > 200){
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
//} else { //if no val1
  //servo.write(stopangle); //motor doesn't move
}


if (val2 > 200){
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
}


delay(100);
Serial.print(val); //print
Serial.print(val1);
Serial.print(val2);

}
