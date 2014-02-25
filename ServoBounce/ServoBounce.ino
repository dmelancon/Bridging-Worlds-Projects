#include <Servo.h> 

float x = 10;
float vel = .1;
float accel = 0;
float grav= .03;
Servo servoMotor;       // creates an instance of the servo object to control a servo
int servoPin = 2;
float fric ;
void setup() {
Serial.begin(9600);
  servoMotor.attach(servoPin);

}
// the loop routine runs over and over again forever:
void loop() {
  fric= vel*-1*.001;
 accel= accel + grav+fric;
 vel=vel+accel;
 x=x+vel;
 
 accel = 0;

 if (x>120){
    x= 119;
     vel*= -1;
    
    }
 int  mapp= map(x,0, 120, 0, 120);
 servoMotor.write(mapp);
 
Serial.println(mapp);
delay(5);
 
}
