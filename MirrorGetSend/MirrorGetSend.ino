#include <Servo.h>      // include the servo library
#include <Bridge.h>
#include <HttpClient.h>
int x = 0;
int y = 1;
int index = 0;
int readings[721];
int highread= 0;
int highX; 
int voltage;
Servo servoMotor;       // creates an instance of the servo object to control a servo
int servoPin = 2;
int servoAngle;
// the setup routine runs once when you press reset:
void setup() {
    Bridge.begin();
  // initialize serial communication at 9600 bits per second:
  Serial.begin(9600); 
  servoMotor.attach(servoPin);
   while (!Serial);
  

 
  
  // read the input on analog pin 0:

  // Convert the analog reading (which goes from 0 - 1023) to a voltage (0 - 5V):
  // print out the value you read:
  
//  servoAngle = map(voltage,0,1023,0,179);
for (int j= 0; j<=360;j++){
  voltage = analogRead(A0);
if (index<720){
   x= x+y;
   if (x>119){
     x= 120;
     y*=-1;
      }
   if (x<0){
    x= 1;
    y*= -1;
   
   }
   
   readings[index]= voltage;
   readings[index+1]= x;
   index+=2;
   servoMotor.write(x);
  Serial.println(x);
  Serial.println(voltage);
}
  delay(25);
}
  
 if (index==720){
   for(int i =0; i<index; i+=2){
     if (readings[i]>highread){
     highread = readings[i];
     highX = readings[i+1];
     }}
 Serial.println(highread);  
 servoMotor.write(highX);
 }
  
//       HttpClient client;
//   String site = "http://mirrorsdata.appspot.com/write?devicename=photoresister&sensormin=0&sensormax=1024&sensorreading=";
//   String address = site + highread;
//   client.get(address);
//   String site2= "http://mirrorsdata.appspot.com/write?devicename=lightangle&sensormin=0&sensormax=120&sensorreading=";
//   String address2 = site2+highX;
//   client.get(address2);
//    while (client.available()) {
//    char c = client.read();
//    Serial.print(c);
  
//}
Serial.flush();

 

 

}
// the loop routine runs over and over again forever:
void loop() {


  
}

  
