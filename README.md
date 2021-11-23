# Digipot_MCP42xxx
Arduino library using SPI to control the dual digital potentiometer by Microchip, MCP42xxx.

The MCP4<b>1</b>xxx units have a single built-in potentiometer and the MCP4<b>2</b>xxx units have two independent potentiometers.

Both series will operate on either 3.3V or 5V, as the digipots do not send any data back to the controller. In fact, this digipot cannot be read via SPI; its signal-out pin (SO) is not a tri-state output and so it cannot share a SPI bus. The MCP42xxx does not have any Read commands in its repertoire.

# Background
Our project began with digipot DS1804 to control a single channel of audio volume level. Later, we needed two audio channels and replaced the DS1804 with the MCP42xxx.

This library was developed for the Griduino project, a device for a vehicle's dashboard. One of its features is to announces its location by speaking letters and numbers using the NATO Military Phonetic Alphabet.

* Griduino runs on the Feather M4 Express, https://www.adafruit.com/product/3857
* Griduino software is an open-source project, https://github.com/barry-ha/Griduino
* Griduino devices are available, https://www.griduino.com
