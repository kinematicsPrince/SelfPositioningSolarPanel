#include <Servo.h>
#include "SevSeg.h"
SevSeg sevseg;

Servo topservo;    // 90 is vertical, 0 is flat
Servo bottomservo;

// Struct to hold both angle and intensity
struct LightReading {
  int bottomangle;
  int topangle;
  int intensity;
};

int bestTopAngle = 0;
int bestBottomAngle = 0;
int InitialIntensity = 0;
int intialTopAngle = 0;
int initialBottomAngle = 0;

int threshold = 20; // How different does the voltage input (range: 0 to 1023) needs to be for the scanning to be required

int photoPin = A5;

void setup() {

  // For Segment diplay
  byte numDigits = 1;
  byte digitPins[] = {};
  byte segmentPins[] = {6, 5, 2, 3, 4, 7, 8, 9};
  bool resistorsOnSegments = true;

  byte hardwareConfig = COMMON_CATHODE; 
  sevseg.begin(hardwareConfig, numDigits, digitPins, segmentPins, resistorsOnSegments);
  sevseg.setBrightness(90);


  Serial.begin(9600);
  bottomservo.attach(12);
  bottomservo.write(0);
  delay(1000);
  topservo.attach(11);
  topservo.write(90);
  delay(1000);
  
  LightReading reading = surroundcheck();
  bottomservo.write(reading.bottomangle);
  topservo.write(reading.topangle);

  delay(2000);
  InitialIntensity = photoresistor();
}

void loop() {
  float displayNumber = 0;
  int SecondIntensity = photoresistor();

  if (abs(InitialIntensity - SecondIntensity) > threshold) {
    LightReading reading = surroundcheck();
    bottomservo.write(reading.bottomangle);
    topservo.write(reading.topangle);
    InitialIntensity = reading.intensity;
    delay(1500);
  }


}

// Read from the photoresistor
int photoresistor() {
  int displayNumber = 0;
  int Average = 0;
  long total = 0;
  for (int i = 0; i < 5; i++) {
    total += analogRead(photoPin);
    delay(5);
  }
  Average = total / 5;
    // segment display
  displayNumber = Average / (102.4);
  displayNumber = (int)displayNumber;
  sevseg.setNumber(displayNumber);
  delay(5);
  sevseg.refreshDisplay();
  Serial.println(Average);
  return Average;
}

// Scan 0–180 degrees and find the brightest direction
LightReading surroundcheck() {

  int BottomBestAngle = 0;
  int TopBestAngle = 0;

  int scanAngle = 55; // Angle at which the scanning is done

  int initialBottomAngle = bottomservo.read();
  int intialTopAngle = topservo.read();
  

  for (int i = initialBottomAngle; i >= 0; i -= 1){ // Position the bottomservo at 0
    bottomservo.write(i);
    delay(15);
  }

  if (intialTopAngle >= scanAngle){ // if initial topangle is higher than the scanAngle (more vertical than the scanAngle), reduce the angle until scanAngle
    for (int i = intialTopAngle; i >= scanAngle; i -= 1){
      topservo.write(i);
      delay(15);
    }
  }

  else if (intialTopAngle <= scanAngle){ // if initial topangle is lower than scanAngle (more horizontal than scanAngle), reduce the angle until scanAngle
    for (int i = intialTopAngle; i <= scanAngle; i += 1){
      topservo.write(i);
      delay(15);
    }
  }

  int intensityA = 0;
  int intensityB = 0;
  int maxIntensity = 0;

  for (int i = 0; i <= 180; i += 1) { // Scan using bottomservo and return the position with the highest intensity of light
    bottomservo.write(i);
    delay(15);

    intensityA = intensityB;
    intensityB = photoresistor();

    if (intensityB > maxIntensity) {
      maxIntensity = intensityB;
      BottomBestAngle = i; // Best angle for bottomservo
    }
  }

  for (int i = 180; i >= BottomBestAngle; i -= 1){ // Positions the bottomservo at to BottomBestAngle smoothly
    bottomservo.write(i);
    delay(15);
  }


  for (int i = scanAngle; i >= 0; i -= 1){ // Positions the topservo to 0 smoothly
    topservo.write(i);
    delay(15);
  }

  intensityA = 0;
  intensityB = 0;
  maxIntensity = 0;

  for (int i = 0; i <= 90; i += 1) {
    topservo.write(i);
    delay(15);

    intensityA = intensityB;
    intensityB = photoresistor();

    if (intensityB > maxIntensity) {
      maxIntensity = intensityB;
      TopBestAngle = i;
    }
  }

  for (int i = 90; i >= TopBestAngle; i -= 1){ // Positions the topservo to TopBestAngle smoothly
    topservo.write(i);
    delay(15);
  }

  LightReading result = { BottomBestAngle, TopBestAngle, maxIntensity };
  return result;
}