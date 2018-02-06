//Lauren
//push button, makes led lights blink sequentially

const int buttonPin = 7;     // the number of the pushbutton pin
const int ledPin1 =  13;
const int ledPin2 =  12;
const int ledPin3 =  11;
const int ledPin4 =  10;     // the number of the LED pin

// variables will change:
int buttonState = 0;         // variable for reading the pushbutton status


void setup() {
  // put your setup code here, to run once:
pinMode(ledPin1, OUTPUT);
  pinMode(ledPin2, OUTPUT);
  pinMode(ledPin3, OUTPUT);
  pinMode(ledPin4, OUTPUT);
  // initialize the pushbutton pin as an input:
  pinMode(buttonPin, INPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
buttonState = digitalRead(buttonPin);
  
  if (buttonState == HIGH) {
    // turn LED on:

  digitalWrite(ledPin2, HIGH);
  delay(200);
  digitalWrite(ledPin4, HIGH);
  delay(300);  
  digitalWrite(ledPin1, HIGH);
  delay(200);
  digitalWrite(ledPin3, HIGH);
  delay(300);
  
  } else {
    // turn LED off:

  digitalWrite(ledPin1, LOW);
  //delay(200);
  digitalWrite(ledPin2, LOW);
  //delay(300);
  digitalWrite(ledPin3, LOW);
  //delay(400);
  digitalWrite(ledPin4, LOW);
  //delay(500);
}
}
