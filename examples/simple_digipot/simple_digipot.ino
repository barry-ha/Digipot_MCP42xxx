// Please format this file with clang before check-in to GitHub
/*
  File: simple_digipot.ino 

  Purpose:  Illustrate invoking this class.
            This is not intended to be functionally useful.
*/

#include <Digipot_MCP42xxx.h>

// here's the volume control being demonstrated
#define cs_pin 8
Digipot_MCP42xxx thePot(cs_pin);

void setup() {
  thePot.setBothVolume(0);      // minimum volume
  thePot.setLeftVolume(128);    // midpoint volume
  thePot.setRightVolume(255);   // maximum volume
  thePot.setPotWiper(pot0, 66);
  thePot.setPotWiper(pot1, 77);
}

int main() {
}