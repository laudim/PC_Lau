import processing.video.*;
import processing.serial.*;

Serial myPort; // creates object from Serial class
int angle;
Capture video;


void setup(){
size (640, 480);

printArray(Serial.list()); // this line prints the port list to the console
String portName = Serial.list()[1]; //change the number in the [] for the port you need
myPort = new Serial(this, portName, 9600);

video = new Capture(this, 640, 480);
video.start();

}

void draw(){
  if ( myPort.available() > 0) { // If data is available,
angle = myPort.read(); // read it and store it in angle
}

  image(video, 0,0);
  if(angle > 50){
    tint(255,0,0);
  } else {
    tint(255);
  }
    
  println(angle);
}

void captureEvent(Capture c){
  c.read();
}