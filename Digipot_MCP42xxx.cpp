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

#include <math.h>
#include <Digipot_MCP42xxx.h>

void Digipot_MCP42xxx::setLeftVolume(unsigned char pos) {
  pos = constrain(pos, 0, 255);   // limit wiper setting to 0..255
  setPotWiper(pot0, pos);
}

void Digipot_MCP42xxx::setRightVolume(unsigned char pos) {
  pos = constrain(pos, 0, 255);   // limit wiper setting to 0..255
  setPotWiper(pot1, pos);
}

void Digipot_MCP42xxx::setBothVolume(unsigned char pos) {
  pos = constrain(pos, 0, 255);   // limit wiper setting to 0..255
  setPotWiper(potBoth, pos);
}

void Digipot_MCP42xxx::setPotWiper(unsigned char address, unsigned char pos) {
  pos = constrain(pos, 0, 255);   // limit wiper setting to 0...255

  digitalWrite(cs, LOW);   // select chip

  // SPISettings mySettting(speedMaximum, dataOrder, dataMode)
  // dataOrder: MSBFIRST or LSBFIRST
  // dataMode : SPI_MODE0, SPI_MODE1, SPI_MODE2, or SPI_MODE3
  SPI.beginTransaction(SPISettings(1400000, MSBFIRST, SPI_MODE2));

  SPI.transfer(address);   // configure target pot with wiper position
  SPI.transfer(pos);

  digitalWrite(cs, HIGH);   // deselect chip

  SPI.endTransaction();
}
