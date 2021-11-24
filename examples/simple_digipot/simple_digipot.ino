// Please format this file with clang before check-in to GitHub
/*
  File: simple_digipot.ino 

  Purpose:  Illustrate invoking this class.
            This is non-functional.
*/

#include <Digipot_MCP42xxx.h>

// ---------- Hardware Wiring ----------
// Same as Griduino platform

// here's the volume control being demonstrated
// Digipot_MCP42xxx thePot(cs);
#define cs_pin 8

void setup() {
  setBothVolume(cs_pin, 0);      // minimum volume
  setLeftVolume(cs_pin, 128);    // midpoint volume
  setRightVolume(cs_pin, 255);   // maximum volume
  setPotWiper(cs_pin, pot0, 66);
  setPotWiper(cs_pin, pot1, 77);
}

int main() {
}