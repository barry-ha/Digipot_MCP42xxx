// Please format this file with clang before check-in to GitHub
/*
  File:     MCP42xxx.h

  Purpose:  Arduino library using SPI to control the Microchip MCP42xxx dual digital potentiometer.

  License:  GNU General Public License v3.0

            Permissions of this strong copyleft license are conditioned on making 
            available complete source code of licensed works and modifications, 
            which include larger works using a licensed work, under the same license. 
            Copyright and license notices must be preserved. Contributors provide 
            an express grant of patent rights.
*/
#pragma once
#include <Arduino.h>
#include <SPI.h>

#define pot0            0x11
#define pot1            0x12
#define potBoth         0x13
#define pot0Shutdown    0x21
#define pot1Shutdown    0x22
#define potBothShutdown 0x23

class Digipot_MCP42xxx {
public:
  Digipot_MCP42xxx(unsigned char chip_select_pin) : cs(chip_select_pin) {}
  unsigned char cs;   // chip select

  void begin();   // init SPI, init chip select pin

  void setLeftVolume(unsigned char pos);
  void setRightVolume(unsigned char pos);
  void setBothVolume(unsigned char pos);
  void setPotWiper(unsigned char address, unsigned char pos);
};
