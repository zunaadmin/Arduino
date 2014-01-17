
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
    along with Foobar.  If not, see <http://www.gnu.org/licenses/>.
/**************************************************************************************************************/


/**************************************************************************************************************
   File   : softRtc.cpp
   Author : Sriharsha
   Email  : helpzuna@gmail.com
/**************************************************************************************************************/


#include "softRtc.h"

/* Method      : setTime
   Parameters  : unsigned chat,unsigned char,unsigned char (seconds,minutes,hour in 24 Hr Format)
   Return      : None
   Description : It will give a delay in milliseconds
 */
void SoftRTC :: setTime(unsigned char ss,unsigned char mm,unsigned char hh)
{
this->SS = ss;
this->MM = mm;
this->HH = hh;
}

/* Method      : calcTime
   Parameters  : None
   Return      : None
   Description : It will give a delay in milliseconds
 */
void SoftRTC::calcTime(void)
{
this->SS++;
if(this->SS == 60)
{
this->SS = 0;
this->MM++;
if(this->MM == 60)
{
this->MM = 0;
this->HH++;
if(this->HH == 24)
{
this->HH = 0;
}
}
}
TIMER_COUNTER_REGISTER = TIMER_RELOAD_VALUE;
}

void SoftRTC:: begin(void)
{
TIMER_CONTROL_A = TIMER_CONTROL_A_VAL;
TIMER_CONTROL_B |= TIMER_CONTROL_B_VAL;
TIMER_COUNTER_REGISTER = TIMER_RELOAD_VALUE;
}

void SoftRTC :: clearTimer(void)
{
this->SS = 0;
this->MM = 0;
this->HH = 0;
tickStatus = false;
}

void SoftRTC :: clearFlag(void)
{
tickStatus = false;
}

bool SoftRTC :: checkFlag(void)
{
return tickStatus;
}

void SoftRTC :: startTimer(void)
{
TIMER_MASK_REGISTER |= TIMER_MASK_SET;
//sei();
}

void SoftRTC :: stopTimer(void)
{
TIMER_MASK_REGISTER &= TIMER_MASK_CLR;
//cli();
}

char* SoftRTC :: getTime(unsigned char _mode)
{
char *buffer;
if(_mode == 0)
{
sprintf(buffer,"%d:%d:%d",HH,MM,SS);
}
else if(_mode == 1)
{
if(HH < 12)
sprintf(buffer,"%d:%d:%d:AM",HH,MM,SS);
else
sprintf(buffer,"%d:%d:%d:PM",(HH-12),MM,SS);
}
return buffer;
}



