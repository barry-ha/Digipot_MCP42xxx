// Library for MCP42xxx digital potentiometer

#include <SPI.h>

#define pot0 0x11
#define pot1 0x12
#define potBoth 0x13
#define pot0Shutdown 0x21
#define pot1Shutdown0x22
#define potBothShutdown 0x23

void setPotWiper(unsigned char, unsigned char, unsigned char);
void setLEFTvolume(unsigned char, unsigned char);
void setRIGHTvolume(unsigned char, unsigned char);
void setBOTHvolume(unsigned char,  unsigned char);