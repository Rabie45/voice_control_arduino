/*
 * Discreption this progect is to control smart room with sound download this app for android 
 * https://play.google.com/store/apps/details?id=appinventor.ai_cempehlivan92.Arduino_Sesli_Kontrol
 * the home consests of to rooms conected to relay  
 * and sd card moudle 
 * CS -> 10
 * SCK -> 13
 * MOSI -> 11
 * MISO-> 12
 * VCC -> +5v
 * GND-> Arduino's Ground
 * the spekear connected to PIN 9 in arduino and the other pin to the ground
 
*/
#include "SD.h" //SD card moudule 
#define led 1   //first room lamb
#define led1 2   //Second room lamb
#define SD_ChipSelectPin 10  //PIN 10 in arduino
#include "TMRpcm.h" //this library is used with sounds 
#include "SPI.h"  //SPI comm for Sd card 

TMRpcm tmrpcm;
void setup() {
  pinMode(led,OUTPUT);
  pinMode(led1,OUTPUT);
 //Wire.begin();
tmrpcm.speakerPin=9; //the pin connected to the speaker 
Serial.begin(9600);
  // put your setup code here, to run once:

}

void loop() {
  char num;
  lable1:
  Serial.println("what do u need light or music :");
   while(Serial.available()==0){} //stay in while loop until Serial recive any data
while(Serial.available()){
  String x =Serial.readString(); //to read a string from the Serial
  Serial.println(x);
  if(x=="music"){
    Serial.println("enter the num of the song:");
  while(Serial.available()==0){} //stay in while loop until Serial recive any data
    num=Serial.read();//to read a Char from the Serial
    Serial.println(num);
    if(num=='1'){
    tmrpcm.setVolume(6);
    tmrpcm.play("music_name.wav"); //start the song
    Serial.println("music_name.wav");
    Serial.println("press y to stop");
    }
    else if(num=='2'){
    tmrpcm.setVolume(6);
    tmrpcm.play("msuic_name1.wav");//start the song
    Serial.println("music_name1.wav");
    Serial.println("press y to stop");
    }
    while(Serial.available()==0){}
    String st=Serial.readString();
    if(st=="stop music"){ //say stop music to stop the music
      goto lable;
    }
    else{
      goto lable1;  // this function if the user enter any unkown word 
    }
   }
   else if(num=='y'){
      lable:
  tmrpcm.stopPlayback();//say stop music to stop the  
   Serial.println("stop music"); 
  }
  
  else if(x=="light"){
   roo:
   Serial.print("which room?"); //choose the room to turn one 
    while(Serial.available()==0){} //stay in while loop until Serial recive any data
    String room=Serial.readString();  
    if(room=="room1"){
  Serial.println("Room 1 on"); 
     digitalWrite(led,1); //turn on the room
      goto roo;
    }
    else if(room=="room off"){ //turn off both of the rooms
      digitalWrite(led,0);
      digitalWrite(led1,0); 
       Serial.println("room of");
    }
      else if(room=="Room 2 on"){
      digitalWrite(led1,1); //turn on the room
     //   Wire.beginTransmission(2);
      //Wire.write('2');
   // Wire.endTransmission();
       Serial.println("Room 2 on");
    }
  }
 
    
  }
}
