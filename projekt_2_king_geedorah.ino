#include <Adafruit_NeoPixel.h>
#include <Servo.h> // Include the Servo Library to control the servos

#define PIN 6
#define NUM_LEDS 24
Adafruit_NeoPixel pixels = Adafruit_NeoPixel(NUM_LEDS, PIN, NEO_GRB + NEO_KHZ800);
Servo Servo1;
Servo Servo2;

const int SOLENOID = 4;

//Servo variables
int pos = 0;       // variable to store the servo position
int pos2 = 90;     //servo2 start-position 
int Servo1Pin = 12; // Servo pin that will control X motion
int Servo2Pin = 13; // Servo pin that will control Y motion

//Button variables
int buttonPin = 7; //Buttonpin is attached to pin 7
int buttonPress = 0;
bool mode = true;


void setup() {
  pinMode(5, OUTPUT);
  pinMode(8, OUTPUT);
  pinMode(9, OUTPUT);
  pinMode(10, OUTPUT);
  pinMode(11, OUTPUT);
  pixels.setBrightness(50);  //Sets the brightness of the NEOPIXEL-ring to 50
  pixels.begin();
  Servo1.attach(Servo1Pin);  //
  Servo2.attach(Servo2Pin);
  Servo1.write(pos);
  Servo2.write(pos2);
  pinMode(SOLENOID, OUTPUT); //The solenoid pin is an input
  pinMode(buttonPin, INPUT); //The buttonpress pin is an input
  digitalWrite(buttonPin, LOW); //This enables the Arduino pullup for this pin
}

void loop() {

  buttonPress = digitalRead(buttonPin);//Read the sate of the button
  Serial.println(buttonPress);
  if (buttonPress == HIGH) // The button press is active low
  {
    for (int i = 0; i < NUM_LEDS; i++) {
      pixels.setPixelColor(i, pixels.Color(0, 0, 0)); // set the color of the i-th LED to green
      pixels.show(); // display the colors
      delay(250); // wait for a quarter second
      pixels.setPixelColor(i, pixels.Color(255, 0, 0)); // set the color of the i-th LED to red
      pixels.show(); // display the colors
    }

    for (int i = 0; i < NUM_LEDS; i++) {
      pixels.setPixelColor(i, pixels.Color(255, 0, 0));
      pixels.show();
      // Add the digitalWrite() statements for the LED pins here
      // This will turn the LED pins on at the same time the NeoPixel ring is updated
      digitalWrite(5, HIGH);
      digitalWrite(8, HIGH);
      digitalWrite(9, HIGH);
      digitalWrite(10, HIGH);
      digitalWrite(11, HIGH);
      delay(70);
      digitalWrite(5, LOW);
      digitalWrite(8, LOW);
      digitalWrite(9, LOW);
      digitalWrite(10, LOW);
      digitalWrite(11, LOW);
    }

    // Turn off all the pixels
    for (int i = 0; i < NUM_LEDS; i++) {
      pixels.setPixelColor(i, pixels.Color(0, 0, 0));
      pixels.show();

      // Add the digitalWrite() statements for the LED pins here
      // This will turn the LED pins off at the same time the NeoPixel ring is updated
      digitalWrite(5, LOW);
      digitalWrite(8, LOW);
      digitalWrite(9, LOW);
      digitalWrite(10, LOW);
      digitalWrite(11, LOW);

      delay(50);
    }


    // Blink the ring in red
    for (int j = 0; j < 7; j++) {
      for (int i = 0; i < NUM_LEDS; i++) {
        pixels.setPixelColor(i, pixels.Color(255, 0, 0));
      }

      // Add the digitalWrite() statements for the LED pins here
      // This will turn the LED pins on at the same time the NeoPixel ring is updated
      digitalWrite(5, HIGH);
      digitalWrite(8, HIGH);
      digitalWrite(9, HIGH);
      digitalWrite(10, HIGH);
      digitalWrite(11, HIGH);

      pixels.show();
      delay(400);
      for (int i = 0; i < NUM_LEDS; i++) {
        pixels.setPixelColor(i, pixels.Color(0, 0, 0));
      }

      // Add the digitalWrite() statements for the LED pins here
      // This will turn the LED pins off at the same time the NeoPixel ring is updated
      digitalWrite(5, LOW);
      digitalWrite(8, LOW);
      digitalWrite(9, LOW);
      digitalWrite(10, LOW);
      digitalWrite(11, LOW);

      pixels.show();
      delay(200);
    }
    digitalWrite(5, HIGH); // turn the LEDS on
    digitalWrite(8, HIGH);
    digitalWrite(9, HIGH);
    digitalWrite(10, HIGH);
    digitalWrite(11, HIGH);
    // Fire effect
    for (int j = 0; j < 20; j++) {
     for (int i = 0; i < NUM_LEDS; i++) {
        int r = random(80, 255);  //r gets a random value from 80 to 225
        int g = random(0, 10);    //g gets a random value from 0 to 10
        int b = 0;               
        pixels.setPixelColor(i, pixels.Color(r, g, b)); //
      }
      pixels.show();
      delay(300);
    }
    digitalWrite(5, LOW); // turn the LED off by making the voltage LOW
    digitalWrite(8, LOW);
    digitalWrite(9, LOW);
    digitalWrite(10, LOW);
    digitalWrite(11, LOW);
    delay(400);
    // Set all the pixels to red and delay for 400ms 
    for (int i = 0; i < NUM_LEDS; i++) {
      pixels.setPixelColor(i, pixels.Color(255, 0, 0));
    }
    pixels.show();
    delay (100);
    upanddown();
    shot();
    delay(15);
    servomove();
    dragonshot();
    servomoveback();
    servomoveforward();
    shot();
    
  }
  if (buttonPress == LOW) // The button press is active low
  {
    for (int i = 0; i < NUM_LEDS; i++) {
      pixels.setPixelColor(i, pixels.Color(0, 0, 0)); //The NUMPIXEL-ring stays turned off
      pixels.show();
      delay(20);
    }
    digitalWrite(8,HIGH);
  }
}


