// Please format this file with clang before check-in to GitHub
/*
  File: simple_digipot.ino 

  Purpose:  Illustrate invoking the class and confirm it compiles successfully.
            This is not intended to be functional or useful.

*/

#include <Digipot_MCP42xxx.h>   // https://github.com/barry-ha/Digipot_MCP42xxx

// here's the volume control being demonstrated
#define cs_pin 8
Digipot_MCP42xxx digipot(cs_pin);

void setup() {
  digipot.begin();   // init SPI, init chip select pin

  digipot.setBothVolume(0);      // minimum volume
  digipot.setLeftVolume(128);    // midpoint volume
  digipot.setRightVolume(255);   // maximum volume

  digipot.setPotWiper(pot0, 66);
  digipot.setPotWiper(pot1, 77);
}

void loop() {
}