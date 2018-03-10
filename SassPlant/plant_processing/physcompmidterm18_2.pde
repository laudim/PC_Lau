//based on minim library exercise from coding class FA17 and research on processing forum

import processing.serial.*; //serial communication
import ddf.minim.*;

Serial myPort;
int val; //flex sensor vals from arduino
int val1;
int val2;

boolean playing = false;
String growl = "growl2.mp3";

Minim minim; //audio objs
AudioPlayer player;
AudioOutput out;

void setup(){
  //serial communication w arduino
  printArray(Serial.list());
  String portName = Serial.list()[1]; //change port #
  myPort = new Serial(this, portName, 9600);
  
  //load audio
  minim = new Minim(this);
  
  //open audio out
  out = minim.getLineOut();
}


void draw(){
  if ( myPort.available() > 0) { // If data is available,
  val = myPort.read(); // read it and store it in val
  val1 = myPort.read();
  val2 = myPort.read();
  }
 
  
  if (val > 50 && playing==false){
    //loads mp3 file and create new player obj
  player = minim.loadFile(growl);
    player.play();
    playing = true;
  } else if (val < 48 && playing==true){
    playing = false;
  }
  
  if (val1 > 50 && playing==false){
    //loads mp3 file and create new player obj
  player = minim.loadFile(growl);
    player.play();
    playing = true;
  } else if (val1 < 48 && playing==true){
    playing = false;
  }
  
  if (val2 > 50 && playing==false){
    //loads mp3 file and create new player obj
  player = minim.loadFile(growl);
    player.play();
    playing = true;
  } else if (val2 < 48 && playing==true){
    playing = false;
  }
  
  
println(val);
println(val1);
println(val2);
}

void stop(){
  player.close();
}