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
**   File       : pcf8591.h
**   Author     : Sriharsha
**   Website    : www.zuna.in
**   Email      : helpzuna@gmail.com
**   Description: This is the PCF8591 ADC/DAC driver include file for Arduino
***/

#ifndef PCF8591_H
#define PCF8591_H

#define PCF8591_SLAVE_ADDRESS 0x92 >> 1 

#define PCF8591_AUTO_INC_BYTE 0x04
#define PCF8591_DAC_REGISTER  0x00


class pcf8591
{
private:
unsigned char pcf8591_slave_address;
public:
void          begin();
void          begin(unsigned char);
unsigned char analogRead(unsigned char);
void          analogWrite(unsigned char);
};

#endif 

