
#include <Process.h>

void setup() {
  Serial.begin(9600);  // initialize serial communication
  while (!Serial);     // do nothing until the serial monitor is opened

  Serial.println("Starting bridge...\n");

  Bridge.begin();  // make contact with the linux processor
 
  delay(2000);  // wait 2 seconds
}

void loop() {
  Process getAllEvents;  // initialize a new process

  getAllEvents.runShellCommand("python /mnt/sda1/tembootest.py");  // command you want to run

  // while there's any characters coming back from the
  // process, print them to the serial monitor:
  while (getAllEvents.available() > 0) {
    char c = getAllEvents.read();
    Serial.print(c);
  }

  Serial.println();

  delay(10000);
}

