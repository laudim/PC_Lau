/*
 RobotGeek Floormat Demo
 
 This example demonstrates the use of pinMode(INPUT_PULLUP) to read from
 a floormat switch. The code reads digital input on pin 2 and turns
 Digital Pin 4 HIGH when pin 2 goes LOW.
 
 The circuit: 
 Digital pin 2 -  Floor Mat Switch
 Digital pin 4 - LED / Buzzer / Relay / PowerSwitch Tail
 
 Since a raw switch like a floormat leaves the digital pin open we need to make
 use of an internal 20K-ohm resistor to pull up to 5V. This configuration causes
 the input to read HIGH when the switch is open, and LOW when it is closed. 
 
 Products Used in this demo
 - http://www.robotgeek.com/store/Search.aspx?SearchTerms=floor%20mat
 - http://www.robotgeek.com/robotgeek-geekduino-sensor-kit
 - http://www.robotgeek.com/robotgeek-led-driver
 - http://www.robotgeek.com/robotgeek-buzzer
 - http://www.robotgeek.com/store/p/6437-PowerSwitch-Tail-II.aspx
 - http://www.robotgeek.com/robotgeek-relay
 - http://www.robotgeek.com/robotgeek-small-workbench.aspx
 - http://www.robotgeek.com/p/power-supply-6vdc-2a.aspx

 */

int pressPlate = 2;

void setup(){
  Serial.begin(9600);

  //configure pin1 as an input and enable the internal pull-up resistor
  pinMode(pressPlate, INPUT_PULLUP);
  //configure pin4 as output
  //pinMode(2, OUTPUT);
  pinMode(3, OUTPUT);
  pinMode(4, OUTPUT);
  pinMode(5, OUTPUT);
  pinMode(6, OUTPUT);
  pinMode(7, OUTPUT);
  pinMode(8, OUTPUT);
  pinMode(9, OUTPUT); 
  pinMode(10, OUTPUT); 
  pinMode(11, OUTPUT); 
  pinMode(12, OUTPUT);
  pinMode(13, OUTPUT); 

}

void loop(){
  //read the pin1 state into a variable
  int sensorVal = digitalRead(pressPlate);

  
  // Keep in mind the pullup means the pushbutton's
  // logic is inverted. It is HIGH when it's open,
  // and LOW when it's pressed. Turn on pin 4 when the 
  // floormat is stepped on, and off when it's not:
  if (sensorVal == HIGH) {
    //digitalWrite(2, LOW);
    digitalWrite(3, LOW);
    digitalWrite(4, LOW);
    digitalWrite(5, LOW);
    digitalWrite(6, LOW);
    digitalWrite(7, LOW);
    digitalWrite(8, LOW);
    digitalWrite(9, LOW);
    digitalWrite(10, LOW);
    digitalWrite(11, LOW);
    digitalWrite(12, LOW);
    digitalWrite(13, LOW);
  } 
  else {
    //digitalWrite(2, HIGH);
    digitalWrite(3, HIGH);
    digitalWrite(4, HIGH);
    digitalWrite(5, HIGH);
    digitalWrite(6, HIGH);
    digitalWrite(7, HIGH);
    digitalWrite(8, HIGH);
    digitalWrite(9, HIGH);
    digitalWrite(10, HIGH);
    digitalWrite(11, HIGH);
    digitalWrite(12, HIGH);
    digitalWrite(13, HIGH);
  }
  
  Serial.println(sensorVal);
  delay(100);
}



