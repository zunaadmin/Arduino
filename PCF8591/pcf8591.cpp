/***************************************************************************************************************
    This file is part of Library for Arduino.

    Library for Arduino is free software: you can redistribute it and/or modify
    it under the terms of the GNU General Public License as published by
    the Free Software Foundation, either version 3 of the License, or
    (at your option) any later version.

    Library for Arduino is distributed in the hope that it will be useful,
    but WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
    GNU General Public License for more details.

    You should have received a copy of the GNU General Public License
    along with Library for Arduino.  If not, see <http://www.gnu.org/licenses/>.
/**************************************************************************************************************/

/***
**   File       : pcf8591.cpp
**   Author     : Sriharsha
**   Website    : www.zuna.in
**   Email      : helpzuna@gmail.com
**   Description: This is the PCF8591 ADC/DAC driver for Arduino
***/

#include <Wire.h>
#include <avr/pgmspace.h>
#include <WProgram.h>
#include "pcf8591.h"
#include <Arduino.h>

/*** Method      : begin
**   Parameters  : None
**   Return      : None
**   Description : It will initiate the PCF8591 with default address defined in pcf8591.h
**/
void pcf8591::begin(void)
{
pcf8591_slave_address = PCF8591_SLAVE_ADDRESS;
Wire.begin(pcf8591_slave_address);
}

/*** Method      : begin
**   Parameters  : unsigned char (Slave Address of PCF8591)
**   Return      : None
**   Description : It will initiate the PCF8591 with address passed by method caller
**/
void pcf8591::begin(unsigned char __address)
{
pcf8591_slave_address = __address;
Wire.begin(pcf8591_slave_address);
}

/*** Method      : analogRead
**   Parameters  : unsigned char (Analog Channel (0,1,2,3))
**   Return      : unsigned char (8-bit analogRead value)
**   Description : It will read the ADC pins
**/
unsigned char pcf8591::analogRead(unsigned char ch)
{
unsigned char buff[6]
 Wire.beginTransmission(pcf8591_slave_address); 
 Wire.write(PCF8591_AUTO_INC_BYTE);
 Wire.endTransmission(); 
 Wire.requestFrom(pcf8591_slave_address, 5);
 buff[0]=Wire.read();
 buff[0]=Wire.read();
 buff[1]=Wire.read();
 buff[2]=Wire.read();
 buff[3]=Wire.read();
 return buff[ch]);
}

/*** Method      : analogWrite
**   Parameters  : unsigned char (8-bit value that will pass to DAC)
**   Return      : None
**   Description : It will write the value into DAC
**/
void pcf8591::analogWrite(unsigned char DacVal)
{
 Wire.beginTransmission(pcf8591_slave_address); 
 Wire.write(PCF8591_DAC_REGISTER);
 Wire.write(DacVal);
 Wire.endTransmission(); 
}





