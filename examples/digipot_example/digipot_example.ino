// Please format this file with clang before check-in to GitHub
/*
  File: digipot_example.ino 

  Purpose:  Working example to set various levels in the digipot while 
            blinking the onboard LED to visually indicate a new setting.
            Run this to verify the digipot settings with an ohmmeter.

*/
#include <Arduino.h>
#include <SPI.h>
#include <Digipot_MCP42xxx.h>
#include <Adafruit_DotStar.h>

#define NUMPIXELS 1
#define DATAPIN   8
#define CLOCKPIN  6
Adafruit_DotStar strip(NUMPIXELS, DATAPIN, CLOCKPIN, DOTSTAR_BRG);

// here's the volume control being demonstrated
#define cs_pin 2
Digipot_MCP42xxx digipot(cs_pin);

void setup() {
  // turn off the dotStar (it's too bright)
  strip.begin();   // Initialize pins for output
  strip.setBrightness(0);
  strip.show();   // Turn all LEDs off ASAP

  // initialize the onboard LED so we can flash it
  pinMode(LED_BUILTIN, OUTPUT);

  // initialize the SPI bus, and chip select pin
  digipot.begin();
}

// the loop function runs over and over again forever
void loop() {
  digipot.setBothVolume(0);   // minimum resistance
  digitalWrite(LED_BUILTIN, HIGH);
  delay(100);
  digitalWrite(LED_BUILTIN, LOW);
  delay(900);

  digipot.setBothVolume(255);   // maximum resistance
  digitalWrite(LED_BUILTIN, HIGH);
  delay(100);
  digitalWrite(LED_BUILTIN, LOW);
  delay(900);
}