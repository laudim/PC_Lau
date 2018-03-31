import processing.serial.*; //serial communication
import ddf.minim.*;

Serial myPort;
char val; //flex sensor vals from arduino

Minim minim; //audio objs
AudioPlayer wii;
AudioPlayer [] leaf = new AudioPlayer[2];
AudioPlayer [] leaf1 = new AudioPlayer[2];
AudioPlayer [] leaf2 = new AudioPlayer[2];
int i; //audio files increment

void setup(){
  size(200,200);
  
  //serial communication w arduino
  printArray(Serial.list());
  String portName = Serial.list()[1]; //change port #
  myPort = new Serial(this, portName, 9600);
  
  //load audio
  minim = new Minim(this);
  wii = minim.loadFile("purr.wav");
  
  for(int i = 0; i < leaf.length; i++){
  leaf[i] = minim.loadFile("giggle"+i+".wav");
}
  for(int i = 0; i < leaf1.length; i++){
  leaf1[i] = minim.loadFile("manscream"+i+".wav");
}
  for(int i = 0; i < leaf2.length; i++){
  leaf2[i] = minim.loadFile("growl"+i+".wav");
}
 
}


void draw(){
  if ( myPort.available() > 0) { // If data is available,
  val = myPort.readChar(); // read it and store it in val
  }
  
  i = (i + 1) % leaf.length;
  i = (i + 1) % leaf1.length;
  i = (i + 1) % leaf2.length;
  
  if (val == 'z'){
    wii.play();
    //wii.loop();
  }
  
  if (val == 'a'){
    wii.pause();
    leaf[i].play();
    leaf[i].rewind();
  }
  
  if (val == 'b'){
    wii.pause();
    leaf1[i].play();
    leaf1[i].rewind();
  }
  
  if (val == 'c'){
    wii.pause();
    leaf2[i].play();
    leaf2[i].rewind();
  }
  
println(val);
}

void stop(){
  i = (i + 1) % leaf.length;
  i = (i + 1) % leaf1.length;
  i = (i + 1) % leaf2.length;
  wii.close();
  leaf[i].close();
  leaf1[i].close();
  leaf2[i].close();
  minim.stop();
}