#include <Servo.h>

Servo myservo;  // create servo object to control a servo
//Serial.begin(9600);

void setup() {
 myservo.attach(9);  // attaches the servo on pin 9 to the servo object
Serial.begin(9600);

}

void loop() {
  Serial.println("step1");
  //for (pos = 0; pos <= 180; pos += 1) { // goes from 0 degrees to 180 degrees
    myservo.write(0);              // tell servo to go to position in variable 'pos'
    //delay(10000); // waits 15ms for the servo to reach the position
  //myservo.attach(9);
  myservo.write(180);
  delay(16200);
  Serial.println("step2");
  myservo.write(90);
  delay(2000);
  myservo.detach();
  delay(10000);
  }


