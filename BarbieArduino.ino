
#include <Servo.h>
#include <Adafruit_NeoPixel.h>

#define PIN 4
#define LED_COUNT 250
#define LAWNGREEN    0x7CFC00
#define BARBIEPINK    0xFF1493
#define BLUE      0x0000FF
#define ELVTRPIN 9 // Pin on Arduino board to connecting servo for the elevator
#define ELVTRPOWER 10
#define READ_RATE 100 // How often the serial link is read, in milliseconds
#define FLASH_RATE 100 // The on/off period in milliseconds, for the LED Flash status feedback

byte cmd = 0; // Stores the next byte of incoming data, which is a "command" to do something
byte param; // Stores the 2nd byte, which is the command parameter
Servo myservo;
boolean turnOff = false;
Adafruit_NeoPixel leds = Adafruit_NeoPixel(LED_COUNT, PIN, NEO_GRB + NEO_KHZ800);

void setup()
{
  leds.begin();  // Call this to start up the LED strip.
  clearLEDs();   // This function, defined below, turns all LEDs off...
  leds.show();   // ...but the LEDs don't actually update until you call this.  
  myservo.attach(ELVTRPIN);
  pinMode(ELVTRPOWER, OUTPUT);
  pinMode(PIN, OUTPUT); // pin 48 (on-board LED) as OUTPUT
  digitalWrite(PIN, LOW);
  Serial.begin(9600); // start serial communication at 9600bps
}
void clearLEDs()
{
  for (int i=0; i<LED_COUNT; i++)
  {
    leds.setPixelColor(i, 0);
  }
}

void loop() {
  if ( Serial.available() ) // if data is available to read
{
cmd = Serial.read(); // read it and store it in 'cmd'
// Data format is byte 1 = command, byte 2 = parameter
};


switch ( cmd ) {
case 1:
// First byte contains a generic "command" byte. We arbitrarily defined '1' as the command to then check the 2nd parameter byte
// User can additional commands by adding case 2, 3, 4, etc
{
// read the parameter byte
param = Serial.read();
switch (param)
{
case 1:
// Android device requests the Arduino to send some data back to Android
//flashLED(1);
if (Serial)
{
// Send back 2 bytes with a value of 1, 2
Serial.write(1);
Serial.write(2);
};
break;

case 2:
// Turn on status LED
//flashLED(2);
//digitalWrite(LEDPIN, HIGH );
break;

case 3:
// Turn off status LED
//flashLED(3);
//digitalWrite(LEDPIN, LOW);
break;

case 4:
// Light On
hitTheLights(0xFFDAB9, 0); 
break;

case 5:
//Light off
clearLEDs();
leds.show();
break;

case 6:
//Elevator Up
digitalWrite(ELVTRPOWER, HIGH);
myservo.write(0);   
myservo.write(180);
delay(12300);
myservo.write(90);
delay(2000);
myservo.detach();
delay(10000);
digitalWrite(ELVTRPOWER, LOW);
cmd = 1;
break;

case 7:
//Elevator Down
//spin(myservo, -360);
cmd = 1;
break;

case 8:
// Lights to pink
hitTheLights(BARBIEPINK, 0);
cmd = 1;
break;

case 9:
// Lights to green
hitTheLights(LAWNGREEN, 0);
cmd = 1;
break;

case 10:
// Lights to blue
hitTheLights(BLUE, 0);
cmd = 1;
break;

case 11:
// Lights delay = 0
hitTheLights(0xFFDAB9, 0);
cmd = 1;
break;

case 12:
// Lights delay = 0.5
hitTheLights(0xFFDAB9, 0.5);
cmd = 1;
break;

case 13:
// Lights delay = 1
hitTheLights(0xFFDAB9, 1);
cmd = 1;
break;

default: break; // do nothing
} // switch (param)
} // switch (cmd) case 1
default: break; // do nothing
} // switch (cmd)

delay(READ_RATE); // wait 100ms for next reading
}

//Spin Servo
void spin(Servo s, int n){
  s.write(n);
  delay(10000);
}


void hitTheLights(unsigned long color, byte wait){
  for(int i=40; i<200; i++)
  {
    leds.setPixelColor(i,color);
    delay(wait);
    leds.show();
  }
}

