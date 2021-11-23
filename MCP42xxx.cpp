// MCP42xxx Digital Potentiometer Functions
#include "MCP42xxx.h"

void setLEFTvolume(unsigned char CHIP_SELECT, unsigned char pos)
{
       pos = constrain(pos, 0, 255);      // limit wiper setting to range o 0 to 255
       setPotWiper (CHIP_SELECT, pot0, pos);

}

void setRIGHTvolume(unsigned char CHIP_SELECT, unsigned char pos)
{
       pos = constrain(pos, 0, 255);      // limit wiper setting to range o 0 to 255
       setPotWiper (CHIP_SELECT, pot1, pos);
}

void setBOTHvolume(unsigned char CHIP_SELECT, unsigned char pos)
{
       pos = constrain(pos, 0, 255);      // limit wiper setting to range o 0 to 255
       setPotWiper (CHIP_SELECT, potBoth, pos);
}

void setPotWiper (unsigned char CHIP_SELECT, unsigned char address, unsigned char pos)
{
    pos = constrain(pos, 0, 255);      // limit wiper setting to range o 0 to 255
    
    digitalWrite(CHIP_SELECT, LOW);          // select chip

    // SPISettings mySettting(speedMaximum, dataOrder, dataMode)
    // dataOrder: MSBFIRST or LSBFIRST
    // dataMode : SPI_MODE0, SPI_MODE1, SPI_MODE2, or SPI_MODE3
    SPI.beginTransaction(SPISettings(1400000, MSBFIRST, SPI_MODE2));

    SPI.transfer(address);                // configure target pot with wiper position
    SPI.transfer(pos);
    
    digitalWrite(CHIP_SELECT, HIGH);         // deselect chip
    
    SPI.endTransaction();
}