//Function where the LEDPINS light up one by one from left to right
void dragonshot() {
  digitalWrite(11, HIGH);
  delay(500);
  digitalWrite(11, LOW);
  digitalWrite(10, HIGH);
  delay(500);
  digitalWrite(10, LOW);
  digitalWrite(9, HIGH);
  delay(500);
  digitalWrite(9, LOW);
  digitalWrite(8, HIGH);
  delay(500);
  digitalWrite(8, LOW);
  digitalWrite(5, HIGH);
  delay(500);
  digitalWrite(5, LOW);
  delay(300);
  digitalWrite(11, HIGH);
  delay(300);
  digitalWrite(11, LOW);
  digitalWrite(10, HIGH);
  delay(300);
  digitalWrite(10, LOW);
  digitalWrite(9, HIGH);
  delay(300);
  digitalWrite(9, LOW);
  digitalWrite(8, HIGH);
  delay(300);
  digitalWrite(8, LOW);
  digitalWrite(5, HIGH);
  delay(300);
  digitalWrite(5, LOW);
  delay(300);
  digitalWrite(11, HIGH);
  delay(100);
  digitalWrite(11, LOW);
  digitalWrite(10, HIGH);
  delay(100);
  digitalWrite(10, LOW);
  digitalWrite(9, HIGH);
  delay(100);
  digitalWrite(9, LOW);
  digitalWrite(8, HIGH);
  delay(100);
  digitalWrite(8, LOW);
  digitalWrite(5, HIGH);
  delay(100);
  digitalWrite(5, LOW);
  delay(100);
}

//Function where the LEDPINS light up one by one from right to left
void shot(){
  digitalWrite(5, HIGH);
  delay(500);
  digitalWrite(5, LOW);
  digitalWrite(8, HIGH);
  delay(500);
  digitalWrite(8, LOW);
  digitalWrite(9, HIGH);
  delay(500);
  digitalWrite(9, LOW);
  digitalWrite(10, HIGH);
  delay(500);
  digitalWrite(10, LOW);
  digitalWrite(11, HIGH);
  delay(500);
  digitalWrite(11, LOW);
  delay(300);
  digitalWrite(5, HIGH);
  delay(300);
  digitalWrite(5, LOW);
  digitalWrite(8, HIGH);
  delay(300);
  digitalWrite(8, LOW);
  digitalWrite(9, HIGH);
  delay(300);
  digitalWrite(9, LOW);
  digitalWrite(10, HIGH);
  delay(300);
  digitalWrite(10, LOW);
  digitalWrite(11, HIGH);
  delay(300);
  digitalWrite(11, LOW);
  delay(300);
  digitalWrite(5, HIGH);
  delay(100);
  digitalWrite(5, LOW);
  digitalWrite(8, HIGH);
  delay(100);
  digitalWrite(8, LOW);
  digitalWrite(9, HIGH);
  delay(100);
  digitalWrite(9, LOW);
  digitalWrite(10, HIGH);
  delay(100);
  digitalWrite(10, LOW);
  digitalWrite(11, HIGH);
  delay(100);
  digitalWrite(11, LOW);
  delay(100);
}

//Function that makes the SOLENOID go up and down
void upanddown() {
  digitalWrite(4, HIGH);
  delay(1000);
  digitalWrite(4, LOW);
  delay(500);
  digitalWrite(4, HIGH);
  delay(1000);
  digitalWrite(4, LOW);
}

void servomove() {
  for (pos = 0; pos <= 180; pos += 1) { // goes from 0 degrees to 180 degrees
    // in steps of 1 degree
    Servo1.write(pos);
    Servo2.write(pos);// tell servo to go to position in variable 'pos'
    delay(5);                       // waits 5 ms for the servo to reach the position
  }
  for (pos = 180; pos >= 0; pos -= 1) { // goes from 180 degrees to 0 degrees
    Servo1.write(pos);
    Servo2.write(pos); // tell servo to go to position in variable 'pos'
    delay(5);                       // waits 5 ms for the servo to reach the position
  }
}

//Function that adjustes the SERVOs position
void servomoveback(){
  Servo2.write(0); //move servo1 to 0 degrees
  Servo1.write(90); //move servo2 to 90 degrees

  Servo2.write(90); //move servo1 to 90 degrees
  Servo1.write(180); //move servo2 to 180 degrees
  delay(3); //wait for 3 ms
}

//Function that adjustes the SERVOs position
void servomoveforward(){
  Servo1.write(0); //move servo1 to 0 degrees
  Servo2.write(90); //move servo2 to 90 degrees
  delay(3); //wait for 3 ms

  Servo1.write(90); //move servo1 to 90 degrees
  Servo2.write(180); //move servo2 to 180 degrees
  delay(3); //wait for 3 ms
}
