#include <Time.h>

#include <Servo.h> 


Servo x;
Servo y;
int laserPin = 7;
int xServoPin = 4;
int yServoPin = 2;
int scale = 3;
int del;
int letterHeight = -60; 
int letterWidth = 30;
int xLowBoundary = 1100;
int yLowBoundary = 1480;

int xHighBoundary = 1250;
int yHighBoundary = 1416;
int xPos = xLowBoundary;
int yPos = yLowBoundary;

void setup() {
Serial.begin(9600); 
pinMode(laserPin, OUTPUT);
x.attach(xServoPin); 
y.attach(yServoPin);

digitalWrite(laserPin,LOW);
x.writeMicroseconds(xPos);
y.writeMicroseconds(yPos);
setTime(4, 46, 0, 29,3, 2014);

}

void loop() {
String time = String(hour()) + ":" + String(minute());   
xHighBoundary = 1100 + 30*time.length()+15;
 for (int i = 0; i < time.length(); i++)
  {
  char c = time.charAt(i);
  switch (c) {
    case '0':
      drawZero();
      drawSpace();
      break;
    case '1':
      drawOne();
     drawSpace();
      break;
    case '2':
      drawTwo();
     drawSpace();
      break;
    case '3':
      drawThree();
      drawSpace();
      break;  
    case '4':
      drawFour();
      drawSpace();
      break;
    case '5':
      drawFive();
     drawSpace();
      break;  
    case '6':
      drawSix();
      drawSpace();
      break; 
    case '7':
      drawSeven();
      drawSpace();
      break;   
    case '8':
      drawEight();
     drawSpace();
      break;  
     case '9':
      drawNine();
      drawSpace();
      break; 
     case ':':
      drawColon();
      drawSpace();
      break;  
  }
if (xPos + letterWidth > xHighBoundary) { //character line wrap
       yPos = yPos + letterHeight + 5;
       xPos = xLowBoundary;
       updatePosition();
       delay(100);
    }
  
    if (yPos +letterHeight < yHighBoundary) { //panel wrap
      yPos = yLowBoundary;
      xPos = xLowBoundary; 
      updatePosition();
      delay(100);
}
Serial.println(xPos);

}
delay(1000);

}
void drawZero() {
  moveOn(0, letterHeight);
  moveOn(letterWidth, 0);
  moveOn(0, letterHeight*-1);
  moveOn(letterWidth*-1, 0);
  moveOff(letterWidth, 0);
}

void drawOne() {
  moveOff(letterWidth/4, 0);
  moveOn(letterWidth/4, 0);
  moveOn(0, letterHeight);
  moveOff(letterWidth/2, letterHeight*-1);
}

void drawTwo() {
  moveOn(letterWidth, 0);
  moveOn(0, letterHeight/2);
  moveOn(letterWidth*-1, 0);
  moveOn(0, letterHeight/2);
  moveOn(letterWidth, 0);
  moveOff(0, letterHeight*-1);
}

void drawThree() {
  moveOn(letterWidth,0);
  moveOn(0, letterHeight);
  moveOn(letterWidth*-1, 0);
  moveOff(0, letterHeight/-2);
  moveOn(letterWidth, 0);
  moveOff(0, letterHeight/-2);
}

void drawFour() {
  moveOn(0, letterHeight/2);
  moveOn(letterWidth, 0);
  moveOff(0, letterHeight/-2);
  moveOn(0, letterHeight);
  moveOff(0, letterHeight*-1);
}
void drawFive() {
  moveOff(letterWidth, 0);
  moveOn(letterWidth*-1, 0);
  moveOn(0, letterHeight/2);
  moveOn(letterWidth, 0);
  moveOn(0, letterHeight/2);
  moveOn(letterWidth*-1,0);
  moveOff(letterWidth, letterHeight* -1);

}
void drawSix() {
  moveOff(0,letterHeight/2);
  moveOn(letterWidth,0);
  moveOn(0,letterHeight/2);
  moveOn(letterWidth*-1, 0);
  moveOn(0, letterHeight*-1);
  moveOn(letterWidth, 0);
}

void drawSeven() {
  moveOn(letterWidth, 0);
  moveOn(letterWidth/-2, letterHeight);
  moveOff(letterWidth/2, letterHeight*-1);
}

void drawEight() {
  moveOn(0, letterHeight);
  moveOn(letterWidth, 0);
  moveOn(0, letterHeight*-1);
  moveOn(letterWidth*-1, 0);
  moveOff(0, letterHeight/2);
  moveOn(letterWidth, 0);
  moveOff(0, letterHeight/-2);
}

void drawNine() {
  moveOff(letterWidth, letterHeight/2);
  moveOn(letterWidth*-1, 0);
  moveOn(0,letterHeight/-2);
  moveOn(letterWidth, 0);
  moveOn(0, letterHeight);
  moveOn(letterWidth*-1, 0);
  moveOff(letterWidth, letterHeight *-1);
}
void drawColon() {
  moveOff(0,letterHeight/4);
  moveOn(0,0);
  moveOff(0, letterHeight/2);
  moveOn(0,0);
  moveOff(0, (letterHeight/4)*-3);
}
void drawSpace() {
  moveOff(letterWidth/2, 0); 
}

void moveOn (int xGo, int yGo) {
  digitalWrite(laserPin, HIGH);
  xPos = xPos + xGo;
  yPos = yPos + yGo;
  x.writeMicroseconds(xPos);
  y.writeMicroseconds(yPos);
  delay(75);
  digitalWrite(laserPin, LOW);

}
void moveOff (int xGo, int yGo) {
  xPos = xPos + xGo;
  yPos = yPos + yGo;
  x.writeMicroseconds(xPos);
  y.writeMicroseconds(yPos);
  delay(75);
}

void updatePosition() {
  x.writeMicroseconds(xPos);
  y.writeMicroseconds(yPos);
  delay(75);
}

